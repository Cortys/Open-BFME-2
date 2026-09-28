// ?rva004D3D2B@DisconnectManager@@QAEXPAVConnectionManager@@@Z
// partial score=0.96 date=2026-09-28
// ?rva004D3D2B@DisconnectManager@@QAEXPAVConnectionManager@@@Z
// partial score=0.96 date=2026-09-28
// cl: /O1
//
// ?rva004D3D2B@DisconnectManager@@QAEXPAVConnectionManager@@@Z @0x004D3D2B 49B
// DisconnectManager 8-slot helper. Evidence: __thiscall via ecx plus ret-4
// single ConnectionManager arg; rowed callees getLocalPlayerID 0x004CF906
// plus Rva004D39DEGet 0x004D39DE plus resetPlayerTimeout 0x004D3A06;
// loop 8 with Get plus conditional reset; sibling of rva004D3CA8.
int Rva004D39DEGet(int a, int b);

class ConnectionManager
{
public:
	unsigned int getLocalPlayerID();
};

class DisconnectManager
{
public:
	void resetPlayerTimeout(int slot);
	void rva004D3D2B(ConnectionManager *a2);
};

void DisconnectManager::rva004D3D2B(ConnectionManager *a2)
{
	for (int i = 0; i < 8; ++i)
	{
		int idx = Rva004D39DEGet(i, (int)a2->getLocalPlayerID());
		if (idx != -1)
			resetPlayerTimeout(idx);
	}
}
