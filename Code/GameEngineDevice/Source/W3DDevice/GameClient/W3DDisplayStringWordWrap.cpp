// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc /arch:SSE
/*
**	Command & Conquer Generals Zero Hour(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// W3DDisplayString text-state members, ported from Zero Hour's
// GameEngineDevice/Source/W3DDevice/GameClient/W3DDisplayString.cpp and the
// inline Render2DSentenceClass::Set_Wrapping_Width of WW3D2/render2dsentence.h
// (GeneralsMD tree vendored under reference/open-bfme-1/inputs/reference).
//
// Built on the BFME 2 layout of W3DDisplayStringComputeExtents.cpp (renderers
// at +0x14/+0xD8, m_textChanged at +0x1A0); the ZH-layout W3DDisplayString.cpp
// beside this file places them elsewhere. In the 0xC4-byte BFME 2
// Render2DSentenceClass the wrap width sits at +0x84 and the hard-wrap flag at
// +0xAE; GlobalLanguage::m_useHardWrap is at +0x24.

#include "unicode_string.h"

typedef bool Bool;
typedef int Int;
#define TRUE true
#define FALSE false

class GameFont;

struct GlobalLanguage
{
	char m_unrecovered00[ 0x24 ];
	Bool m_useHardWrap;																	///< 0x24
};
extern GlobalLanguage *TheGlobalLanguageData;

class DisplayString
{
public:
	virtual ~DisplayString();
	virtual void setText( UnicodeString text );
	virtual UnicodeString getText();
	virtual Int getTextLength();
	virtual void notifyTextChanged();
	virtual void reset();
protected:
	UnicodeString m_textString;
	GameFont *m_font;
	DisplayString *m_next;
	DisplayString *m_prev;
};

class Render2DSentenceClass
{
public:
	~Render2DSentenceClass();
	virtual void Reset();
	bool	Set_Wrapping_Width (float width)					{ if(WrapWidth == width)
																											return false;
																										WrapWidth = width; 
																										return true;	}
	void Set_Use_Hard_Word_Wrap( bool onoff ) { UseHardWordWrap = onoff; }
private:
	char m_unrecovered04[ 0x84 - 0x04 ];
	float WrapWidth;																		///< 0x84
	char m_unrecovered88[ 0xAE - 0x88 ];
	bool UseHardWordWrap;																///< 0xAE
	char m_unrecoveredAF[ 0xC4 - 0xAF ];
};

class W3DDisplayString : public DisplayString
{
public:
	virtual ~W3DDisplayString();
	virtual void notifyTextChanged();
	virtual void setWordWrap( Int wordWrap );
protected:
	void computeExtents();
private:
	Render2DSentenceClass m_textRenderer;								///< 0x14
	Render2DSentenceClass m_textRendererHotKey;					///< 0xD8
	UnicodeString m_hotkey;															///< 0x19C
	Bool m_textChanged;																	///< 0x1A0
};

//-------------------------------------------------------------------------------------------------
/** Text, font, or other attributes have changed, mark data as dirty */
//-------------------------------------------------------------------------------------------------
void W3DDisplayString::notifyTextChanged( void )
{

	if(TheGlobalLanguageData)
	{
		if(TheGlobalLanguageData->m_useHardWrap == TRUE)
		{
			m_textRenderer.Set_Use_Hard_Word_Wrap(true);
			m_textRendererHotKey.Set_Use_Hard_Word_Wrap(true);
		}
		else
		{
			m_textRenderer.Set_Use_Hard_Word_Wrap(false);
			m_textRendererHotKey.Set_Use_Hard_Word_Wrap(false);
		}
	}

	// get our new text extents
	computeExtents();

	//
	// set a flag so that if it comes that we need to render this string
	// we know we must first build the sentence
	//
	m_textChanged = TRUE;

	// reset data for our text renderer
	m_textRenderer.Reset();
	m_textRendererHotKey.Reset();

}  // end notifyTextChanged

//-------------------------------------------------------------------------------------------------
/** Set the width that we want to start wrapping text */
//-------------------------------------------------------------------------------------------------
void W3DDisplayString::setWordWrap( Int wordWrap )
{
	// set the Word Wrap
	if(m_textRenderer.Set_Wrapping_Width(wordWrap))
		notifyTextChanged();
}// void setWordWrap( Int wordWrap )
