// cl: /O1 /MD
//
// ?rva005CB260@Rva005CB260@@QAEXXZ @0x005CB260 5B.
// Evidence: retail mov eax,[ecx]; jmp [eax+4] (slot 1 forwarder); LINK BONUS
// requires exactly QAEXXZ; twin pins at 0x005CB260; caller
// RadarWindowOverrideSource::rva002D370A passes +0xC8 pointer as this.

class Rva005CB260
{
public:
	virtual void rva005CB260_slot0();
	virtual void rva005CB260_slot1();
	void rva005CB260();
};

void Rva005CB260::rva005CB260()
{
	rva005CB260_slot1();
}
