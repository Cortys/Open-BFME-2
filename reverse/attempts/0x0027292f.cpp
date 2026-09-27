// ?setTerrainDecalSize@Drawable@@QAEXMM@Z
// partial score=0.91 date=2026-09-27
// ?setTerrainDecalSize@Drawable@@QAEXMM@Z
// partial score=0.91 date=2026-09-27
// cl: /O2 /MD /G7
//
// ?setTerrainDecalSize@Drawable@@QAEXMM@Z, retail 0x0027292F, 22 bytes.
// First-module forwarder over draw modules at this+0x14C to DrawModule
// slot 0x64. Evidence: BFME1 donor Drawable::setTerrainDecalSize in
// reference/open-bfme-1/Code/GameEngine/Source/GameClient/Drawable.cpp
// (DrawModule** dm = getDrawModules(); if (*dm) (*dm)->setTerrainDecalSize);
// retail +0x14C matches landed pristine twin 0x0027274D; 2-float ret-8 shape.

class BfmeDrawModuleForDecalSize
{
public:
	virtual void slot00() = 0; virtual void slot04() = 0;
	virtual void slot08() = 0; virtual void slot0C() = 0;
	virtual void slot10() = 0; virtual void slot14() = 0;
	virtual void slot18() = 0; virtual void slot1C() = 0;
	virtual void slot20() = 0; virtual void slot24() = 0;
	virtual void slot28() = 0; virtual void slot2C() = 0;
	virtual void slot30() = 0; virtual void slot34() = 0;
	virtual void slot38() = 0; virtual void slot3C() = 0;
	virtual void slot40() = 0; virtual void slot44() = 0;
	virtual void slot48() = 0; virtual void slot4C() = 0;
	virtual void slot50() = 0; virtual void slot54() = 0;
	virtual void slot58() = 0; virtual void slot5C() = 0;
	virtual void slot60() = 0;
	virtual void setTerrainDecalSize(float x, float y) = 0;
};

class Drawable
{
public:
	void setTerrainDecalSize(float x, float y);
};

// ?setTerrainDecalSize@Drawable@@QAEXMM@Z present-unmatched
void Drawable::setTerrainDecalSize(float x, float y)
{
	BfmeDrawModuleForDecalSize *first =
		**reinterpret_cast<BfmeDrawModuleForDecalSize ***>((unsigned char *)this + 0x14C);
	if (first) {
		first->setTerrainDecalSize(x, y);
	}
}
