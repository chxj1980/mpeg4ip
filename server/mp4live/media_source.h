/*
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 * 
 * The Original Code is MPEG4IP.
 * 
 * The Initial Developer of the Original Code is Cisco Systems Inc.
 * Portions created by Cisco Systems Inc. are
 * Copyright (C) Cisco Systems Inc. 2000-2002.  All Rights Reserved.
 * 
 * Contributor(s): 
 *		Dave Mackie		dmackie@cisco.com
 *		Bill May 		wmay@cisco.com
 */

#ifndef __MEDIA_SOURCE_H__
#define __MEDIA_SOURCE_H__

#include "media_node.h"
#include "media_sink.h"

#include "video_util_resize.h"

// forward declarations
class CAudioEncoder;
class CVideoEncoder;

// virtual parent class for audio and/or video sources
// contains all the common media processing code

class CMediaSource : public CMediaNode {
public:
	CMediaSource();

	~CMediaSource();
	
	bool AddSink(CMediaSink* pSink);

	void RemoveSink(CMediaSink* pSink);

	void RemoveAllSinks(void);

	void StartVideo(void) {
		m_myMsgQueue.send_message(MSG_SOURCE_START_VIDEO,
			NULL, 0, m_myMsgQueueSemaphore);
	}

	void StartAudio(void) {
		m_myMsgQueue.send_message(MSG_SOURCE_START_AUDIO,
			NULL, 0, m_myMsgQueueSemaphore);
	}

	void GenerateKeyFrame(void) {
		m_myMsgQueue.send_message(MSG_SOURCE_KEY_FRAME,
			NULL, 0, m_myMsgQueueSemaphore);
	}

	virtual bool IsDone() = NULL;

	virtual Duration GetElapsedDuration();

	virtual float GetProgress() = NULL;

	virtual u_int32_t GetNumEncodedVideoFrames() {
		return m_videoDstFrameNumber;
	}

	virtual u_int32_t GetNumEncodedAudioFrames() {
		return m_audioDstFrameNumber;
	}

protected:
	// Video & Audio support
	virtual void ProcessMedia();
	virtual void ProcessVideo() {
	};
	virtual void ProcessAudio() {
	};
	virtual bool IsEndOfVideo() { 
		return true;
	}
	virtual bool IsEndOfAudio() {
		return true;
	}

	void PaceSource();

	void ForwardFrame(CMediaFrame* pFrame);

	void DoStopSource();


	// Video

	bool InitVideo(
		MediaType srcType,
		u_int16_t srcWidth,
		u_int16_t srcHeight,
		bool matchAspectRatios = true,
		bool realTime = true);

	void ProcessVideoFrame(
		u_int8_t* frameData,
		u_int32_t frameDataLength,
		Duration frameDuration);

	bool WillUseVideoFrame(Duration frameDuration);

	void DoGenerateKeyFrame() {
		m_videoWantKeyFrame = true;
	}

	void DoStopVideo();

	// Audio

	bool InitAudio(
		MediaType srcType,
		u_int8_t srcChannels,
		u_int32_t srcSampleRate,
		bool realTime);

	void ProcessAudioFrame(
		u_int8_t* frameData,
		u_int32_t frameDataLength,
		u_int32_t frameDuration);

	void ForwardEncodedAudioFrames(
		Timestamp baseTimestamp,
		u_int32_t* pNumSamples,
		u_int32_t* pNumFrames);

	Duration SamplesToTicks(u_int32_t numSamples) {
		return (numSamples * TimestampTicks)
			/ m_pConfig->GetIntegerValue(CONFIG_AUDIO_SAMPLE_RATE);
	}

	void DoStopAudio();

protected:
	static const int MSG_SOURCE_START_VIDEO	= 1;
	static const int MSG_SOURCE_START_AUDIO	= 2;
	static const int MSG_SOURCE_KEY_FRAME	= 3;

	// sink info
	static const u_int16_t MAX_SINKS = 8;
	CMediaSink* m_sinks[MAX_SINKS];
	SDL_mutex*	m_pSinksMutex;

	// generic media info
	bool			m_source;
	bool			m_sourceVideo;
	bool			m_sourceAudio;
	bool			m_sourceRealTime;
	Timestamp		m_startTimestamp;
	Duration		m_maxAheadDuration;

	// video source info
	MediaType		m_videoSrcType;
	u_int32_t		m_videoSrcFrameNumber;
	u_int16_t		m_videoSrcWidth;
	u_int16_t		m_videoSrcHeight;
	u_int16_t		m_videoSrcAdjustedHeight;
	float			m_videoSrcAspectRatio;
	u_int32_t		m_videoSrcYUVSize;
	u_int32_t		m_videoSrcYSize;
	u_int32_t		m_videoSrcUVSize;
	u_int32_t		m_videoSrcYCrop;
	u_int32_t		m_videoSrcUVCrop;

	// video destination info
	MediaType		m_videoDstType;
	float			m_videoDstFrameRate;
	Duration		m_videoDstFrameDuration;
	u_int32_t		m_videoDstFrameNumber;
	u_int16_t		m_videoDstWidth;
	u_int16_t		m_videoDstHeight;
	float			m_videoDstAspectRatio;
	u_int32_t		m_videoDstYUVSize;
	u_int32_t		m_videoDstYSize;
	u_int32_t		m_videoDstUVSize;

	// video resizing info
	image_t*		m_videoSrcYImage;
	image_t*		m_videoDstYImage;
	scaler_t*		m_videoYResizer;
	image_t*		m_videoSrcUVImage;
	image_t*		m_videoDstUVImage;
	scaler_t*		m_videoUVResizer;

	// video encoding info
	CVideoEncoder*	m_videoEncoder;
	bool			m_videoWantKeyFrame;

	// video timing info
	u_int32_t		m_videoSkippedFrames;
	Duration		m_videoEncodingDrift;
	Duration		m_videoEncodingMaxDrift;
	Duration		m_videoSrcElapsedDuration;
	Duration		m_videoDstElapsedDuration;

	// video previous frame info
	u_int8_t*		m_videoDstPrevImage;
	u_int8_t*		m_videoDstPrevReconstructImage;
	u_int8_t*		m_videoDstPrevFrame;
	u_int32_t		m_videoDstPrevFrameLength;


	// audio source info 
	MediaType		m_audioSrcType;
	u_int8_t		m_audioSrcChannels;
	u_int32_t		m_audioSrcSampleRate;
	u_int16_t		m_audioSrcSamplesPerFrame;
	u_int64_t		m_audioSrcSampleNumber;
	u_int32_t		m_audioSrcFrameNumber;

	// audio destination info
	MediaType		m_audioDstType;
	u_int8_t		m_audioDstChannels;
	u_int32_t		m_audioDstSampleRate;
	u_int16_t		m_audioDstSamplesPerFrame;
	u_int64_t		m_audioDstSampleNumber;
	u_int32_t		m_audioDstFrameNumber;
	u_int64_t		m_audioDstRawSampleNumber;
	u_int32_t		m_audioDstRawFrameNumber;

	// audio encoding info
	CAudioEncoder*	m_audioEncoder;

	// audio timing info
	Duration		m_audioSrcElapsedDuration;
	Duration		m_audioDstElapsedDuration;
};

#endif /* __MEDIA_SOURCE_H__ */

