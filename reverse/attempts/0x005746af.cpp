// ??0Rva005746AF@@QAE@H@Z
// partial score=0.94 date=2026-09-28
// ??0Rva005746AF@@QAE@H@Z
// partial score=0.94 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
// ??0Rva005746AF@@QAE@H@Z retail 0x005746AF 35B
// Ctor storing vtable 0x0086E3B0 then int arg at +4 then timeGetTime at +8
// then zero at +0xC via and [mem],0. Evidence: vtable store at [this],
// IAT winmm timeGetTime call, sole callers at 0x005747E1 0x005750E3 0x00575139
// unblocking 0x005747DA and 0x00575125; neighbours share /O1. Honest Rva name.
extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);

class Rva005746AF
{
public:
	Rva005746AF(int arg);
	virtual ~Rva005746AF();
private:
	int m_04;
	unsigned long m_08;
	int m_0C;
};
// ??0Rva005746AF@@QAE@H@Z present-unmatched
Rva005746AF::Rva005746AF(int arg)
	: m_04(arg)
{
	m_08 = timeGetTime();
	m_0C = 0;
}
