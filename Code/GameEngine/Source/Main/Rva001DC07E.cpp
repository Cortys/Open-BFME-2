// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva001DC07E@Rva001DC07E@@QAEXXZ @0x001DC07E 73B: wait loop on TheAudio ready with WindowManager Display setFPMode Sleep. Evidence: caller at 0x001DC618; callees rowed rva001DBFEE setFPMode plus pins.
class AudioManager
{
public:
	bool rva001DBFEE();
};

class GameWindowManager
{
public:
	virtual void v00();
	virtual void v01();
	virtual void v02();
	virtual void v03();
	virtual void v04();
	virtual void v05();
	virtual void v06();
	virtual void v07();
	virtual void v08();
	virtual void v09();
	virtual void unk28();
};

class Display
{
public:
	virtual void v00();
	virtual void v01();
	virtual void v02();
	virtual void v03();
	virtual void v04();
	virtual void v05();
	virtual void v06();
	virtual void v07();
	virtual void v08();
	virtual void v09();
	virtual void v10();
	virtual void v11();
	virtual void unk30();
};

extern GameWindowManager *TheWindowManager;
extern AudioManager *TheAudio;
extern Display *TheDisplay;
void __cdecl setFPMode();
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);

class Rva001DC07E
{
public:
	void rva001DC07E();
private:
	char m_pad[0x64];
	unsigned long m_64;
};

void Rva001DC07E::rva001DC07E()
{
	while (!TheAudio->rva001DBFEE()) {
		TheWindowManager->unk28();
		if (TheAudio->rva001DBFEE())
			continue;
		TheDisplay->unk30();
		setFPMode();
		Sleep(m_64);
	}
}
