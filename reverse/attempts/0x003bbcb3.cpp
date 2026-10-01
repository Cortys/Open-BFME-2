// ?Rva003BBCB3Set@@YGX_N@Z
// partial score=0.95 date=2026-10-01
// cl: /O1
// ?Rva003BBCB3Set@@YGX_N@Z @0x003BBCB3 31B leaf caller 0x003CC0C4 globals TheAudio slot 0x90 args 0 1 bool
// Evidence: mov ecx,[TheAudio] mov edx,[ecx] xor eax,eax cmp [esp+4],al sete al push eax push 1 push 0 call [edx+0x90] ret 4.
class AudioManager
{
public:
	virtual void s00();
	virtual void s01();
	virtual void s02();
	virtual void s03();
	virtual void s04();
	virtual void s05();
	virtual void s06();
	virtual void s07();
	virtual void s08();
	virtual void s09();
	virtual void s10();
	virtual void s11();
	virtual void s12();
	virtual void s13();
	virtual void s14();
	virtual void s15();
	virtual void s16();
	virtual void s17();
	virtual void s18();
	virtual void s19();
	virtual void s20();
	virtual void s21();
	virtual void s22();
	virtual void s23();
	virtual void s24();
	virtual void s25();
	virtual void s26();
	virtual void s27();
	virtual void s28();
	virtual void s29();
	virtual void s30();
	virtual void s31();
	virtual void s32();
	virtual void s33();
	virtual void s34();
	virtual void s35();
	virtual void s36(int, int, int);
};
extern AudioManager *TheAudio;
// ?Rva003BBCB3Set@@YGX_N@Z present-unmatched
void __stdcall Rva003BBCB3Set(bool a)
{
	TheAudio->s36(0, 1, !a ? 1 : 0);
}
