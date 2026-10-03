// ?rva006F1530@@YAXPAVBfmeAptValue006DCD20@@@Z
// partial score=0.85 date=2026-10-03
// cl: /O2 /DNDEBUG /MD
class Rva006F1530Inner
{
public:
	virtual void *slot0();
	virtual void *slot1();
	virtual void *slot2();
	virtual void *slot3();
	virtual void *slot4();
	virtual void *slot5();
	virtual void *slot6();
	virtual void *slot7();
	virtual void *slot8();
	virtual void *slot9();
};

class BfmeAptValue006DCD20
{
public:
	virtual void vtableSlot0();
	int isXmlNode() const;
	BfmeAptValue006DCD20 *rva006DD220();

private:
	char m_pad[0x1C];

public:
	Rva006F1530Inner *m_inner20;	// +0x20
};

class AptValue;
AptValue *Rva006D88C0MakeBool(bool b);

void rva006F1530(BfmeAptValue006DCD20 *obj)
{
	if (obj->isXmlNode()) {
		Rva006F1530Inner *inner = obj->rva006DD220()->m_inner20;
		if (inner) {
			Rva006D88C0MakeBool(inner->slot9() != 0);
			return;
		}
	}
	Rva006D88C0MakeBool(false);
}
