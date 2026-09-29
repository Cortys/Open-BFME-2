// cl: /DNDEBUG /MD /GX- /O1 /Ob2
// ??0Rva003AE0AF@@QAE@ABV0@@Z @0x003AE0AF 38B
// Copy ctor: base Rva003AE0D5 at +0 via rowed copy 0x003AE0D5 then own
// three vptrs. Evidence: retail base call plus stores at +0/+8/+0x10
// plus ret 4, chain after landing 0x003AE0D5. Precedent: same-file base.
class Rva003AE0D5 {
public: Rva003AE0D5(const Rva003AE0D5 &that);
private: char m_pad[0x20 - 4];
};

extern "C" char Rva003AE0AF_v0;
extern "C" char Rva003AE0AF_v8;
extern "C" char Rva003AE0AF_v10;

class Rva003AE0AF : public Rva003AE0D5 {
public: __declspec(noinline) Rva003AE0AF(const Rva003AE0AF &that);
};

Rva003AE0AF::Rva003AE0AF(const Rva003AE0AF &that)
	: Rva003AE0D5(that)
{
	*(void **)this = &Rva003AE0AF_v0;
	*(void **)((char *)this + 8) = &Rva003AE0AF_v8;
	*(void **)((char *)this + 0x10) = &Rva003AE0AF_v10;
}
