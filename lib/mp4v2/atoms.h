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
 * Copyright (C) Cisco Systems Inc. 2001.  All Rights Reserved.
 * 
 * Contributor(s): 
 *		Dave Mackie		dmackie@cisco.com
 */

#ifndef __MP4_ATOMS_INCLUDED__
#define __MP4_ATOMS_INCLUDED__

class MP4RootAtom : public MP4Atom {
public:
	MP4RootAtom();
	void StartWrite();
	void Write();
};

class MP4FtypAtom : public MP4Atom {
public:
	MP4FtypAtom();
	void Generate();
	void Read();
};

class MP4MdatAtom : public MP4Atom {
public:
	MP4MdatAtom();
	void Read();
};

class MP4MoovAtom : public MP4Atom {
public:
	MP4MoovAtom();
};

class MP4MvhdAtom : public MP4Atom {
public:
	MP4MvhdAtom();
	void Generate();
	void Read();
protected:
	void AddVersion0Properties();
	void AddVersion1Properties();
};

class MP4IodsAtom : public MP4Atom {
public:
	MP4IodsAtom();
};

class MP4TrakAtom : public MP4Atom {
public:
	MP4TrakAtom();
};

class MP4TkhdAtom : public MP4Atom {
public:
	MP4TkhdAtom();
	void Generate();
	void Read();
protected:
	void AddVersion0Properties();
	void AddVersion1Properties();
};

class MP4TrefAtom : public MP4Atom {
public:
	MP4TrefAtom();
};

class MP4HintAtom : public MP4Atom {
public:
	MP4HintAtom();
	void Read();
};

class MP4MdiaAtom : public MP4Atom {
public:
	MP4MdiaAtom();
};

class MP4MdhdAtom : public MP4Atom {
public:
	MP4MdhdAtom();
	void Generate();
	void Read();
protected:
	void AddVersion0Properties();
	void AddVersion1Properties();
};

class MP4HdlrAtom : public MP4Atom {
public:
	MP4HdlrAtom();
	void Read();
};

class MP4MinfAtom : public MP4Atom {
public:
	MP4MinfAtom();
};

class MP4VmhdAtom : public MP4Atom {
public:
	MP4VmhdAtom();
};

class MP4SmhdAtom : public MP4Atom {
public:
	MP4SmhdAtom();
};

class MP4HmhdAtom : public MP4Atom {
public:
	MP4HmhdAtom();
};

class MP4NmhdAtom : public MP4Atom {
public:
	MP4NmhdAtom();
};

class MP4DinfAtom : public MP4Atom {
public:
	MP4DinfAtom();
};

class MP4DrefAtom : public MP4Atom {
public:
	MP4DrefAtom();
	void Read();
};

class MP4UrlAtom : public MP4Atom {
public:
	MP4UrlAtom();
	void Read();
	void Write();
};

class MP4UrnAtom : public MP4Atom {
public:
	MP4UrnAtom();
	void Read();
};

class MP4StblAtom : public MP4Atom {
public:
	MP4StblAtom();
};

class MP4StsdAtom : public MP4Atom {
public:
	MP4StsdAtom();
	void Read();
};

class MP4Mp4aAtom : public MP4Atom {
public:
	MP4Mp4aAtom();
};

class MP4Mp4sAtom : public MP4Atom {
public:
	MP4Mp4sAtom();
};

class MP4Mp4vAtom : public MP4Atom {
public:
	MP4Mp4vAtom();
};

class MP4EsdsAtom : public MP4Atom {
public:
	MP4EsdsAtom();
};

class MP4SttsAtom : public MP4Atom {
public:
	MP4SttsAtom();
};

class MP4CttsAtom : public MP4Atom {
public:
	MP4CttsAtom();
};

class MP4StszAtom : public MP4Atom {
public:
	MP4StszAtom();
	void Read();
	void Write();
};

class MP4StscAtom : public MP4Atom {
public:
	MP4StscAtom();
	void Read();
};

class MP4StcoAtom : public MP4Atom {
public:
	MP4StcoAtom();
};

class MP4Co64Atom : public MP4Atom {
public:
	MP4Co64Atom();
};

class MP4StssAtom : public MP4Atom {
public:
	MP4StssAtom();
};

class MP4StshAtom : public MP4Atom {
public:
	MP4StshAtom();
};

class MP4StdpAtom : public MP4Atom {
public:
	MP4StdpAtom();
	void Read();
};

class MP4EdtsAtom : public MP4Atom {
public:
	MP4EdtsAtom();
};

class MP4ElstAtom : public MP4Atom {
public:
	MP4ElstAtom();
	void Generate();
	void Read();
protected:
	void AddVersion0Properties();
	void AddVersion1Properties();
};

class MP4UdtaAtom : public MP4Atom {
public:
	MP4UdtaAtom();
	void Read();
};

class MP4CprtAtom : public MP4Atom {
public:
	MP4CprtAtom();
};

class MP4HntiAtom : public MP4Atom {
public:
	MP4HntiAtom();
	void Read();
};

class MP4RtpAtom : public MP4Atom {
public:
	MP4RtpAtom();
	void Read();
};

class MP4SdpAtom : public MP4Atom {
public:
	MP4SdpAtom();
	void Read();
};

class MP4HinfAtom : public MP4Atom {
public:
	MP4HinfAtom();
};

class MP4TrpyAtom : public MP4Atom {
public:
	MP4TrpyAtom();
};

class MP4NumpAtom : public MP4Atom {
public:
	MP4NumpAtom();
};

class MP4TpylAtom : public MP4Atom {
public:
	MP4TpylAtom();
};

class MP4MaxrAtom : public MP4Atom {
public:
	MP4MaxrAtom();
};

class MP4DmedAtom : public MP4Atom {
public:
	MP4DmedAtom();
};

class MP4DimmAtom : public MP4Atom {
public:
	MP4DimmAtom();
};

class MP4DrepAtom : public MP4Atom {
public:
	MP4DrepAtom();
};

class MP4TminAtom : public MP4Atom {
public:
	MP4TminAtom();
};

class MP4TmaxAtom : public MP4Atom {
public:
	MP4TmaxAtom();
};

class MP4PmaxAtom : public MP4Atom {
public:
	MP4PmaxAtom();
};

class MP4DmaxAtom : public MP4Atom {
public:
	MP4DmaxAtom();
};

class MP4PaytAtom : public MP4Atom {
public:
	MP4PaytAtom();
};

class MP4FreeAtom : public MP4Atom {
public:
	MP4FreeAtom();
	void Read();
};

#endif /* __MP4_ATOMS_INCLUDED__ */