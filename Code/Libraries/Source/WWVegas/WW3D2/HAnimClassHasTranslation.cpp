// cl: /O1 /DNDEBUG /MD
//
// ?Has_X_Translation@HAnimClass@@UAE_NH@Z, retail 0x0018D1B0, 5 bytes.
// BFME1 hanim.h: `virtual bool Has_X_Translation(int pividx) { return true; }`, the first
// of six consecutive one-argument `return true` defaults (Has_X/Y/Z_Translation,
// Has_Rotation, Has_Visibility, _bfme_hanim_v21). Evidence: ??_7HAnimClass
// (0x00BD5CB8, installed by the ctor at 0x0018C84E) slots 15-20 all point at this one
// MOV AL,1 / RET 4 body, which retail folds; the row takes the first slot's name.

class HAnimClass
{
public:
	virtual bool Has_X_Translation(int pividx);
};

bool HAnimClass::Has_X_Translation(int pividx)
{
	return true;
}
