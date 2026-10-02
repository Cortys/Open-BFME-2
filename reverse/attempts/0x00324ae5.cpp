// ?Rva00324AE5Update@@YAXPAVGameWindow@@H_N@Z
// partial score=0.97 date=2026-10-02
// cl: /O1 /DNDEBUG /MD
// ?Rva00324AE5Update@@YAXPAVGameWindow@@H_N@Z, retail 0x00324AE5, 84 bytes.
// Free listbox display update: gets user data via rowed winGetUserData
// 0x005C4ACD, when flag at +0x10 set clamps top-entry from rowed fastcall
// Rva0032378 plus delta at +0xC against endPos word at +0x2C, then stores
// row diff words at +0/+4 into displayPos word at +0x44, finally calls
// pinned Rva003249D2 with window and flag. Evidence: callers in
// FUN_00725472/FUN_00725635/FUN_00725fbf push window int bool, unblocks
// 0x00325472 and 0x00325635, prev/next share /O1 /DNDEBUG /MD.
typedef int Int;
typedef short Short;

class GameWindow
{
public:
	void *winGetUserData();
};

struct _ListboxData;
int __fastcall Rva0032378(_ListboxData *listData);

void __cdecl Rva003249D2(GameWindow *window, bool updateSlider);

struct ListboxData00324AE5
{
	char pad0[0x18];
	void *rows;
	char pad1[0x10];
	short endPos;
	char pad2[0x16];
	short displayPos;
};

// ?Rva00324AE5Update@@YAXPAVGameWindow@@H_N@Z present-unmatched
void __cdecl Rva00324AE5Update(GameWindow *window, int delta, bool flag)
{
	void *userData = window->winGetUserData();
	if (flag)
	{
		int top = Rva0032378((_ListboxData *)userData);
		int idx = top + delta;
		if (idx <= 0)
			idx = 0;
		else
		{
			short count = *(short *)((char *)userData + 0x2C);
			if (idx >= count)
				idx = (int)count - 1;
		}
		ListboxData00324AE5 *list = (ListboxData00324AE5 *)userData;
		int rows = (int)list->rows;
		int entry = rows + (idx << 4);
		short v0 = *(short *)entry;
		short v1 = *(short *)(entry + 4);
		list->displayPos = (short)(v0 - v1);
	}
	Rva003249D2(window, flag);
}
