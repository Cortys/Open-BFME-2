// ?Rva0041B94AGet@@YG_NPAVObject@@0H@Z
// partial score=0.96 date=2026-09-30
// ?Rva0041B94AGet@@YG_NPAVObject@@0H@Z
// partial score=0.96 date=2026-09-30
// cl: /O1 /MD
// ?Rva0041B94AGet@@YG_NPAVObject@@0H@Z @0x0041B94A 102B
// Object pair helper via rowed rva002931F5 rva0028C197 and provider slot28.
// Evidence: callees rva002931F5 0x002931F5 row ObjectRva002931F5.cpp rva0028C197 0x0028C197 row ObjectRva0028C197.cpp virtual slot28 at 0x70; callers 0x00264746 0x0029CA25 0x00346177 0x0041D464; prev next GameEngineDeletingBaseDerived.cpp same flags; ret 0xC stdcall 3 args.
class Object
{
public:
	Object *rva002931F5(bool checkProducer);
	void *rva0028C197() const;
};
struct Provider28
{
	virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
	virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
	virtual void s08(); virtual void s09(); virtual void s10(); virtual void s11();
	virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
	virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
	virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
	virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
	virtual bool slot28(Object *other);
};
extern "C" void _WriteBarrier(void);
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_WriteBarrier, _ReadWriteBarrier)
// ?Rva0041B94AGet@@YG_NPAVObject@@0H@Z present-unmatched
bool __stdcall Rva0041B94AGet(Object *a, Object *b, int)
{
	if (a == 0 || b == 0)
		return false;
	Object *aObj = a->rva002931F5(false);
	Object *bObj = b->rva002931F5(false);
	if (aObj == bObj)
		return false;
	if (aObj != 0 && bObj == 0)
	{
		void *p = aObj->rva0028C197();
		if (p == 0)
			return false;
		if (((Provider28 *)p)->slot28(b))
		{
			_WriteBarrier();
			return true;
		}
		_ReadWriteBarrier();
		return false;
	}
	else
	{
		void *p = bObj->rva0028C197();
		if (p == 0)
			return false;
		if (((Provider28 *)p)->slot28(a))
		{
			_WriteBarrier();
			return true;
		}
		_ReadWriteBarrier();
		return false;
	}
}
