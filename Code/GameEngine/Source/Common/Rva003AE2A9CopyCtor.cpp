// cl: /DNDEBUG /MD /GX- /O1 /Ob2
// ??0Rva003AE2A9@@QAE@ABV0@@Z @0x003AE2A9 38B
// Copy ctor: base Rva003AE2CF at +0 via rowed copy 0x003AE2CF then own
// three vptrs. Evidence: retail base call plus stores at +0/+8/+0x10
// plus ret 4, chain after landing 0x003AE2CF. Sibling of 0x003AE0AF.
class Rva003AE2CF {
public: Rva003AE2CF(const Rva003AE2CF &that);
private: char m_pad[0x24 - 4];
};

extern "C" char Rva003AE2A9_v0;
extern "C" char Rva003AE2A9_v8;
extern "C" char Rva003AE2A9_v10;

class Rva003AE2A9 : public Rva003AE2CF {
public: __declspec(noinline) Rva003AE2A9(const Rva003AE2A9 &that);
};

Rva003AE2A9::Rva003AE2A9(const Rva003AE2A9 &that)
	: Rva003AE2CF(that)
{
	*(void **)this = &Rva003AE2A9_v0;
	*(void **)((char *)this + 8) = &Rva003AE2A9_v8;
	*(void **)((char *)this + 0x10) = &Rva003AE2A9_v10;
}
