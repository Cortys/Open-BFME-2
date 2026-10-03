// cl: /O1 /DNDEBUG /MD

// Text-color family from clean Open-BFME-1 6d9434269164392c5ba62aaa7c15a86b5b020d76.
// Retail independently proves four distinct color-pair stores and the
// ComboBox style-bit dispatch at GameWindow +0x3C. The paired helpers call
// the rowed winGetUserData provider and then the same setter on optional
// child pointers at data +0x2C and +0x28. Donor supplies semantic names;
// native boundaries, stores and reciprocal calls establish target ABI/offsets.
// Disabled helper intentionally gets user data before its null test, as retail does.

// GadgetComboBox small setters, retail 0x003226E7/0x00322703.
// Ported from Open-BFME-1 Code/GameEngine/Source/GameClient/GUI/Gadget/GadgetComboBox.cpp
// (BFME1 0x004B3980/0x004B39B0). ComboBoxData/EntryData keep their ZH order
// here; winGetUserData resolves through the ledger (no new pins).

typedef int Int;
typedef bool Bool;
typedef short Short;

class GameWindow;
class ListboxData;
class DisplayString;

struct EntryData
{
	DisplayString *text;
	DisplayString *sText;
	DisplayString *constructText;
	Bool secretText;
	Bool numericalOnly;
	Bool alphaNumericalOnly;
	Bool aSCIIOnly;
	Short maxTextLen;
	Bool receivedUnichar;
	Bool drawTextFromStart;
	GameWindow *constructList;
	unsigned short charPos;
	unsigned short conCharPos;
};

struct ComboBoxData
{
	Bool isEditable;
	Int maxDisplay;
	Int maxChars;
	Bool asciiOnly;
	Bool lettersAndNumbersOnly;
	ListboxData *listboxData;
	EntryData *entryData;
	Bool dontHide;
	Int entryCount;
	GameWindow *dropDownButton;
	GameWindow *editBox;
	GameWindow *listBox;
};

class GameWindow
{
public:
	void winSetEnabledTextColors(int, int);
	void winSetDisabledTextColors(int, int);
	void winSetHiliteTextColors(int, int);
	void winSetIMECompositeTextColors(int, int);
	void *winGetUserData(void);
};

#ifndef NULL
#define NULL 0
#endif

// ?GadgetComboBoxSetMaxChars@@YAXPAVGameWindow@@H@Z, retail 0x003226E7 (28B).
void GadgetComboBoxSetMaxChars(GameWindow *comboBox, Int maxChars)
{
	if (comboBox == NULL)
		return;

	ComboBoxData *comboData = (ComboBoxData *)comboBox->winGetUserData();
	comboData->maxChars = maxChars;
	comboData->entryData->maxTextLen = maxChars;
}

// ?GadgetComboBoxSetMaxDisplay@@YAXPAVGameWindow@@H@Z, retail 0x00322703 (17B).
void GadgetComboBoxSetMaxDisplay(GameWindow *comboBox, Int maxDisplay)
{
	ComboBoxData *comboData = (ComboBoxData *)comboBox->winGetUserData();
	comboData->maxDisplay = maxDisplay;
}

// ?GadgetComboBoxGetLength@@YAHPAVGameWindow@@@Z, retail 0x003229B1 (20B).
// Entry count lives at +0x20 (BFME ComboBoxData places the child windows at
// +0x24/+0x28/+0x2C); load by offset so the body matches retail.
Int GadgetComboBoxGetLength(GameWindow *comboBox)
{
	ComboBoxData *comboData = (ComboBoxData *)comboBox->winGetUserData();
	if (comboData)
		return *(Int *)((char *)comboData + 0x20);

	return 0;
}

// ?GadgetComboBoxSetEnabledTextColors@@YAXPAVGameWindow@@HH@Z present-unmatched
void GadgetComboBoxSetEnabledTextColors(GameWindow *comboBox, int color, int borderColor )
{
	// sanity
	if( comboBox == 0 )
		return;
	
	ComboBoxData *comboBoxData = (ComboBoxData *)comboBox->winGetUserData();
	GameWindow *listBox = *(GameWindow **)((char *)comboBoxData + 0x2c);
	if(listBox)
		listBox->winSetEnabledTextColors( color,borderColor);
	GameWindow *editBox = *(GameWindow **)((char *)comboBoxData + 0x28);
	if(editBox)
		editBox->winSetEnabledTextColors(color,borderColor);
}

// ?GadgetComboBoxSetDisabledTextColors@@YAXPAVGameWindow@@HH@Z present-unmatched
void GadgetComboBoxSetDisabledTextColors(GameWindow *comboBox, int color, int borderColor )
{
	ComboBoxData *comboBoxData = (ComboBoxData *)comboBox->winGetUserData();
	// sanity
	if( comboBox == 0 )
		return;

	GameWindow *listBox = *(GameWindow **)((char *)comboBoxData + 0x2C);
	if(listBox)
		listBox->winSetDisabledTextColors( color,borderColor);
	GameWindow *editBox = *(GameWindow **)((char *)comboBoxData + 0x28);
	if(editBox)
		editBox->winSetDisabledTextColors(color,borderColor);
}

// ?GadgetComboBoxSetHiliteTextColors@@YAXPAVGameWindow@@HH@Z present-unmatched
void GadgetComboBoxSetHiliteTextColors( GameWindow *comboBox,int color, int borderColor )
{
	// sanity
	if( comboBox == 0 )
		return;
	
	ComboBoxData *comboBoxData = (ComboBoxData *)comboBox->winGetUserData();
	
	GameWindow *listBox = *(GameWindow **)((char *)comboBoxData + 0x2C);
	if(listBox)
		listBox->winSetHiliteTextColors( color,borderColor);
	GameWindow *editBox = *(GameWindow **)((char *)comboBoxData + 0x28);
	if(editBox)
		editBox->winSetHiliteTextColors(color,borderColor);
}

// ?GadgetComboBoxSetIMECompositeTextColors@@YAXPAVGameWindow@@HH@Z present-unmatched
void GadgetComboBoxSetIMECompositeTextColors(GameWindow *comboBox, int color, int borderColor )
{
	// sanity
	if( comboBox == 0 )
		return;
	
	ComboBoxData *comboBoxData = (ComboBoxData *)comboBox->winGetUserData();

	GameWindow *listBox = *(GameWindow **)((char *)comboBoxData + 0x2C);
	if(listBox)
		listBox->winSetIMECompositeTextColors( color,borderColor);
	GameWindow *editBox = *(GameWindow **)((char *)comboBoxData + 0x28);
	if(editBox)
		editBox->winSetIMECompositeTextColors(color,borderColor);
}
