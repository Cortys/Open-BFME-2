// ?rva004CB333@UpgradeMuxData@@QAE_NPAVObject@@@Z
// partial score=0.97 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /Oy- /DNDEBUG /MD /GX- /Oi-
//
// ?rva004CB333@UpgradeMuxData@@QAE_NPAVObject@@@Z, retail 0x004CB333, 197 bytes.
// UpgradeMuxData gate: optional drawable 19-dword mask check then 1024-bit
// activation/conflicting test against Object bits. Evidence: calls rowed
// UpgradeMuxData::getUpgradeActivationMasks 0x004CB189, Thing::getDrawable
// 0x005508E2, Rva001DFE56 19-dword tester 0x001DFE56, clear80 0x001EAE6F x2,
// Object::rva0028D9E5 0x0028D9E5 x2; flags +0x381/+0x382, masks +0x118/+0x164.

struct UpgradeMaskType
{
	unsigned long m_words[32];
};

class Rva001EAE6FHelper
{
public:
	Rva001EAE6FHelper *clear80();
private:
	char m_pad[0x80];
};

class Rva001DFE56
{
public:
	bool rva001DFE56(const void *required, const void *exempt) const;
};

class Drawable
{
public:
	char m_pad00[0x258];
	Rva001DFE56 m_tester;
};

class Thing
{
public:
	Drawable *getDrawable() const;
};

class Object : public Thing
{
public:
	bool rva0028D9E5(int bit) const;
};

class UpgradeMuxData
{
public:
	bool rva004CB333(Object *obj);
	void getUpgradeActivationMasks(UpgradeMaskType &activation, UpgradeMaskType &conflicting) const;
private:
	char m_pad00[0x118];
	unsigned m_req19[19];
	unsigned m_ban19[19];
	char m_pad1B0[0x381 - 0x1B0];
	unsigned char m_flag381;
	unsigned char m_flag382;
};

// ?rva004CB333@UpgradeMuxData@@QAE_NPAVObject@@@Z present-unmatched
bool UpgradeMuxData::rva004CB333(Object *obj)
{
	if (m_flag381 != 0 || m_flag382 != 0)
	{
		Drawable *drawable = obj->getDrawable();
		if (drawable == 0)
			return false;
		if (!drawable->m_tester.rva001DFE56(m_req19, m_ban19))
			return false;
	}
	Rva001EAE6FHelper hAct;
	Rva001EAE6FHelper hConf;
	hAct.clear80();
	hConf.clear80();
	UpgradeMaskType &activation = (UpgradeMaskType &)hAct;
	UpgradeMaskType &conflicting = (UpgradeMaskType &)hConf;
	getUpgradeActivationMasks(activation, conflicting);
	for (int bit = 0; bit < 0x400; ++bit)
	{
		unsigned word = (unsigned)bit >> 5;
		if ((activation.m_words[word] & (1u << (bit & 31))) != 0)
		{
			if (!obj->rva0028D9E5(bit))
				return false;
		}
		if ((conflicting.m_words[word] & (1u << (bit & 31))) != 0)
		{
			if (obj->rva0028D9E5(bit))
				return false;
		}
	}
	return true;
}
