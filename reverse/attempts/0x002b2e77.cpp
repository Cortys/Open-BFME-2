// ?Rva002B2E77Append@@YAXXZ
// partial score=0.95 date=2026-09-28
// ?Rva002B2E77Append@@YAXXZ
// partial score=0.95 date=2026-09-28
// cl: /O1
// 0x002B2E77 23B free wrapper: GlobalHolder at RVA 0x00A00950 slot 0x48 returns
// GameMessage then tail appendIntegerArgument(0x6B9). Ours 24B with call+ret
// vs retail jmp (1B tail optimization left). Early push matches with single-
// statement return-void shape.
class GameMessage { public: void appendIntegerArgument(int v); };
class GlobalHolder {
public:
	virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
	virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
	virtual void s08(); virtual void s09(); virtual void s10(); virtual void s11();
	virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
	virtual void s16(); virtual void s17();
	virtual GameMessage* getMessage();
};
extern GlobalHolder* Glo00A00950;
// ?Rva002B2E77Append@@YAXXZ present-unmatched
void __cdecl Rva002B2E77Append()
{
	return Glo00A00950->getMessage()->appendIntegerArgument(0x6B9);
}
