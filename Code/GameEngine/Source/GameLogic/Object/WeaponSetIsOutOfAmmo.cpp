// cl: /O1
//
// ?isOutOfAmmo@WeaponSet@@QBE_NXZ @0x002C73CE, 41B.
// WeaponSet::isOutOfAmmo. Returns true when every present weapon reports
// OUT_OF_AMMO (1), skipping null slots. Retail scans the six slots at +0x8.
// Evidence: neighbour WeaponSetRvaSlotSearch.cpp proves six slots at +0x8;
// caller 0x0028ADD5 does add ecx 0x330 then jmp here (Object WeaponSet
// forwarder); callee ?getStatus@Weapon@@QBE?AW4WeaponStatus@@XZ is rowed.
// Donor: ZH WeaponSet::isOutOfAmmo verbatim except WEAPONSLOT_COUNT 6.

enum WeaponStatus
{
	READY_TO_FIRE,
	OUT_OF_AMMO,
	BETWEEN_FIRING_SHOTS,
	RELOADING_CLIP,
	PRE_ATTACK
};

class Weapon
{
public:
	WeaponStatus getStatus() const;
};

class WeaponSet
{
public:
	bool isOutOfAmmo() const;

private:
	char m_pad[8];
	Weapon *m_weapons[6];
};

bool WeaponSet::isOutOfAmmo() const
{
	for (int i = 0; i < 6; ++i) {
		const Weapon *weapon = m_weapons[i];
		if (weapon == 0)
			continue;
		if (weapon->getStatus() != OUT_OF_AMMO)
			return false;
	}
	return true;
}
