// ?rva00478FD7@Rva00478FD7@@QAEXXZ
// partial score=0.91 date=2026-10-01
// cl: /O1 /MD
// ?rva00478FD7@Rva00478FD7@@QAEXXZ @0x00478FD7 68B
// GarrisonContain-adjacent update: if flag at [this+4]+0xA0 set, fetch pair via rowed 0x0046247D then setPosition each list node to [this+8]+0x38.
// Evidence: callers 0x004796FA in 0x00479643; callees rowed 0x0046247D CondPair plus Thing setPosition 0x0030AA80; prev 0x0047860D GarrisonContain dtor.
struct Rva0046247DPair
{
	void *first;
	void *second;
};
class Rva0046247D
{
public:
	void rva0046247D(Rva0046247DPair &result);
};
struct Coord3D
{
	float x;
	float y;
	float z;
};
class Thing
{
public:
	void setPosition(const Coord3D *pos);
};
class Rva00478FD7 : public Rva0046247D
{
public:
	void rva00478FD7();
private:
	char m_pad0[4];
	void *m_unk4;
	void *m_unk8;
};
// ?rva00478FD7@Rva00478FD7@@QAEXXZ present-unmatched
void Rva00478FD7::rva00478FD7()
{
	if (*(unsigned char *)(*(char **)((char *)this + 4) + 0xA0) == 0)
		return;
	Rva0046247DPair tmp;
	rva0046247D(tmp);
	void **second = (void **)tmp.second;
	void *cur = *(void **)*second;
	if (cur != *second)
	{
		do
		{
			Coord3D *pos = (Coord3D *)(*(char **)((char *)this + 8) + 0x38);
			Thing *thing = *(Thing **)((char *)cur + 8);
			thing->setPosition(pos);
			cur = *(void **)cur;
		} while (cur != *second);
	}
}
