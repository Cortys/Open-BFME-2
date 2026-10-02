// ??1Rva000C2980@@QAE@XZ
// partial score=0.95 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD
// stlport
//
// ??1Rva000C2980@@QAE@XZ, retail 0x000C2980 292B.
// Non-virtual dtor (no vptr store in retail): AudioEventRTS* at +0xdc deleted
// then nulled, void* at +0xd0 freed, vector<Rva00B9AC2> at +0xc4, Rva000C1BE1
// (12B) at +0xb8, list base at +0xb4, five vector<AsciiString> at
// +0xa8/+0x9c/+0x90/+0x84/+0x78, AsciiString at +0x74/+0x70,
// vector<Rva00B6CF1> at +0x64, AsciiString at +0x60/+0x5c/+0x58,
// vector<AsciiString> at +0x4c. Evidence: retail call chain, deleting dtor
// at 0x000C3808, EH funclet 0x0076204B. Class may carry a vptr at +0 in
// reality; the dtor never touches +0x00..+0x4b so it is modelled as pad.
#include "ascii_string.h"
#include <vector>
#include <list>
struct Rva00B9AC2 { char _pad[0x18]; };
struct Rva00B6CF1 { char _pad[8]; };
struct Rva000C1BE1 { void *_p[3]; ~Rva000C1BE1(); };
class AudioEventRTS { public: ~AudioEventRTS(); };
extern "C" void __cdecl free(void *memory) throw(...);
class Rva000C2980
{
public:
	~Rva000C2980();
private:
	char _pad00[0x4c]; // +0x00..+0x4b
	_STL::vector<AsciiString> m_4c; // +0x4c
	AsciiString m_58; // +0x58
	AsciiString m_5c; // +0x5c
	AsciiString m_60; // +0x60
	_STL::vector<Rva00B6CF1> m_64; // +0x64
	AsciiString m_70; // +0x70
	AsciiString m_74; // +0x74
	_STL::vector<AsciiString> m_78; // +0x78
	_STL::vector<AsciiString> m_84; // +0x84
	_STL::vector<AsciiString> m_90; // +0x90
	_STL::vector<AsciiString> m_9c; // +0x9c
	_STL::vector<AsciiString> m_a8; // +0xa8
	_STL::_List_base<AsciiString, _STL::allocator<AsciiString> > m_b4; // +0xb4
	Rva000C1BE1 m_b8; // +0xb8
	_STL::vector<Rva00B9AC2> m_c4; // +0xc4
	void *m_d0; // +0xd0
	char _padD4[8]; // +0xd4..+0xdb
	AudioEventRTS *m_dc; // +0xdc
};
Rva000C2980::~Rva000C2980()
{
	if (m_dc != 0) {
		delete m_dc;
		m_dc = 0;
	}
	if (m_d0 != 0)
		free(m_d0);
}
