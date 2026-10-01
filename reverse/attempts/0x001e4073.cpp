// ?rva001E4073@Rva001E4073@@QAEMPAVObject@@PAM@Z
// partial score=0.96 date=2026-10-01
// cl: /O1 /MD /arch:SSE
//
// ?rva001E4073@Rva001E4073@@QAEMPAVObject@@PAM@Z @0x001E4073 102B
// __thiscall float(obj, out): v1=Rva001E3F08::rva001E3F08(obj) 0x001E3F08
// maxTurn=Locomotor::getMaxTurnRate(obj) 0x001E3E9F; ratio=v1/maxTurn if maxTurn>0
// else g_00BDDAD8; if out: *out=(v1>0 ? ratio/v1 : 0); return ratio.
// Caller 0x001E7D1E in 0x001E7CDF.
class Object;
struct Rva001E3F08Arg;
class Rva001E3F08
{
public:
	float rva001E3F08(Rva001E3F08Arg *p);
};
class Locomotor
{
public:
	float getMaxTurnRate(Object *obj) const;
};
extern float g_00BDDAD8;
class Rva001E4073
{
public:
	float rva001E4073(Object *obj, float *out);
};
// ?rva001E4073@Rva001E4073@@QAEMPAVObject@@PAM@Z present-unmatched
float Rva001E4073::rva001E4073(Object *obj, float *out)
{
	Rva001E4073 *self = this;
	Object *o = obj;
	float v1 = ((Rva001E3F08 *)self)->rva001E3F08((Rva001E3F08Arg *)o);
	float maxTurn = ((const Locomotor *)self)->getMaxTurnRate(o);
	float ratio;
	if (maxTurn > 0.0f)
		ratio = v1 / maxTurn;
	else
		ratio = g_00BDDAD8;
	if (out)
	{
		float t = ratio / v1;
		if (!(v1 > 0.0f))
			t = 0.0f;
		*out = t;
	}
	return ratio;
}
