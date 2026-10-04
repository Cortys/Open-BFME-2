// cl: /O1 /DNDEBUG /MD
//
// ModelConditionSpecialAbilityUpdate's slot-22 override (vftable whose
// slot-2 name getter returns "ModelConditionSpecialAbilityUpdate"; rowed
// pool key 0x00490D96). It runs the base SpecialAbilityUpdate slot 22
// (pinned rva004508B7) and carries that slot's address name, which cl 7.1
// needs to place the override; the method identity is not established.
//
// ?rva004508B7@ModelConditionSpecialAbilityUpdate@@UAEXXZ, retail 0x00490ECF, 102 bytes.
// While the ability state at +0x24 is 0, sets one model-condition bit on the
// owner chosen by module data +0xC8 (0: bit 10*32+10; 1 to 3: bits 6*32+19
// to 6*32+21) and, when it was clear, runs the pinned notifier
// Object::rva0028AE6D (the HordeSiegeEngineContainRiders bit helper).
//
// ?onExit@ModelConditionSpecialAbilityUpdate@@MAEX_N0@Z, retail 0x00490F35, 121 bytes.
// Slot 13, where the SpecialAbilityUpdate vftable holds the rowed onExit
// 0x004502CE: runs it, then clears the bit slot 22 set (same choice by module
// data +0xC8) and notifies when it was set.

class ModuleData;

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

class Object
{
public:
	void rva0028AE6D();
	unsigned char m_pad000[0x10C];
	Rva0010CBits m_conditionBits; // +0x10C
};

static __forceinline void setModelConditionBit(Object *object, int bit)
{
	if (object->m_conditionBits.test(bit) == 0)
	{
		object->m_conditionBits.set(bit);
		object->rva0028AE6D();
	}
}

static __forceinline void clearModelConditionBit(Object *object, int bit)
{
	if (object->m_conditionBits.test(bit) != 0)
	{
		object->m_conditionBits.clear(bit);
		object->rva0028AE6D();
	}
}

struct ModelConditionSpecialAbilityUpdateModuleData
{
	unsigned char m_pad00[0xC8];
	int m_C8;
};

class ModelConditionSpecialAbilityUpdate;

class SpecialAbilityUpdate
{
	friend class ModelConditionSpecialAbilityUpdate;
public:
	virtual void rva004508B7();
private:
	void onExit(bool a, bool b);
protected:
	const ModuleData *m_moduleData; // +0x04
	Object *m_object; // +0x08
	unsigned char m_pad0C[0x24 - 0x0C];
	int m_24; // +0x24
};

class ModelConditionSpecialAbilityUpdate : public SpecialAbilityUpdate
{
public:
	virtual void rva004508B7();
protected:
	virtual void onExit(bool a, bool b);
};

// ?rva004508B7@ModelConditionSpecialAbilityUpdate@@UAEXXZ @0x00490ECF
void ModelConditionSpecialAbilityUpdate::rva004508B7()
{
	SpecialAbilityUpdate::rva004508B7();
	if (m_24 != 0)
		return;

	const ModelConditionSpecialAbilityUpdateModuleData *data =
		(const ModelConditionSpecialAbilityUpdateModuleData *)m_moduleData;
	Object *object = m_object;
	switch (data->m_C8)
	{
	case 0:
		setModelConditionBit(object, 10 * 32 + 10);
		break;
	case 1:
		setModelConditionBit(object, 6 * 32 + 19);
		break;
	case 2:
		setModelConditionBit(object, 6 * 32 + 20);
		break;
	case 3:
		setModelConditionBit(object, 6 * 32 + 21);
		break;
	}
}

// ?onExit@ModelConditionSpecialAbilityUpdate@@MAEX_N0@Z @0x00490F35
void ModelConditionSpecialAbilityUpdate::onExit(bool a, bool b)
{
	SpecialAbilityUpdate::onExit(a, b);

	const ModelConditionSpecialAbilityUpdateModuleData *data =
		(const ModelConditionSpecialAbilityUpdateModuleData *)m_moduleData;
	Object *object = m_object;
	switch (data->m_C8)
	{
	case 0:
		clearModelConditionBit(object, 10 * 32 + 10);
		break;
	case 1:
		clearModelConditionBit(object, 6 * 32 + 19);
		break;
	case 2:
		clearModelConditionBit(object, 6 * 32 + 20);
		break;
	case 3:
		clearModelConditionBit(object, 6 * 32 + 21);
		break;
	}
}
