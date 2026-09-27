// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?rva0028C197@Object@@QBEPAXXZ @0x0028C197 18B
// Object null-checked tail forward through the +0x250 interface (same offset
// Object_isAbleToAttack.cpp and Weapon_getRemainingAmmo.cpp document) to its
// vtable slot 0x7c. Retail shape is mov ecx+0x250 plus test plus jne plus
// xor-ret plus indirect jmp. 40-plus callers including 0x0028C4B6. Landing
// unblocks 70. Identity beyond the Object owner is unproven so the name
// stays address-derived. Flags from the same-page Object sibling
// Object_bfmeRefreshPartitionCells.cpp; if (p == 0) selects the retail jne.
class Rva0028C197Provider
{
public:
	virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
	virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
	virtual void slot08(); virtual void slot09(); virtual void slot10(); virtual void slot11();
	virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
	virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
	virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
	virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
	virtual void slot28(); virtual void slot29(); virtual void slot30();
	virtual void *slot31();
};

class Object
{
	char m_pad[0x250];
	Rva0028C197Provider *m_provider250;

public:
	void *rva0028C197() const;
};

void *Object::rva0028C197() const
{
	Rva0028C197Provider *provider = m_provider250;
	if (provider == 0)
		return 0;
	return provider->slot31();
}
