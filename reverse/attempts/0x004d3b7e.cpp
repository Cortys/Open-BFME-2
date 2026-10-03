// ?rva004D3B7E@DisconnectManager@@QAEEHPAVBFMEConnectionManager@@@Z
// partial score=0.93 date=2026-10-03
// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /O1
// ?rva004D3B7E@DisconnectManager@@QAEEHPAVBFMEConnectionManager@@@Z 0x004D3B7E 55 predicate on slot and BFMEConnectionManager
// Evidence: between 0x004D3AB2 and 0x004D3CA8 in DisconnectManager area; callees isPlayerConnected 0x004CF083 and rva004CEF58 0x004CEF58; callers 0x004D3C02 0x004D3E6D 0x004D3EA9 set ecx=this plus two stack args.

class BFMEConnectionManager
{
public:
	bool isPlayerConnected(int slot);
	unsigned char rva004CEF58(int slot);
};

class DisconnectManager
{
public:
	unsigned char rva004D3B7E(int slot, BFMEConnectionManager *mgr);
};

// ?rva004D3B7E@DisconnectManager@@QAEEHPAVBFMEConnectionManager@@@Z present-unmatched
unsigned char DisconnectManager::rva004D3B7E(int slot, BFMEConnectionManager *mgr)
{
	if ((unsigned int)slot < 8)
	{
		if (mgr != 0)
		{
			if (!mgr->isPlayerConnected(slot))
				return 1;
			if (!mgr->rva004CEF58(slot))
				return 1;
			return 0;
		}
		return 0;
	}
	return 1;
}
