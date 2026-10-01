// cl: /O1 /DNDEBUG /MD
//
// Three Object methods (retail Object.cpp range; this is the Object: its +0x10C
// model-condition words and the pinned notifier 0x0028AE6D). Names by address.
// Retail 0x00290758 (73 bytes): set condition bit 2*32+21 when the second
// argument is positive, else clear it (cl merges the two notifier calls), then
// forward both arguments to the matched Rva002716Holder broadcast on the +0x84
// member (tail jump).
// Retail 0x00293DAC / 0x00293E08 (92 bytes each): take the Object returned by
// the matched Object::rva002931F5(false); when it has the interface returned by
// the matched Object::rva0028C197, fill a (?, list) pair from its slot 66 and
// set (0x00290963) / clear (0x00290A10) the weapon set flag on every listed
// Object, then on that Object itself. The list is walked through raw nodes
// (next at +0, Object at +8) with the end reloaded each pass, as retail does.
// Model-condition bits as in ObjectWeaponSetFlags.cpp (word array at +0x10C,
// masked-word accessors).

enum WeaponSetType
{
	WEAPONSET_NONE = 0
};
class Rva002716Holder
{
public:
	void Rva0027164EBroadcast(int a, int b);
};
class Rva0010CBits
{
public:
	unsigned int test(int bit) const
	{
		return m_words[bit >> 5] & (1U << (bit & 0x1f));
	}
	void set(int bit)
	{
		m_words[bit >> 5] |= 1U << (bit & 0x1f);
	}
	void clear(int bit)
	{
		m_words[bit >> 5] &= ~(1U << (bit & 0x1f));
	}
private:
	unsigned int m_words[20];
};
class Object;
struct Rva00293DACNode
{
	Rva00293DACNode *m_next;
	Rva00293DACNode *m_prev;
	Object *m_object;
};
struct Rva00293DACList
{
	Rva00293DACNode *m_head;
};
struct Rva00293DACRange
{
	int m_00;
	const Rva00293DACList *m_list;
};
template <int N> class Rva00293DACSlots : public Rva00293DACSlots<N - 1>
{
public:
	virtual void gap(char (*)[N]) = 0;
};
template <> class Rva00293DACSlots<0>
{
};
// Interface returned by the matched Object::rva0028C197: slots 0..65
// placeholders, slot 66 fills a (?, list) pair.
class Rva00293DACIface : public Rva00293DACSlots<66>
{
public:
	virtual void rva00293DACSlot66(Rva00293DACRange *out) = 0;
};
class Object
{
public:
	void rva0028AE6D();
	Object *rva002931F5(bool flag);
	void *rva0028C197() const;
	void setWeaponSetFlag(WeaponSetType wst);
	void clearWeaponSetFlag(WeaponSetType wst);
	void rva00290758(int a, int b);
	void rva00293DAC(WeaponSetType wst);
	void rva00293E08(WeaponSetType wst);
private:
	unsigned char m_pad000[0x84];
	Rva002716Holder *m_84; // +0x84
	unsigned char m_pad088[0x10C - 0x88];
	Rva0010CBits m_conditionBits; // +0x10C
};
void Object::rva00290758(int a, int b)
{
	if (b > 0)
	{
		if (m_conditionBits.test(2 * 32 + 21) == 0)
		{
			m_conditionBits.set(2 * 32 + 21);
			rva0028AE6D();
		}
	}
	else
	{
		if (m_conditionBits.test(2 * 32 + 21) != 0)
		{
			m_conditionBits.clear(2 * 32 + 21);
			rva0028AE6D();
		}
	}
	if (m_84)
		m_84->Rva0027164EBroadcast(a, b);
}
void Object::rva00293DAC(WeaponSetType wst)
{
	Object *top = rva002931F5(false);
	if (top)
	{
		Rva00293DACIface *iface = (Rva00293DACIface *)top->rva0028C197();
		if (iface)
		{
			Rva00293DACRange range;
			iface->rva00293DACSlot66(&range);
			for (Rva00293DACNode *node = range.m_list->m_head->m_next; node != range.m_list->m_head; node = node->m_next)
				node->m_object->setWeaponSetFlag(wst);
			top->setWeaponSetFlag(wst);
		}
	}
}
void Object::rva00293E08(WeaponSetType wst)
{
	Object *top = rva002931F5(false);
	if (top)
	{
		Rva00293DACIface *iface = (Rva00293DACIface *)top->rva0028C197();
		if (iface)
		{
			Rva00293DACRange range;
			iface->rva00293DACSlot66(&range);
			for (Rva00293DACNode *node = range.m_list->m_head->m_next; node != range.m_list->m_head; node = node->m_next)
				node->m_object->clearWeaponSetFlag(wst);
			top->clearWeaponSetFlag(wst);
		}
	}
}
