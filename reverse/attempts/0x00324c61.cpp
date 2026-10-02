// ?Rva00324C61Layout@@YAXPAVGameWindow@@@Z
// partial score=0.91 date=2026-10-02
// cl: /O1 /DNDEBUG /MD
// ?Rva00324C61Layout@@YAXPAVGameWindow@@@Z, retail 0x00324C61, 291 bytes.
// Free-function listbox layout: walks outer cols at user+0x18, inner items
// size 0x1c, max per col, accumulates total at user+0x28 then calls rowed
// Rva003249D2(window,1). Type1 via virtual [obj+0x3c](0,&cur) unless status
// has 0x4000, type2 via +0x18+1, else WindowManager [0x120](font at
// inst+0x184). Callers 0x00324E7F 0x00325622 0x0032636F 0x00326588 0x00326F72.
// Evidence: callees rowed winGetUserData winGetInstanceData winGetStatus,
// pin Rva003249D2, global TheWindowManager.

class GameWindow;
class WinInstanceData;

class GameWindow
{
public:
	void *winGetUserData(void);
	WinInstanceData *winGetInstanceData(void);
	unsigned int winGetStatus(void);
};

struct WinInstanceData
{
	char m_pad00[0x184];
	void *m_font;
};

class GameWindowManager
{
public:
	virtual void v00(void); virtual void v01(void); virtual void v02(void); virtual void v03(void);
	virtual void v04(void); virtual void v05(void); virtual void v06(void); virtual void v07(void);
	virtual void v08(void); virtual void v09(void); virtual void v10(void); virtual void v11(void);
	virtual void v12(void); virtual void v13(void); virtual void v14(void); virtual void v15(void);
	virtual void v16(void); virtual void v17(void); virtual void v18(void); virtual void v19(void);
	virtual void v20(void); virtual void v21(void); virtual void v22(void); virtual void v23(void);
	virtual void v24(void); virtual void v25(void); virtual void v26(void); virtual void v27(void);
	virtual void v28(void); virtual void v29(void); virtual void v30(void); virtual void v31(void);
	virtual void v32(void); virtual void v33(void); virtual void v34(void); virtual void v35(void);
	virtual void v36(void); virtual void v37(void); virtual void v38(void); virtual void v39(void);
	virtual void v40(void); virtual void v41(void); virtual void v42(void); virtual void v43(void);
	virtual void v44(void); virtual void v45(void); virtual void v46(void); virtual void v47(void);
	virtual void v48(void); virtual void v49(void); virtual void v50(void); virtual void v51(void);
	virtual void v52(void); virtual void v53(void); virtual void v54(void); virtual void v55(void);
	virtual void v56(void); virtual void v57(void); virtual void v58(void); virtual void v59(void);
	virtual void v60(void); virtual void v61(void); virtual void v62(void); virtual void v63(void);
	virtual void v64(void); virtual void v65(void); virtual void v66(void); virtual void v67(void);
	virtual void v68(void); virtual void v69(void); virtual void v70(void); virtual void v71(void);
	virtual int getHeight(void *font);
};

extern GameWindowManager *TheWindowManager;

class Rva00324C61Obj
{
public:
	virtual void w00(void); virtual void w01(void); virtual void w02(void); virtual void w03(void);
	virtual void w04(void); virtual void w05(void); virtual void w06(void); virtual void w07(void);
	virtual void w08(void); virtual void w09(void); virtual void w10(void); virtual void w11(void);
	virtual void w12(void); virtual void w13(void); virtual void w14(void);
	virtual void getItemHeight(int zero, int *out);
};

struct Rva00324C61Item
{
	int m_type;
	char m_pad04[8];
	Rva00324C61Obj *m_obj;
	char m_pad10[8];
	int m_height;
};

struct Rva00324C61Col
{
	int m_pos;
	int m_max;
	Rva00324C61Item *m_items;
	int m_pad0C;
};

struct Rva00324C61Data
{
	char m_pad00[2];
	short m_innerCount;
	char m_pad04[0x14];
	Rva00324C61Col *m_cols;
	char m_pad1C[0x0C];
	int m_total;
	short m_outerCount;
};

void __cdecl Rva003249D2(GameWindow *window, bool update);

// ?Rva00324C61Layout@@YAXPAVGameWindow@@@Z present-unmatched
void __cdecl Rva00324C61Layout(GameWindow *window)
{
	int total = 0;
	Rva00324C61Data *data = (Rva00324C61Data *)window->winGetUserData();
	WinInstanceData *inst = window->winGetInstanceData();
	int outerIdx = 0;
	if (data->m_outerCount > 0)
	{
		for (; outerIdx < data->m_outerCount; outerIdx++)
		{
			if (data->m_cols[outerIdx].m_items == 0)
				continue;
			int curMax = 0;
			if (data->m_innerCount > 0)
			{
				for (int innerIdx = 0; innerIdx < data->m_innerCount; innerIdx++)
				{
					int cur = 0;
					int type = data->m_cols[outerIdx].m_items[innerIdx].m_type;
					if (type == 1)
					{
						unsigned int status = window->winGetStatus();
						if ((status & 0x4000) != 0)
							cur = TheWindowManager->getHeight(inst->m_font);
						else
						{
							Rva00324C61Obj *obj = data->m_cols[outerIdx].m_items[innerIdx].m_obj;
							if (obj != 0)
								obj->getItemHeight(0, &cur);
						}
					}
					else if (type == 2)
					{
						int h = data->m_cols[outerIdx].m_items[innerIdx].m_height;
						if (h <= 0)
							cur = TheWindowManager->getHeight(inst->m_font);
						else
							cur = h + 1;
					}
					if (cur > curMax)
						curMax = cur;
				}
			}
			data->m_cols[outerIdx].m_max = curMax;
			total += curMax + 1;
			data->m_cols[outerIdx].m_pos = total;
		}
	}
	data->m_total = total;
	Rva003249D2(window, true);
}
