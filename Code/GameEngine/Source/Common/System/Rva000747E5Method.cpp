// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD /DNDEBUG /DWIN32 /D_WINDOWS /arch:SSE
// ?rva000747E5@Rva000747E5@@QAEXXZ, retail 0x000747E5, 23 bytes.
// Guarded DisplayStringManager factory: if TheDisplayStringManager (VA 0xdfead8)
// then this+0x28 = manager->newDisplayString() at slot 0x38. Manager layout per
// Rva004E5821Method/WinInstanceDataDisplayStrings (new at 0x38 free at 0x3c).
// Evidence: unlock lane, caller 0x00046A50 (also caller of neighbouring
// Rva0007517F ctor/methods), same +0x28 member the ctor zeroes.
class DisplayString;

class DisplayStringManager
{
public:
	virtual ~DisplayStringManager() {}
	virtual void s04() = 0;
	virtual void s08() = 0;
	virtual void s0C() = 0;
	virtual void s10() = 0;
	virtual void s14() = 0;
	virtual void s18() = 0;
	virtual void s1C() = 0;
	virtual void s20() = 0;
	virtual void s24() = 0;
	virtual void s28() = 0;
	virtual void s2C() = 0;
	virtual void s30() = 0;
	virtual void s34() = 0;
	virtual DisplayString *newDisplayString() = 0;
	virtual void freeDisplayString(DisplayString *s) = 0;
};

extern DisplayStringManager *TheDisplayStringManager;

class Rva000747E5
{
public:
	void rva000747E5();
private:
	char m_pad[0x28];
	DisplayString *m_28;
};

void Rva000747E5::rva000747E5()
{
	if (TheDisplayStringManager != 0)
		m_28 = TheDisplayStringManager->newDisplayString();
}
