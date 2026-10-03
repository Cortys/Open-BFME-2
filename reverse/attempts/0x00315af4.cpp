// ?parseDefaultColor@@YA_NPAHPAVFile@@PAD@Z
// partial score=1.0 date=2026-10-03
// cl: /FIzh_ascii.h /Ireference/shims/bfme2_ascii_zh /Ireference/shims/bfme2_ascii /O1 /G7 /arch:SSE /MD /EHsc /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /DBFME_MODULE_NO_MPO /DZH_EMIT_POOL_GLUE /Ireference/shims/bfmerendobj /Ireference/shims/debugvtable /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/bfmeanimobj /Ireference/shims/indexbuffercount /Ireference/shims/bfmecaps /Ireference/shims/bfmehcanim /Ireference/shims/bfmevector /Ireference/shims/bfmemapper /Ireference/shims/meshmatdesclayout /Ireference/shims/bfmeshader /Ireference/shims/bfmecpudetect /Ireference/shims/bfmepool /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameNetwork /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWAudio /Ireference/shims/bfmealloc /Ireference/shims/bfmehashtable /Ireference/shims/bfmelist /Ireference/shims/asciistring_downloadmanager /Ireference/shims/stlp_nodealloc /Ireference/shims/asciistring_thin /ICode/GameEngine/Source/Common /Ireference/shims/w3droadbuffer /Ireference/shims/bfmeterraintracks /ICode/Libraries/Include/Lib /Ireference/shims
// stlport
// Evidence-only complete parser family, comment-trimmed to fit bank limit.
// Source: Code/GameEngine/Source/GameClient/GUI/GameWindowManagerScript.cpp;
// ZH via BFME1 6d9434269164392c5ba62aaa7c15a86b5b020d76; GPL-3.0-or-later,
// copyright 2025 Electronic Arts Inc. Original license is preserved upstream.
// Native font parser315B5E-315BA3 is exact69B with actual static caller family
// and File read+0C/scanString24 casts. Original isolated bank could not reproduce
// compiler's ESI/EBX live-ins. readUntilSemicolon is already rowed90B elsewhere;
// this full family emits89B (direct isspace vs native import), not a new recovery.
// Existing home unit has19 unresolved interfaces and9 wrong-selected dependencies;
// moving this whole family to another unit also duplicates its definitions. This bank
// proves body shape; do not land69 without preserving family ABI and link closure.
#include "PreRTS.h"
#include "Lib/BaseType.h"
#include "Common/Debug.h"
#include "Common/File.h"
#include "Common/FileSystem.h"
#include "Common/GameMemory.h"
#include "Common/NameKeyGenerator.h"
#include "Common/FunctionLexicon.h"
#include "GameClient/Display.h"
#include "GameClient/WindowLayout.h"
#include "GameClient/Gadget.h"
#include "GameClient/GameWindowManager.h"
#include "GameClient/GameWindowGlobal.h"
#include "GameClient/GadgetStaticText.h"
#include "GameClient/GadgetTabControl.h"
#include "GameClient/GadgetTextEntry.h"
#include "GameClient/GadgetPushButton.h"
#include "GameClient/GadgetRadioButton.h"
#include "GameClient/GadgetCheckBox.h"
#include "GameClient/GadgetListBox.h"
#include "GameClient/GadgetComboBox.h"
#include "GameClient/GadgetSlider.h"
#include "GameClient/GameText.h"
#include "GameClient/HeaderTemplate.h"
#ifdef _INTERNAL
#endif
enum
{
	WIN_BUFFER_LENGTH  = 2048,
	WIN_STACK_DEPTH    = 10,
};
struct LayoutScriptParse
{
	char *name;
	Bool (*parse)( char *token, char *buffer, UnsignedInt version, WindowLayoutInfo *info );
};
struct GameWindowParse
{
	char *name;
	Bool (*parse)( char *token, WinInstanceData *, char *, void * );
};
static GameWinSystemFunc		systemFunc = NULL;
static GameWinInputFunc		inputFunc = NULL;
static GameWinTooltipFunc	tooltipFunc = NULL;
static GameWinDrawFunc			drawFunc = NULL;
static AsciiString theSystemString;
static AsciiString theInputString;
static AsciiString theTooltipString;
static AsciiString theDrawString;
static Color defEnabledColor		= 0;
static Color defDisabledColor		= 0;
static Color defBackgroundColor	= 0;
static Color defHiliteColor			= 0;
static Color defSelectedColor		= 0;
static Color defTextColor				= 0;
static GameFont  *defFont				= NULL;
const char *WindowStatusNames[] = { "ACTIVE", "TOGGLE", "DRAGABLE", "ENABLED", "HIDDEN",
														  "ABOVE", "BELOW", "IMAGE", "TABSTOP", "NOINPUT",
														  "NOFOCUS", "DESTROYED", "BORDER",
														  "SMOOTH_TEXT", "ONE_LINE", "NO_FLUSH", "SEE_THRU",
															"RIGHT_CLICK", "WRAP_CENTERED", "CHECK_LIKE","HOTKEY_TEXT",
															"USE_OVERLAY_STATES", "NOT_READY", "FLASHING", "ALWAYS_COLOR",
															"ON_MOUSE_DOWN",
															NULL };
const char *WindowStyleNames[] = { "PUSHBUTTON",	"RADIOBUTTON",	"CHECKBOX",
														 "VERTSLIDER",	"HORZSLIDER",		"SCROLLLISTBOX",
														 "ENTRYFIELD",	"STATICTEXT",		"PROGRESSBAR",
														 "USER",				"MOUSETRACK",		"ANIMATED",
														 "TABSTOP",			"TABCONTROL",		"TABPANE",
														 "COMBOBOX",
														 NULL };
static GameWindow *windowStack[ WIN_STACK_DEPTH ];
static GameWindow **stackPtr;
static char *seps = " =;\n\r\t";
WinDrawData enabledDropDownButtonDrawData[ MAX_DRAW_DATA ];
WinDrawData disabledDropDownButtonDrawData[ MAX_DRAW_DATA ];
WinDrawData hiliteDropDownButtonDrawData[ MAX_DRAW_DATA ];
WinDrawData enabledEditBoxDrawData[ MAX_DRAW_DATA ];
WinDrawData disabledEditBoxDrawData[ MAX_DRAW_DATA ];
WinDrawData hiliteEditBoxDrawData[ MAX_DRAW_DATA ];
WinDrawData enabledListBoxDrawData[ MAX_DRAW_DATA ];
WinDrawData disabledListBoxDrawData[ MAX_DRAW_DATA ];
WinDrawData hiliteListBoxDrawData[ MAX_DRAW_DATA ];
WinDrawData enabledUpButtonDrawData[ MAX_DRAW_DATA ];
WinDrawData disabledUpButtonDrawData[ MAX_DRAW_DATA ];
WinDrawData hiliteUpButtonDrawData[ MAX_DRAW_DATA ];
WinDrawData enabledDownButtonDrawData[ MAX_DRAW_DATA ];
WinDrawData disabledDownButtonDrawData[ MAX_DRAW_DATA ];
WinDrawData hiliteDownButtonDrawData[ MAX_DRAW_DATA ];
WinDrawData enabledSliderDrawData[ MAX_DRAW_DATA ];
WinDrawData disabledSliderDrawData[ MAX_DRAW_DATA ];
WinDrawData hiliteSliderDrawData[ MAX_DRAW_DATA ];
WinDrawData enabledSliderThumbDrawData[ MAX_DRAW_DATA ];
WinDrawData disabledSliderThumbDrawData[ MAX_DRAW_DATA ];
WinDrawData hiliteSliderThumbDrawData[ MAX_DRAW_DATA ];
static GameWindow *parseWindow( File *inFile, char *buffer );
static Bool parseBitFlag( const char *flagString, UnsignedInt *bits,
													const char **flagList )
{
	const char **c;
	int i;
	for( i = 0, c = flagList; *c; i++, c++ )
	{
		if( !stricmp( *c, flagString ) )
		{
			*bits |= (1 << i);
			return TRUE;
		}
	}
	return FALSE;
}
static void parseBitString( const char *inBuffer, UnsignedInt *bits, const char **flagList )
{
	char buffer[256];
	char *tok;
	strcpy( buffer, inBuffer );
	if( strncmp( buffer, "NULL", 4 ) )
	{
		for( tok = strtok( buffer, "+" ); tok; tok = strtok( NULL, "+" ) )
		{
			if ( !parseBitFlag( tok, bits, flagList ) )
			{
				DEBUG_LOG(( "ParseBitString: Invalid flag '%s'.\n", tok ));
			}
		}
	}
}
class GoalScriptFileSlots {
public:
 virtual void s0(); virtual void s1(); virtual void close();
 virtual int read(void*,int); virtual int write(const void*,int);
 virtual int seek(int,int); virtual void nextLine(char*,int);
 virtual bool scanInt(int&); virtual bool scanReal(float&);
 virtual bool scanString(AsciiString&);
};
static void readUntilSemicolon( File *fp, char *buffer, int maxBufLen )
{
	int i = 0;
	Bool start = TRUE;
	while( i < maxBufLen )
	{
		((GoalScriptFileSlots*)fp)->read(buffer + i, 1);
		if( isspace( buffer[ i ] ) )
		{
			if( start == FALSE )
				buffer[ i++ ] = ' ';
		}
		else
		{
			start = FALSE;
			if( buffer[ i ] == ';' )
			{
				buffer[ i ] = '\000';
				return;
			}
			i++;
		}
	}
	DEBUG_LOG(( "ReadUntilSemicolon: ERROR - Read buffer overflow - input truncated.\n" ));
	buffer[ maxBufLen - 1 ] = '\000';
}
static Int scanBool( const char *source, Bool& val )
{
	Int temp = 0;
	Int ret = sscanf( source, "%d", &temp );
	val = (Bool)temp;
	return ret;
}
static Int scanShort( const char *source, Short& val )
{
	Int temp = 0;
	Int ret = sscanf( source, "%d", &temp );
	val = (Short)temp;
	return ret;
}
static Int scanInt( const char *source, Int& val )
{
	Int ret = sscanf( source, "%d", &val );
	return ret;
}
static Int scanUnsignedInt( const char *source, UnsignedInt& val )
{
	Int ret = sscanf( source, "%d", &val );
	return ret;
}
#pragma optimize("s", on)
static void resetWindowStack( void )
{
  memset( windowStack, 0, sizeof( windowStack ) );
  stackPtr = windowStack;
}
#pragma optimize("", on)
static void resetWindowDefaults( void )
{
	defEnabledColor = 0;
	defDisabledColor = 0;
	defBackgroundColor = 0;
	defHiliteColor = 0;
	defSelectedColor = 0;
	defTextColor = 0;
	defFont = 0;
}
GameWindow *peekWindow( void )
{
  if (stackPtr == windowStack)
    return NULL;
  return *(stackPtr - 1);
}
static GameWindow *popWindow( void )
{
  if( stackPtr == windowStack )
    return NULL;
  stackPtr--;
  return *stackPtr;
}
static void pushWindow( GameWindow *window )
{
  if( stackPtr == &windowStack[ WIN_STACK_DEPTH - 1 ] )
	{
    DEBUG_LOG(( "pushWindow: Warning, stack overflow\n" ));
    return;
  }
  *stackPtr++ = window;
}
static Bool parseColor( Color *color, char *buffer )
{
  char *c;
  Byte red, green, blue;
	c = strtok( buffer, " \t\n\r" );
  red = atoi(c);
	c = strtok( NULL, " \t\n\r" );
  green = atoi(c);
	c = strtok( NULL, " \t\n\r" );
  blue = atoi(c);
	*color = TheWindowManager->winMakeColor( red, green, blue, 255 );
  return TRUE;
}
static Bool parseDefaultColor( Color *color, File *inFile, char *buffer )
{
	AsciiString str;
	((GoalScriptFileSlots*)inFile)->scanString(str);
	readUntilSemicolon( inFile, buffer, WIN_BUFFER_LENGTH );
  if (!strcmp( buffer, "TRANSPARENT" ))
	{
		*color = WIN_COLOR_UNDEFINED;
	}
  else
    parseColor( color, buffer );
  return TRUE;
}
static Bool parseDefaultFont( GameFont *font, File *inFile, char *buffer )
{
	AsciiString str;
	((GoalScriptFileSlots*)inFile)->scanString(str);
	readUntilSemicolon( inFile, buffer, WIN_BUFFER_LENGTH );
	return TRUE;
}
static Bool parseTooltip( char *token, WinInstanceData *instData,
													char *buffer, void *data )
{
	UnicodeString tooltip;
	tooltip.set(L"Need tooltip translation");
	instData->setTooltipText( tooltip );
	return TRUE;
}
static Bool parseScreenRect( char *token, char *buffer,
														 Int *x, Int *y, Int *width, Int *height )
{
	GameWindow *parent = peekWindow();
	IRegion2D screenRegion;
	ICoord2D createRes;
	char *seps = " ,:=\n\r\t";
	char *c;
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanInt( c, screenRegion.lo.x );
	c = strtok( NULL, seps );
	scanInt( c, screenRegion.lo.y );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanInt( c, screenRegion.hi.x );
	c = strtok( NULL, seps );
	scanInt( c, screenRegion.hi.y );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanInt( c, createRes.x );
	c = strtok( NULL, seps );
	scanInt( c, createRes.y );
	Real xScale = (Real)TheDisplay->getWidth() / (Real)createRes.x;
	Real yScale = (Real)TheDisplay->getHeight() / (Real)createRes.y;
	screenRegion.lo.x = (Int)((Real)screenRegion.lo.x * xScale);
	screenRegion.lo.y = (Int)((Real)screenRegion.lo.y * yScale);
	screenRegion.hi.x = (Int)((Real)screenRegion.hi.x * xScale);
	screenRegion.hi.y = (Int)((Real)screenRegion.hi.y * yScale);
	if( parent )
	{
		ICoord2D parentScreenPos;
		parent->winGetScreenPosition( &parentScreenPos.x, &parentScreenPos.y );
		*x = screenRegion.lo.x - parentScreenPos.x;
		*y = screenRegion.lo.y - parentScreenPos.y;
	}
	else
	{
		*x = screenRegion.lo.x;
		*y = screenRegion.lo.y;
	}
	*width = screenRegion.hi.x - screenRegion.lo.x;
	*height = screenRegion.hi.y - screenRegion.lo.y;
	return TRUE;
}
static Bool parseImageOffset( char *token, WinInstanceData *instData,
															char *buffer, void *data )
{
  char *c;
	c = strtok( buffer, " \t\n\r" );
	instData->m_imageOffset.x = atoi( c );
	c = strtok( NULL, " \t\n\r" );
	instData->m_imageOffset.y = atoi( c );
  return TRUE;
}
static Bool parseFont( char *token, WinInstanceData *instData,
											 char *buffer, void *data )
{
	char *c, *ptr;
	char *seps = " ,\n\r\t";
	char *stringSeps = ":,\n\r\t\"";
	char fontName[ 256 ];
	Int fontSize;
	Int fontBold;
	c = strtok( buffer, seps );
	ptr = buffer;
	while( *ptr != '"' )
		ptr++;
	ptr++;
	c = strtok( ptr, stringSeps );
	strcpy( fontName, c );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanInt( c, fontSize );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanInt( c, fontBold );
	if( TheFontLibrary )
	{
		GameFont *font;
		font = TheFontLibrary->getFont( AsciiString(fontName), fontSize, fontBold );
		if( font )
			instData->m_font = font;
	}
	return TRUE;
}
static Bool parseName( char *token, WinInstanceData *instData,
											 char *buffer, void *data )
{
	char *c, *ptr;
	char *stringSeps = "\"";
	ptr = buffer;
	while( *ptr != '"' )
		ptr++;
	ptr++;
	c = strtok( ptr, stringSeps );
	instData->m_decoratedNameString = c;
	assert( TheNameKeyGenerator );
	if( TheNameKeyGenerator )
		instData->m_id = (Int)TheNameKeyGenerator->nameToKey( instData->m_decoratedNameString );
	return TRUE;
}
static Bool parseStatus( char *token, WinInstanceData *instData,
												 char *buffer, void *data )
{
  instData->m_status = 0;
  parseBitString( buffer, &instData->m_status, WindowStatusNames );
  return TRUE;
}
static Bool parseStyle( char *token, WinInstanceData *instData,
												char *buffer, void *data )
{
  instData->m_style = 0;
  parseBitString( buffer, &instData->m_style, WindowStyleNames );
  return TRUE;
}
static Bool parseSystemCallback( char *token, WinInstanceData *instData,
																 char *buffer, void *data )
{
	char *c, *ptr;
	char *stringSeps = "\"";
	ptr = buffer;
	while( *ptr != '"' )
		ptr++;
	ptr++;
	c = strtok( ptr, stringSeps );
	DEBUG_ASSERTCRASH( TheNameKeyGenerator && TheFunctionLexicon, ("Invalid singletons") );
	theSystemString = c;
	NameKeyType key = TheNameKeyGenerator->nameToKey( theSystemString );
	systemFunc = TheFunctionLexicon->gameWinSystemFunc( key );
	return TRUE;
}
static Bool parseInputCallback( char *token, WinInstanceData *instData,
																char *buffer, void *data )
{
	char *c, *ptr;
	char *stringSeps = "\"";
	ptr = buffer;
	while( *ptr != '"' )
		ptr++;
	ptr++;
	c = strtok( ptr, stringSeps );
	DEBUG_ASSERTCRASH( TheNameKeyGenerator && TheFunctionLexicon, ("Invalid singletons") );
	theInputString = c;
	NameKeyType key = TheNameKeyGenerator->nameToKey( theInputString );
	inputFunc = TheFunctionLexicon->gameWinInputFunc( key );
	return TRUE;
}
static Bool parseTooltipCallback( char *token, WinInstanceData *instData,
																  char *buffer, void *data )
{
	char *c, *ptr;
	char *stringSeps = "\"";
	ptr = buffer;
	while( *ptr != '"' )
		ptr++;
	ptr++;
	c = strtok( ptr, stringSeps );
	DEBUG_ASSERTCRASH( TheNameKeyGenerator && TheFunctionLexicon, ("Invalid singletons") );
	theTooltipString = c;
	NameKeyType key = TheNameKeyGenerator->nameToKey( theTooltipString );
	tooltipFunc = TheFunctionLexicon->gameWinTooltipFunc( key );
	return TRUE;
}
static Bool parseDrawCallback( char *token, WinInstanceData *instData,
															 char *buffer, void *data )
{
	char *c, *ptr;
	char *stringSeps = "\"";
	ptr = buffer;
	while( *ptr != '"' )
		ptr++;
	ptr++;
	c = strtok( ptr, stringSeps );
	DEBUG_ASSERTCRASH( TheNameKeyGenerator && TheFunctionLexicon, ("Invalid singletons") );
	theDrawString = c;
	NameKeyType key = TheNameKeyGenerator->nameToKey( theDrawString );
	drawFunc = TheFunctionLexicon->gameWinDrawFunc( key );
	return TRUE;
}
static Bool parseHeaderTemplate( char *token, WinInstanceData *instData,
															 char *buffer, void *data )
{
	char *c, *ptr;
	char *stringSeps = "\"";
	ptr = buffer;
	while( *ptr != '"' )
		ptr++;
	ptr++;
	c = strtok( ptr, stringSeps );
	DEBUG_ASSERTCRASH( TheNameKeyGenerator && TheFunctionLexicon, ("Invalid singletons") );
	instData->m_headerTemplateName = c;
	return TRUE;
}
static Bool parseListboxData( char *token, WinInstanceData *instData,
															char *buffer, void *data )
{
	ListboxData *listData = (ListboxData *)data;
	char *c;
	char *seps = " :,\n\r\t";
	c = strtok( buffer, seps );
	c = strtok( NULL, seps );
	scanShort( c, listData->listLength );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanBool( c, listData->autoScroll );
	c = strtok( NULL, seps );
	if ( !stricmp(c, "ScrollIfAtEnd") )
	{
		c = strtok( NULL, seps );
		scanBool( c, listData->scrollIfAtEnd );
		c = strtok( NULL, seps );
	}
	else
	{
		listData->scrollIfAtEnd = FALSE;
	}
	c = strtok( NULL, seps );
	scanBool( c, listData->autoPurge );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanBool( c, listData->scrollBar );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanBool( c, listData->multiSelect );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanShort( c, listData->columns );
	if(listData->columns > 1)
	{
		listData->columnWidthPercentage = NEW Int[listData->columns];
		for(Int i = 0; i < listData->columns; i++ )
		{
			c = strtok( NULL, seps );
			c = strtok( NULL, seps );
			scanInt( c, listData->columnWidthPercentage[i] );
		}
	}
	else
		listData->columnWidthPercentage = NULL;
	listData->columnWidth = NULL;
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanBool( c, listData->forceSelect );
	return TRUE;
}
static Bool parseComboBoxData( char *token, WinInstanceData *instData,
															char *buffer, void *data )
{
	ComboBoxData *comboData = (ComboBoxData *)data;
	char *c;
	char *seps = " :,\n\r\t";
	c = strtok( buffer, seps );
	c = strtok( NULL, seps );
  scanBool( c, comboData->isEditable );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
  scanInt( c, comboData->maxChars );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
  scanInt( c, comboData->maxDisplay );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
  scanBool( c, comboData->asciiOnly );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
  scanBool( c, comboData->lettersAndNumbersOnly );
  return TRUE;
}
static Bool parseSliderData( char *token, WinInstanceData *instData,
														 char *buffer, void *data )
{
	SliderData *sliderData = (SliderData *)data;
	char *c;
	char *seps = " :,\n\r\t";
	c = strtok( buffer, seps );
	c = strtok( NULL, seps );
	scanInt( c, sliderData->minVal );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanInt( c, sliderData->maxVal );
	return TRUE;
}
static Bool parseRadioButtonData( char *token, WinInstanceData *instData,
																	char *buffer, void *data )
{
	RadioButtonData *radioData = (RadioButtonData *)data;
	char *c;
	char *seps = " :,\n\r\t";
	c = strtok( buffer, seps );
	c = strtok( NULL, seps );
	scanInt( c, radioData->group );
	return TRUE;
}
static Bool parseTooltipText( char *token, WinInstanceData *instData,
											 char *buffer, void *data )
{
	char *ptr = buffer;
	char *c;
	char *stringSeps = "\n\r\t\"";
	while( *ptr != '"' )
		ptr++;
	ptr++;
	if(strlen( ptr ) == 1 )
		return TRUE;
	c = strtok( ptr, stringSeps );
	if( strlen( c ) >= MAX_TEXT_LABEL )
	{
		DEBUG_LOG(( "TextTooltip label '%s' is too long, max is '%d'\n", c, MAX_TEXT_LABEL ));
		assert( 0 );
		return FALSE;
	}
	instData->m_tooltipString.set(c);
	instData->setTooltipText(TheGameText->fetch(c));
  return TRUE;
}
static Bool parseTooltipDelay( char *token, WinInstanceData *instData,
																	char *buffer, void *data )
{
	char *c;
	char *seps = " :,\n\r\t";
	c = strtok( buffer, seps );
	scanInt( c, instData->m_tooltipDelay );
	return TRUE;
}
static Bool parseText( char *token, WinInstanceData *instData,
											 char *buffer, void *data )
{
	char *ptr = buffer;
	char *c;
	char *stringSeps = "\n\r\t\"";
	while( *ptr != '"' )
		ptr++;
	ptr++;
	c = strtok( ptr, stringSeps );
	if( strlen( c ) >= MAX_TEXT_LABEL )
	{
		DEBUG_LOG(( "Text label '%s' is too long, max is '%d'\n", c, MAX_TEXT_LABEL ));
		assert( 0 );
		return FALSE;
	}
	instData->m_textLabelString = c;
  return TRUE;
}
static Bool parseTextColor( char *token, WinInstanceData *instData,
														char *buffer, void *data )
{
	char *c;
	char *seps       = " :,\n\r\t";
	UnsignedInt r, g, b, a;
	Int i, states = 3;
	TextDrawData *textData;
	Bool first = TRUE;
	for( i = 0; i < states; i++ )
	{
		if( i == 0 )
			textData = &instData->m_enabledText;
		else if( i == 1 )
			textData = &instData->m_disabledText;
		else if( i == 2 )
			textData = &instData->m_hiliteText;
		else
		{
			DEBUG_LOG(( "Undefined state for text color\n" ));
			assert( 0 );
			return FALSE;
		}
		if( first == TRUE )
			c = strtok( buffer, seps );
		else
			c = strtok( NULL, seps );
		first = FALSE;
		c = strtok( NULL, seps );
		scanUnsignedInt( c, r );
		c = strtok( NULL, seps );
		scanUnsignedInt( c, g );
		c = strtok( NULL, seps );
		scanUnsignedInt( c, b );
		c = strtok( NULL, seps );
		scanUnsignedInt( c, a );
		textData->color = GameMakeColor( r, g, b, a );
		c = strtok( NULL, seps );
		c = strtok( NULL, seps );
		scanUnsignedInt( c, r );
		c = strtok( NULL, seps );
		scanUnsignedInt( c, g );
		c = strtok( NULL, seps );
		scanUnsignedInt( c, b );
		c = strtok( NULL, seps );
		scanUnsignedInt( c, a );
		textData->borderColor = GameMakeColor( r, g, b, a );
	}
	return TRUE;
}
static Bool parseStaticTextData( char *token, WinInstanceData *instData,
																 char *buffer, void *data )
{
	TextData *textData = (TextData *)data;
	char *c;
	char *seps       = " :,\n\r\t";
	c = strtok( buffer, seps );
	c = strtok( NULL, seps );
	scanBool( c, textData->centered );
	textData->centeredVertically = TRUE;
	textData->leftMargin = 7;
	textData->topMargin = 7;
	return TRUE;
}
static Bool parseTextEntryData( char *token, WinInstanceData *instData,
																char *buffer, void *data )
{
	EntryData *entryData = (EntryData *)data;
	char *c;
	char *seps       = " :,\n\r\t";
	c = strtok( buffer, seps );
	c = strtok( NULL, seps );
	scanShort( c, entryData->maxTextLen );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanBool( c, entryData->secretText );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanBool( c, entryData->numericalOnly );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanBool( c, entryData->alphaNumericalOnly );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanBool( c, entryData->aSCIIOnly );
	return TRUE;
}
static Bool parseTabControlData( char *token, WinInstanceData *instData,
																char *buffer, void *data )
{
	TabControlData *tabControlData = (TabControlData *)data;
	char *c;
	char *seps       = " :,\n\r\t";
	c = strtok( buffer, seps );
	c = strtok( NULL, seps );
	scanInt( c, tabControlData->tabOrientation );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanInt( c, tabControlData->tabEdge );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanInt( c, tabControlData->tabWidth );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanInt( c, tabControlData->tabHeight );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanInt( c, tabControlData->tabCount );
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanInt( c, tabControlData->paneBorder );
	Int entryCount = 0;
	c = strtok( NULL, seps );
	c = strtok( NULL, seps );
	scanInt( c, entryCount );
	for( Int paneIndex = 0; paneIndex < entryCount; paneIndex ++ )
	{
		c = strtok( NULL, seps );
		scanBool( c, tabControlData->subPaneDisabled[paneIndex] );
	}
	return TRUE;
}
static Bool parseDrawData( char *token, WinInstanceData *instData,
													 char *buffer, void *data )
{
	Int i;
	UnsignedInt r, g, b, a;
	WinDrawData *drawData;
	Bool first = TRUE;
	char *c;
	char *seps       = " :,\n\r\t";
	for( i = 0; i < MAX_DRAW_DATA; i++ )
	{
		if( strcmp( token, "ENABLEDDRAWDATA" ) == 0 )
			drawData = &instData->m_enabledDrawData[ i ];
		else if( strcmp( token, "DISABLEDDRAWDATA" ) == 0 )
			drawData = &instData->m_disabledDrawData[ i ];
		else if( strcmp( token, "HILITEDRAWDATA" ) == 0 )
			drawData = &instData->m_hiliteDrawData[ i ];
		else if( strcmp( token, "LISTBOXENABLEDUPBUTTONDRAWDATA" ) == 0 )
			drawData = &enabledUpButtonDrawData[ i ];
		else if( strcmp( token, "LISTBOXDISABLEDUPBUTTONDRAWDATA" ) == 0 )
			drawData = &disabledUpButtonDrawData[ i ];
		else if( strcmp( token, "LISTBOXHILITEUPBUTTONDRAWDATA" ) == 0 )
			drawData = &hiliteUpButtonDrawData[ i ];
		else if( strcmp( token, "LISTBOXENABLEDDOWNBUTTONDRAWDATA" ) == 0 )
			drawData = &enabledDownButtonDrawData[ i ];
		else if( strcmp( token, "LISTBOXDISABLEDDOWNBUTTONDRAWDATA" ) == 0 )
			drawData = &disabledDownButtonDrawData[ i ];
		else if( strcmp( token, "LISTBOXHILITEDOWNBUTTONDRAWDATA" ) == 0 )
			drawData = &hiliteDownButtonDrawData[ i ];
		else if( strcmp( token, "LISTBOXENABLEDSLIDERDRAWDATA" ) == 0 )
			drawData = &enabledSliderDrawData[ i ];
		else if( strcmp( token, "LISTBOXDISABLEDSLIDERDRAWDATA" ) == 0 )
			drawData = &disabledSliderDrawData[ i ];
		else if( strcmp( token, "LISTBOXHILITESLIDERDRAWDATA" ) == 0 )
			drawData = &hiliteSliderDrawData[ i ];
		else if( strcmp( token, "SLIDERTHUMBENABLEDDRAWDATA" ) == 0 )
			drawData = &enabledSliderThumbDrawData[ i ];
		else if( strcmp( token, "SLIDERTHUMBDISABLEDDRAWDATA" ) == 0 )
			drawData = &disabledSliderThumbDrawData[ i ];
		else if( strcmp( token, "SLIDERTHUMBHILITEDRAWDATA" ) == 0 )
			drawData = &hiliteSliderThumbDrawData[ i ];
		else if( strcmp( token, "COMBOBOXDROPDOWNBUTTONENABLEDDRAWDATA" ) == 0 )
			drawData = &enabledDropDownButtonDrawData[ i ];
		else if( strcmp( token, "COMBOBOXDROPDOWNBUTTONDISABLEDDRAWDATA" ) == 0 )
			drawData = &disabledDropDownButtonDrawData[ i ];
		else if( strcmp( token, "COMBOBOXDROPDOWNBUTTONHILITEDRAWDATA" ) == 0 )
			drawData = &hiliteDropDownButtonDrawData[ i ];
		else if( strcmp( token, "COMBOBOXEDITBOXENABLEDDRAWDATA" ) == 0 )
			drawData = &enabledEditBoxDrawData[ i ];
		else if( strcmp( token, "COMBOBOXEDITBOXDISABLEDDRAWDATA" ) == 0 )
			drawData = &disabledEditBoxDrawData[ i ];
		else if( strcmp( token, "COMBOBOXEDITBOXHILITEDRAWDATA" ) == 0 )
			drawData = &hiliteEditBoxDrawData[ i ];
		else if( strcmp( token, "COMBOBOXLISTBOXENABLEDDRAWDATA" ) == 0 )
			drawData = &enabledListBoxDrawData[ i ];
		else if( strcmp( token, "COMBOBOXLISTBOXDISABLEDDRAWDATA" ) == 0 )
			drawData = &disabledListBoxDrawData[ i ];
		else if( strcmp( token, "COMBOBOXLISTBOXHILITEDRAWDATA" ) == 0 )
			drawData = &hiliteListBoxDrawData[ i ];
		else
		{
			DEBUG_LOG(( "ParseDrawData, undefined token '%s'\n", token ));
			assert( 0 );
			return FALSE;
		}
		if( first == TRUE )
			c = strtok( buffer, seps );
		else
			c = strtok( NULL, seps );
		first = FALSE;
		c = strtok( NULL, seps );
		if( strcmp( c, "NoImage" ) )
			drawData->image = TheMappedImageCollection->findImageByName( AsciiString( c ) );
		else
			drawData->image = NULL;
		c = strtok( NULL, seps );
		c = strtok( NULL, seps );
		scanUnsignedInt( c, r );
		c = strtok( NULL, seps );
		scanUnsignedInt( c, g );
		c = strtok( NULL, seps );
		scanUnsignedInt( c, b );
		c = strtok( NULL, seps );
		scanUnsignedInt( c, a );
		drawData->color = GameMakeColor( r, g, b, a );
		c = strtok( NULL, seps );
		c = strtok( NULL, seps );
		scanUnsignedInt( c, r );
		c = strtok( NULL, seps );
		scanUnsignedInt( c, g );
		c = strtok( NULL, seps );
		scanUnsignedInt( c, b );
		c = strtok( NULL, seps );
		scanUnsignedInt( c, a );
		drawData->borderColor = GameMakeColor( r, g, b, a );
	}
	return TRUE;
}
void *getDataTemplate( char *type )
{
  static EntryData eData;
  static SliderData sData;
  static ListboxData lData;
  static TextData tData;
	static RadioButtonData rData;
	static TabControlData tcData;
	static ComboBoxData	cData;
	void *data;
  if( !strcmp( type, "VERTSLIDER" ) || !strcmp( type, "HORZSLIDER" ) )
	{
    memset( &sData, 0, sizeof( SliderData ) );
    data = &sData;
  }
	else if( !strcmp( type, "SCROLLLISTBOX" ) )
	{
    memset( &lData, 0, sizeof( ListboxData ) );
    data = &lData;
  }
	else if( !strcmp( type, "TABCONTROL" ) )
	{
    memset( &tcData, 0, sizeof( TabControlData ) );
    data = &tcData;
  }
	else if( !strcmp( type, "ENTRYFIELD" ) )
	{
    memset( &eData, 0, sizeof( EntryData ) );
    data = &eData;
  }
	else if( !strcmp( type, "STATICTEXT" ) )
	{
		memset( &tData, 0, sizeof( TextData ) );
		data = &tData;
  }
	else if( !strcmp( type, "RADIOBUTTON" ) )
	{
		memset( &rData, 0, sizeof( RadioButtonData ) );
		data = &rData;
	}
	else if( !strcmp( type, "COMBOBOX" ) )
	{
		memset( &cData, 0, sizeof( ComboBoxData ) );
		data = &cData;
	}
	else
    data = NULL;
  return data;
}
static Bool parseData( void **data, char *type, char *buffer )
{
  char *c;
  static EntryData eData;
  static SliderData sData;
  static ListboxData lData;
  static TextData tData;
	static RadioButtonData rData;
	static ComboBoxData cData;
  if( !strcmp( type, "VERTSLIDER" ) || !strcmp( type, "HORZSLIDER" ) )
	{
    memset( &sData, 0, sizeof( SliderData ) );
	  c = strtok( buffer, " \t\n\r" );
    sData.minVal = atoi(c);
	  c = strtok( NULL, " \t\n\r" );
    sData.maxVal = atoi(c);
    *data = &sData;
  }
	else if( !strcmp( type, "SCROLLLISTBOX" ) )
	{
    memset( &lData, 0, sizeof( ListboxData ) );
	  c = strtok( buffer, " \t\n\r" );
    lData.listLength = atoi(c);
	  c = strtok( NULL, " \t\n\r" );
    lData.autoScroll = atoi(c);
	  c = strtok( NULL, " \t\n\r" );
    lData.autoPurge = atoi(c);
	  c = strtok( NULL, " \t\n\r" );
    lData.scrollBar = atoi(c);
	  c = strtok( NULL, " \t\n\r" );
    lData.multiSelect = atoi(c);
		c = strtok( NULL, " \t\n\r" );
		lData.forceSelect = atoi(c);
    *data = &lData;
  }
	else if( !strcmp( type, "ENTRYFIELD" ) )
	{
    memset( &eData, 0, sizeof( EntryData ) );
	  c = strtok( buffer, " \t\n\r" );
    eData.maxTextLen = atoi(c);
	  c = strtok( NULL, " \t\n\r" );
		c = strtok( NULL, " \t\n\r" );
		if (c)
		{
			eData.secretText = atoi(c);
			if( eData.secretText != FALSE )
				eData.secretText = TRUE;
		}
		else
			eData.secretText = FALSE;
		c = strtok( NULL, " \t\n\r" );
		if (c)
		{
			eData.numericalOnly = ( atoi(c) == 1 );
			eData.alphaNumericalOnly = ( atoi(c) == 2 );
			eData.aSCIIOnly = ( atoi(c) == 3 );
		}
		else
		{
			eData.numericalOnly = FALSE;
			eData.alphaNumericalOnly = FALSE;
			eData.aSCIIOnly = FALSE;
		}
    *data = &eData;
  }
	else if( !strcmp( type, "STATICTEXT" ) )
	{
	  c = strtok( buffer, " \t\n\r" );
    tData.centered = atoi(c);
		if( tData.centered != FALSE )
			tData.centered = TRUE;
	  c = strtok( NULL, " \t\n\r" );
		*data = &tData;
  }
	else if( !strcmp( type, "RADIOBUTTON" ) )
	{
		c = strtok( buffer, " \t\n\r" );
		rData.group = atoi(c);
		*data = &rData;
	}
	else
    *data = NULL;
  return TRUE;
}
static void setWindowText( GameWindow *window, AsciiString textLabel )
{
	if (textLabel.isEmpty())
		return;
	UnicodeString theText, entryText;
	theText = TheGameText->fetch( (char *)textLabel.str());
	if( BitTest( window->winGetStyle(), GWS_PUSH_BUTTON ) )
		GadgetButtonSetText( window, theText );
	else if( BitTest( window->winGetStyle(), GWS_RADIO_BUTTON ) )
		GadgetRadioSetText( window, theText );
	else if( BitTest( window->winGetStyle(), GWS_CHECK_BOX ) )
		GadgetCheckBoxSetText( window, theText );
	else if( BitTest( window->winGetStyle(), GWS_STATIC_TEXT ) )
		GadgetStaticTextSetText( window, theText );
	else if( BitTest( window->winGetStyle(), GWS_ENTRY_FIELD ) )
	{
		entryText.translate(textLabel);
		GadgetTextEntrySetText( window, entryText );
	}
	else
		window->winSetText( theText );
}
static GameWindow *createGadget( char *type,
																 GameWindow *parent,
																 Int status,
																 Int x, Int y,
																 Int width, Int height,
																 WinInstanceData *instData,
																 void *data )
{
  GameWindow *window;
  instData->m_owner = parent;
  if( !strcmp( type, "PUSHBUTTON" ) )
	{
    instData->m_style |= GWS_PUSH_BUTTON;
    window = TheWindowManager->gogoGadgetPushButton( parent, status, x, y,
																										 width, height,
																										 instData,
																										 instData->m_font, FALSE );
  }
	else if( !strcmp( type, "RADIOBUTTON" ) )
	{
		RadioButtonData *rData = (RadioButtonData *)data;
		char filename[ MAX_WINDOW_NAME_LEN ];
		char *c;
		strcpy( filename, instData->m_decoratedNameString.str() );
		c = strchr( filename, ':' );
		if( c )
			*c = 0;
		assert( TheNameKeyGenerator );
		if( TheNameKeyGenerator )
			rData->screen = (Int)(TheNameKeyGenerator->nameToKey( AsciiString(filename) ));
    instData->m_style |= GWS_RADIO_BUTTON;
    window = TheWindowManager->gogoGadgetRadioButton( parent, status, x, y,
																											width, height,
																											instData, rData,
																											instData->m_font, FALSE );
  }
	else if( !strcmp( type, "CHECKBOX" ) )
	{
    instData->m_style |= GWS_CHECK_BOX;
    window = TheWindowManager->gogoGadgetCheckbox( parent, status, x, y,
																									 width, height,
																									 instData,
																									 instData->m_font, FALSE );
  }
	else if( !strcmp( type, "TABCONTROL" ) )
	{
		TabControlData *tcData = (TabControlData *)data;
    instData->m_style |= GWS_TAB_CONTROL;
    window = TheWindowManager->gogoGadgetTabControl( parent, status, x, y,
																										width, height,
																										instData, tcData,
																										instData->m_font, FALSE );
	}
	else if( !strcmp( type, "VERTSLIDER" ) )
	{
    SliderData *sData = (SliderData *)data;
    instData->m_style |= GWS_VERT_SLIDER;
    window = TheWindowManager->gogoGadgetSlider( parent, status, x, y,
																								 width, height,
																								 instData, sData,
																								 instData->m_font, FALSE );
		GameWindow *thumb = window->winGetChild();
		if( thumb )
		{
			WinInstanceData *instData = thumb->winGetInstanceData();
			for( Int i = 0; i < MAX_DRAW_DATA; i++ )
			{
				instData->m_enabledDrawData[ i ] = enabledSliderThumbDrawData[ i ];
				instData->m_disabledDrawData[ i ] = disabledSliderThumbDrawData[ i ];
				instData->m_hiliteDrawData[ i ] = hiliteSliderThumbDrawData[ i ];
			}
		}
  }
	else if( !strcmp( type, "HORZSLIDER" ) )
	{
    SliderData *sData = (SliderData *)data;
    instData->m_style |= GWS_HORZ_SLIDER;
    window = TheWindowManager->gogoGadgetSlider( parent, status, x, y,
																								 width, height,
																								 instData, sData,
																								 instData->m_font, FALSE );
		GameWindow *thumb = window->winGetChild();
		if( thumb )
		{
			WinInstanceData *instData = thumb->winGetInstanceData();
			for( Int i = 0; i < MAX_DRAW_DATA; i++ )
			{
				instData->m_enabledDrawData[ i ] = enabledSliderThumbDrawData[ i ];
				instData->m_disabledDrawData[ i ] = disabledSliderThumbDrawData[ i ];
				instData->m_hiliteDrawData[ i ] = hiliteSliderThumbDrawData[ i ];
			}
		}
  }
	else if( !strcmp( type, "SCROLLLISTBOX" ) )
	{
    ListboxData *lData = (ListboxData *)data;
    instData->m_style |= GWS_SCROLL_LISTBOX;
    window = TheWindowManager->gogoGadgetListBox( parent, status, x, y,
																									width, height,
																									instData, lData,
																									instData->m_font, FALSE );
		GameWindow *upButton = GadgetListBoxGetUpButton( window );
		if( upButton )
		{
			WinInstanceData *instData = upButton->winGetInstanceData();
			for( Int i = 0; i < MAX_DRAW_DATA; i++ )
			{
				instData->m_enabledDrawData[ i ] = enabledUpButtonDrawData[ i ];
				instData->m_disabledDrawData[ i ] = disabledUpButtonDrawData[ i ];
				instData->m_hiliteDrawData[ i ] = hiliteUpButtonDrawData[ i ];
			}
		}
		GameWindow *downButton = GadgetListBoxGetDownButton( window );
		if( downButton )
		{
			WinInstanceData *instData = downButton->winGetInstanceData();
			for( Int i = 0; i < MAX_DRAW_DATA; i++ )
			{
				instData->m_enabledDrawData[ i ] = enabledDownButtonDrawData[ i ];
				instData->m_disabledDrawData[ i ] = disabledDownButtonDrawData[ i ];
				instData->m_hiliteDrawData[ i ] = hiliteDownButtonDrawData[ i ];
			}
		}
		GameWindow *slider = GadgetListBoxGetSlider( window );
		if( slider )
		{
			WinInstanceData *instData = slider->winGetInstanceData();
			for( Int i = 0; i < MAX_DRAW_DATA; i++ )
			{
				instData->m_enabledDrawData[ i ] = enabledSliderDrawData[ i ];
				instData->m_disabledDrawData[ i ] = disabledSliderDrawData[ i ];
				instData->m_hiliteDrawData[ i ] = hiliteSliderDrawData[ i ];
			}
			GameWindow *thumb = slider->winGetChild();
			if( thumb )
			{
				WinInstanceData *instData = thumb->winGetInstanceData();
				for( Int i = 0; i < MAX_DRAW_DATA; i++ )
				{
					instData->m_enabledDrawData[ i ] = enabledSliderThumbDrawData[ i ];
					instData->m_disabledDrawData[ i ] = disabledSliderThumbDrawData[ i ];
					instData->m_hiliteDrawData[ i ] = hiliteSliderThumbDrawData[ i ];
				}
			}
		}
  }
	else if( !strcmp( type, "COMBOBOX" ) )
	{
		ComboBoxData *cData = (ComboBoxData *)data;
		cData->entryData = NEW EntryData;
		memset ( cData->entryData, 0, sizeof(EntryData));
		cData->listboxData = NEW ListboxData;
		memset ( cData->listboxData, 0, sizeof(ListboxData));
		cData->entryCount = 0;
		cData->entryData->aSCIIOnly = cData->asciiOnly;
		cData->entryData->alphaNumericalOnly = cData->lettersAndNumbersOnly;
		cData->entryData->maxTextLen = cData->maxChars;
		cData->listboxData->listLength = 10;
		cData->listboxData->autoScroll = 0;
		cData->listboxData->scrollIfAtEnd = FALSE;
		cData->listboxData->autoPurge = 0;
		cData->listboxData->scrollBar = 1;
		cData->listboxData->multiSelect = 0;
		cData->listboxData->forceSelect = 1;
		cData->listboxData->columns = 1;
		cData->listboxData->columnWidth = NULL;
		cData->listboxData->columnWidthPercentage = NULL;
    instData->m_style |= GWS_COMBO_BOX;
    window = TheWindowManager->gogoGadgetComboBox( parent, status, x, y,
																									width, height,
																									instData, cData,
																									instData->m_font, FALSE );
		GameWindow *dropDownButton = GadgetComboBoxGetDropDownButton( window );
		if( dropDownButton )
		{
			WinInstanceData *instData = dropDownButton->winGetInstanceData();
			for( Int i = 0; i < MAX_DRAW_DATA; i++ )
			{
				instData->m_enabledDrawData[ i ] = enabledDropDownButtonDrawData[ i ];
				instData->m_disabledDrawData[ i ] = disabledDropDownButtonDrawData[ i ];
				instData->m_hiliteDrawData[ i ] = hiliteDropDownButtonDrawData[ i ];
			}
		}
		GameWindow *editBox = GadgetComboBoxGetEditBox( window );
		if( editBox )
		{
			WinInstanceData *instData = editBox->winGetInstanceData();
			for( Int i = 0; i < MAX_DRAW_DATA; i++ )
			{
				instData->m_enabledDrawData[ i ] = enabledEditBoxDrawData[ i ];
				instData->m_disabledDrawData[ i ] = disabledEditBoxDrawData[ i ];
				instData->m_hiliteDrawData[ i ] = hiliteEditBoxDrawData[ i ];
			}
		}
		GameWindow *listBox = GadgetComboBoxGetListBox( window );
		if( listBox )
		{
			WinInstanceData *instData = listBox->winGetInstanceData();
			for( Int i = 0; i < MAX_DRAW_DATA; i++ )
			{
				instData->m_enabledDrawData[ i ] = enabledListBoxDrawData[ i ];
				instData->m_disabledDrawData[ i ] = disabledListBoxDrawData[ i ];
				instData->m_hiliteDrawData[ i ] = hiliteListBoxDrawData[ i ];
			}
			GameWindow *upButton = GadgetListBoxGetUpButton( listBox );
			if( upButton )
			{
				WinInstanceData *instData = upButton->winGetInstanceData();
				for( Int i = 0; i < MAX_DRAW_DATA; i++ )
				{
					instData->m_enabledDrawData[ i ] = enabledUpButtonDrawData[ i ];
					instData->m_disabledDrawData[ i ] = disabledUpButtonDrawData[ i ];
					instData->m_hiliteDrawData[ i ] = hiliteUpButtonDrawData[ i ];
				}
			}
			GameWindow *downButton = GadgetListBoxGetDownButton( listBox );
			if( downButton )
			{
				WinInstanceData *instData = downButton->winGetInstanceData();
				for( Int i = 0; i < MAX_DRAW_DATA; i++ )
				{
					instData->m_enabledDrawData[ i ] = enabledDownButtonDrawData[ i ];
					instData->m_disabledDrawData[ i ] = disabledDownButtonDrawData[ i ];
					instData->m_hiliteDrawData[ i ] = hiliteDownButtonDrawData[ i ];
				}
			}
			GameWindow *slider = GadgetListBoxGetSlider( listBox );
			if( slider )
			{
				WinInstanceData *instData = slider->winGetInstanceData();
				for( Int i = 0; i < MAX_DRAW_DATA; i++ )
				{
					instData->m_enabledDrawData[ i ] = enabledSliderDrawData[ i ];
					instData->m_disabledDrawData[ i ] = disabledSliderDrawData[ i ];
					instData->m_hiliteDrawData[ i ] = hiliteSliderDrawData[ i ];
				}
				GameWindow *thumb = slider->winGetChild();
				if( thumb )
				{
					WinInstanceData *instData = thumb->winGetInstanceData();
					for( Int i = 0; i < MAX_DRAW_DATA; i++ )
					{
						instData->m_enabledDrawData[ i ] = enabledSliderThumbDrawData[ i ];
						instData->m_disabledDrawData[ i ] = disabledSliderThumbDrawData[ i ];
						instData->m_hiliteDrawData[ i ] = hiliteSliderThumbDrawData[ i ];
					}
				}
			}
		}
  }
	else if( !strcmp( type, "ENTRYFIELD" ) )
	{
    EntryData *eData = (EntryData *)data;
    instData->m_style |= GWS_ENTRY_FIELD;
    window = TheWindowManager->gogoGadgetTextEntry( parent, status, x, y,
																										width, height,
																										instData, eData,
																										instData->m_font, FALSE );
  }
	else if( !strcmp( type, "STATICTEXT" ) )
	{
    TextData *tData = (TextData *)data;
    instData->m_style |= GWS_STATIC_TEXT;
    window = TheWindowManager->gogoGadgetStaticText( parent, status, x, y,
																										 width, height,
																										 instData, tData,
																										 instData->m_font, FALSE );
  }
	else if( !strcmp( type, "PROGRESSBAR" ) )
	{
    instData->m_style |= GWS_PROGRESS_BAR;
    window = TheWindowManager->gogoGadgetProgressBar( parent, status, x, y,
																											width, height,
																											instData,
																											instData->m_font, FALSE );
  }
  return window;
}
static GameWindow *createWindow( char *type,
																 Int id,
																 Int status,
																 Int x, Int y,
																 Int width, Int height,
																 WinInstanceData *instData,
																 void *data,
																 GameWinSystemFunc system,
																 GameWinInputFunc input,
																 GameWinTooltipFunc tooltip,
																 GameWinDrawFunc draw )
{
  GameWindow *window, *parent;
  parent = peekWindow();
  if( !strcmp( type, "USER" ) )
	{
    window = TheWindowManager->winCreate( parent,
																					status, x, y,
																					width, height,
																					system );
		if( window )
		{
			instData->m_style |= GWS_USER_WINDOW;
			window->winSetInstanceData( instData );
			window->winSetWindowId( id );
		}
  }
	else if( !strcmp( type, "TABPANE" ) )
	{
    window = TheWindowManager->winCreate( parent,
																					status, x, y,
																					width, height,
																					system );
		if( window )
		{
			instData->m_style |= GWS_TAB_PANE;
			window->winSetInstanceData( instData );
			window->winSetWindowId( id );
		}
  }
	else
	{
    window = createGadget( type,
													 parent,
													 status,
													 x, y,
													 width, height,
                           instData,
													 data );
		if( window )
		{
			window->winSetWindowId( id );
		}
  }
	if( window )
	{
		if( system )
			window->winSetSystemFunc( system );
		if( input )
			window->winSetInputFunc( input );
		if( tooltip )
			window->winSetTooltipFunc( tooltip );
		if( draw )
			window->winSetDrawFunc( draw );
		GameWindowEditData *editData = window->winGetEditData();
		if( editData )
		{
			editData->systemCallbackString = theSystemString;
			editData->inputCallbackString = theInputString;
			editData->tooltipCallbackString = theTooltipString;
			editData->drawCallbackString = theDrawString;
		}
	}
	if( window )
	{
		setWindowText( window, instData->m_textLabelString );
	}
  if( window && parent )
		TheWindowManager->winSendInputMsg( parent, GWM_SCRIPT_CREATE, id, 0 );
  return window;
}
static Bool parseChildWindows( GameWindow *window,
															 File *inFile,
															 char *buffer )
{
  GameWindow *lastWindow;
	AsciiString asciibuf;
	if( BitTest( window->winGetStyle(), GWS_TAB_CONTROL ) )
	{
		GameWindow *nextWindow = NULL;
		for( GameWindow *myChild = window->winGetChild(); myChild; myChild = nextWindow )
		{
			nextWindow = myChild->winGetNext();
			TheWindowManager->winDestroy( myChild );
		}
	}
  pushWindow( window );
	while( TRUE )
	{
		if (((GoalScriptFileSlots*)inFile)->scanString(asciibuf) == FALSE) {
			break;
		}
		if (asciibuf.compare("ENDALLCHILDREN") == 0) {
			break;
		}
		if (asciibuf.compare("END") == 0) {
      break;
		}
		if (asciibuf.compare("ENABLEDCOLOR") == 0)
		{
			if( parseDefaultColor( &defEnabledColor, inFile, buffer ) == FALSE )
			{
				return FALSE;
			}
		}
		else if (asciibuf.compare("DISABLEDCOLOR") == 0)
		{
			if( parseDefaultColor( &defDisabledColor, inFile, buffer ) == FALSE )
			{
				return FALSE;
			}
		}
		else if (asciibuf.compare("HILITECOLOR") == 0)
		{
			if( parseDefaultColor( &defHiliteColor, inFile, buffer ) == FALSE )
			{
				return FALSE;
			}
		}
		else if (asciibuf.compare("SELECTEDCOLOR") == 0)
		{
			if( parseDefaultColor( &defSelectedColor, inFile, buffer ) == FALSE )
			{
				return FALSE;
			}
		}
		else if (asciibuf.compare("TEXTCOLOR") == 0)
		{
			if( parseDefaultColor( &defTextColor, inFile, buffer ) == FALSE )
			{
				return FALSE;
			}
		}
		else if (asciibuf.compare("WINDOW") == 0)
		{
			if( parseWindow( inFile, buffer ) == NULL )
			{
				return FALSE;
			}
		}
	}
  lastWindow = popWindow();
  if( lastWindow != window )
	{
    DEBUG_LOG(( "parseChildWindows: unmatched window on stack.  Corrupt stack or bad source\n" ));
    return FALSE;
  }
	if( BitTest( window->winGetStyle(), GWS_TAB_CONTROL ) )
		GadgetTabControlFixupSubPaneList( window );
  return TRUE;
}
static GameWindowParse gameWindowFieldList[] =
{
	{ "NAME", parseName },
	{ "STATUS", parseStatus },
	{ "STYLE", parseStyle },
	{ "SYSTEMCALLBACK", parseSystemCallback },
	{ "INPUTCALLBACK", parseInputCallback },
	{ "TOOLTIPCALLBACK", parseTooltipCallback },
	{ "DRAWCALLBACK", parseDrawCallback },
	{ "FONT", parseFont },
	{ "HEADERTEMPLATE", parseHeaderTemplate },
	{ "LISTBOXDATA", parseListboxData },
	{ "COMBOBOXDATA", parseComboBoxData },
	{ "SLIDERDATA", parseSliderData },
	{ "RADIOBUTTONDATA", parseRadioButtonData },
	{	"TOOLTIPTEXT", parseTooltipText },
  { "TOOLTIPDELAY", parseTooltipDelay },
	{ "TEXT", parseText },
	{ "TEXTCOLOR", parseTextColor },
	{ "STATICTEXTDATA", parseStaticTextData },
	{ "TEXTENTRYDATA", parseTextEntryData },
	{ "TABCONTROLDATA", parseTabControlData },
	{ "ENABLEDDRAWDATA", parseDrawData },
	{ "DISABLEDDRAWDATA", parseDrawData },
	{ "HILITEDRAWDATA", parseDrawData },
	{ "LISTBOXENABLEDUPBUTTONDRAWDATA", parseDrawData },
	{ "LISTBOXENABLEDDOWNBUTTONDRAWDATA", parseDrawData },
	{ "LISTBOXENABLEDSLIDERDRAWDATA", parseDrawData },
	{ "LISTBOXDISABLEDUPBUTTONDRAWDATA", parseDrawData },
	{ "LISTBOXDISABLEDDOWNBUTTONDRAWDATA", parseDrawData },
	{ "LISTBOXDISABLEDSLIDERDRAWDATA", parseDrawData },
	{ "LISTBOXHILITEUPBUTTONDRAWDATA", parseDrawData },
	{ "LISTBOXHILITEDOWNBUTTONDRAWDATA", parseDrawData },
	{ "LISTBOXHILITESLIDERDRAWDATA", parseDrawData },
	{ "SLIDERTHUMBENABLEDDRAWDATA", parseDrawData },
	{ "SLIDERTHUMBDISABLEDDRAWDATA", parseDrawData },
	{ "SLIDERTHUMBHILITEDRAWDATA", parseDrawData },
	{ "COMBOBOXDROPDOWNBUTTONENABLEDDRAWDATA", parseDrawData },
	{ "COMBOBOXDROPDOWNBUTTONDISABLEDDRAWDATA", parseDrawData },
	{ "COMBOBOXDROPDOWNBUTTONHILITEDRAWDATA", parseDrawData },
	{ "COMBOBOXEDITBOXENABLEDDRAWDATA", parseDrawData },
	{ "COMBOBOXEDITBOXDISABLEDDRAWDATA", parseDrawData },
	{ "COMBOBOXEDITBOXHILITEDRAWDATA", parseDrawData },
	{ "COMBOBOXLISTBOXENABLEDDRAWDATA", parseDrawData },
	{ "COMBOBOXLISTBOXDISABLEDDRAWDATA", parseDrawData },
	{ "COMBOBOXLISTBOXHILITEDRAWDATA", parseDrawData },
	{ "IMAGEOFFSET", parseImageOffset },
	{ "TOOLTIP", parseTooltip },
	{ NULL, NULL }
};
static GameWindow *parseWindow( File *inFile, char *buffer )
{
	GameWindowParse *parse;
	GameWindow *window = NULL;
	GameWindow *parent = peekWindow();
	WinInstanceData instData;
	char type[64];
	char token[ 256 ];
	char *c;
	Int x, y, width, height;
	void *data = NULL;
	ICoord2D parentSize;
	AsciiString asciibuf;
	systemFunc = NULL;
	inputFunc = NULL;
	tooltipFunc = NULL;
	drawFunc = NULL;
	theSystemString.clear();
	theInputString.clear();
	theTooltipString.clear();
	theDrawString.clear();
	if( parent )
	{
		parent->winGetSize( &parentSize.x, &parentSize.y );
	}
	else
	{
		parentSize.x = TheDisplay->getWidth();
		parentSize.y = TheDisplay->getHeight();
	}
	instData.init();
	instData.m_enabledText.color = defTextColor;
	instData.m_enabledText.borderColor = defTextColor;
	instData.m_disabledText.color = defTextColor;
	instData.m_disabledText.borderColor = defTextColor;
	instData.m_hiliteText.color = defTextColor;
	instData.m_hiliteText.borderColor = defTextColor;
	instData.m_font = defFont;
	readUntilSemicolon( inFile, buffer, WIN_BUFFER_LENGTH );
	c = strtok( buffer, seps );
	assert( strcmp( c, "WINDOWTYPE" ) == 0 );
	c = strtok( NULL, seps );
	strcpy( type, c );
	data = getDataTemplate( type );
	readUntilSemicolon( inFile, buffer, WIN_BUFFER_LENGTH );
	c = strtok( buffer, seps );
	assert( strcmp( c, "SCREENRECT" ) == 0 );
	if( parseScreenRect( c, buffer, &x, &y, &width, &height ) == FALSE )
		goto cleanupAndExit;
	while( TRUE )
	{
		((GoalScriptFileSlots*)inFile)->scanString(asciibuf);
		for( parse = gameWindowFieldList; parse->parse; parse++ )
		{
			if (asciibuf.compare(parse->name) == 0)
			{
				strcpy( token, asciibuf.str() );
				((GoalScriptFileSlots*)inFile)->scanString(asciibuf);
				readUntilSemicolon( inFile, buffer, WIN_BUFFER_LENGTH );
				if (parse->parse( token, &instData, buffer, data ) == FALSE )
				{
					DEBUG_LOG(( "parseGameObject: Error parsing %s\n", parse->name ));
					goto cleanupAndExit;
				}
				break;
			}
		}
		if( parse->parse == NULL )
		{
			if (asciibuf.compare("DATA") == 0)
			{
				((GoalScriptFileSlots*)inFile)->scanString(asciibuf);
				readUntilSemicolon( inFile, buffer, WIN_BUFFER_LENGTH );
				if( parseData( &data, type, buffer ) == FALSE )
				{
					DEBUG_LOG(( "parseGameWindow: Error parsing %s\n", parse->name ));
					goto cleanupAndExit;
				}
			}
			else if (asciibuf.compare("END") == 0)
			{
				if(TheHeaderTemplateManager->getFontFromTemplate(instData.m_headerTemplateName))
					instData.m_font = TheHeaderTemplateManager->getFontFromTemplate(instData.m_headerTemplateName);
				if( window == NULL )
					window = createWindow( type, instData.m_id, instData.getStatus(), x, y,
																 width, height, &instData, data,
																 systemFunc, inputFunc, tooltipFunc, drawFunc );
				goto cleanupAndExit;
			}
			else if (asciibuf.compare("CHILD") == 0)
			{
				window = createWindow( type, instData.m_id, instData.getStatus(), x, y,
															 width, height, &instData, data,
															 systemFunc, inputFunc, tooltipFunc, drawFunc );
				if (window == NULL)
					goto cleanupAndExit;
				if( parseChildWindows( window, inFile, buffer ) == FALSE )
				{
					TheWindowManager->winDestroy( window );
					window = NULL;
					goto cleanupAndExit;
				}
			}
			else
			{
				readUntilSemicolon( inFile, buffer, WIN_BUFFER_LENGTH );
			}
		}
	}
cleanupAndExit:
	return window;
}
Bool parseInit( char *token, char *buffer, UnsignedInt version, WindowLayoutInfo *info )
{
	char *c;
	char *seps = " \n\r\t";
	c = strtok( buffer, seps );
	info->initNameString = c;
	info->init = TheFunctionLexicon->winLayoutInitFunc( TheNameKeyGenerator->nameToKey( info->initNameString ) );
	return TRUE;
}
Bool parseUpdate( char *token, char *buffer, UnsignedInt version, WindowLayoutInfo *info )
{
	char *c;
	char *seps = " \n\r\t";
	c = strtok( buffer, seps );
	info->updateNameString = c;
	info->update = TheFunctionLexicon->winLayoutUpdateFunc( TheNameKeyGenerator->nameToKey( info->updateNameString ) );
	return TRUE;
}
Bool parseShutdown( char *token, char *buffer, UnsignedInt version, WindowLayoutInfo *info )
{
	char *c;
	char *seps = " \n\r\t";
	c = strtok( buffer, seps );
	info->shutdownNameString = c;
	info->shutdown = TheFunctionLexicon->winLayoutShutdownFunc( TheNameKeyGenerator->nameToKey( info->shutdownNameString ) );
	return TRUE;
}
static LayoutScriptParse layoutScriptTable[] =
{
	{ "LAYOUTINIT",										parseInit },
	{ "LAYOUTUPDATE",									parseUpdate },
	{ "LAYOUTSHUTDOWN",								parseShutdown },
	{ NULL,															NULL },
};
Bool parseLayoutBlock( File *inFile, char *buffer, UnsignedInt version, WindowLayoutInfo *info );
WindowLayout *GameWindowManager::winCreateLayout( AsciiString filename )
{
	WindowLayout *layout;
	layout = newInstance(WindowLayout);
	if( layout->load( filename ) == FALSE )
	{
		layout->deleteInstance();
		return NULL;
	}
	return layout;
}
#pragma optimize("s", on)
void GameWindowManager::freeStaticStrings(void)
{
	theSystemString.clear();
	theInputString.clear();
	theTooltipString.clear();
	theDrawString.clear();
}
#pragma optimize("", on)
WindowLayoutInfo::WindowLayoutInfo() :
	version(0),
	init(NULL),
	update(NULL),
	shutdown(NULL),
	initNameString(AsciiString::TheEmptyString),
	updateNameString(AsciiString::TheEmptyString),
	shutdownNameString(AsciiString::TheEmptyString)
{
		windows.clear();
}
GameWindow *GameWindowManager::winCreateFromScript( AsciiString filenameString,
																										WindowLayoutInfo *info )
{
	const char* filename = filenameString.str();
	static char buffer[ WIN_BUFFER_LENGTH ];
	GameWindow *firstWindow = NULL;
  GameWindow *window;
  char filepath[ _MAX_PATH ] = "Window\\";
  File *inFile;
	WindowLayoutInfo scriptInfo;
	AsciiString asciibuf;
  resetWindowStack();
	resetWindowDefaults();
	if( strchr( filename, '\\' ) == NULL )
		sprintf( filepath, "Window\\%s", filename );
	else
		strcpy( filepath, filename );
	inFile = TheFileSystem->openFile(filepath, File::READ);
	if (inFile == NULL)
	{
		DEBUG_LOG(( "WinCreateFromScript: Cannot access file '%s'.\n", filename ));
		return NULL;
	}
  inFile=inFile->convertToRAMFile();
	Int version;
	inFile->read(NULL, strlen("FILE_VERSION = "));
	inFile->scanInt(version);
	inFile->nextLine();
	if( version >= 2 )
	{
		if( parseLayoutBlock( inFile, buffer, version, &scriptInfo ) == FALSE )
		{
			DEBUG_LOG(( "WinCreateFromScript: Error parsing layout block\n" ));
			return FALSE;
		}
	}
	else
	{
		scriptInfo.initNameString = "[None]";
		scriptInfo.updateNameString = "[None]";
		scriptInfo.shutdownNameString = "[None]";
	}
	while( TRUE )
	{
		if (((GoalScriptFileSlots*)inFile)->scanString(asciibuf) == FALSE) {
			break;
		}
		if (asciibuf.compare("END") == 0) {
      continue;
		}
		if (asciibuf.compare("ENABLEDCOLOR") == 0)
		{
			if( parseDefaultColor( &defEnabledColor, inFile, buffer ) == FALSE )
			{
				inFile->close();
				inFile = NULL;
				return NULL;
			}
		}
		else if (asciibuf.compare("DISABLEDCOLOR") == 0)
		{
			if( parseDefaultColor( &defDisabledColor, inFile, buffer ) == FALSE )
			{
				inFile->close();
				inFile = NULL;
				return NULL;
			}
		}
		else if (asciibuf.compare("HILITECOLOR") == 0)
		{
			if( parseDefaultColor( &defHiliteColor, inFile, buffer ) == FALSE )
			{
				inFile->close();
				inFile = NULL;
				return NULL;
			}
		}
		else if (asciibuf.compare("SELECTEDCOLOR") == 0)
		{
			if( parseDefaultColor( &defSelectedColor, inFile, buffer ) == FALSE )
			{
				inFile->close();
				inFile = NULL;
				return NULL;
			}
		}
		else if (asciibuf.compare("TEXTCOLOR") == 0)
		{
			if( parseDefaultColor( &defTextColor, inFile, buffer ) == FALSE )
			{
				inFile->close();
				inFile = NULL;
				return NULL;
			}
		}
		else if (asciibuf.compare("BACKGROUNDCOLOR") == 0)
		{
			if( parseDefaultColor( &defBackgroundColor, inFile, buffer ) == FALSE )
			{
				inFile->close();
				inFile = NULL;
				return NULL;
			}
		}
		else if (asciibuf.compare("FONT") == 0)
		{
			if( parseDefaultFont( defFont, inFile, buffer ) == FALSE )
			{
				inFile->close();
				inFile = NULL;
				return NULL;
			}
		}
		else if (asciibuf.compare("WINDOW") == 0)
		{
      window = parseWindow( inFile, buffer );
			if( firstWindow == NULL )
				firstWindow = window;
			scriptInfo.windows.push_back(window);
    }
	}
	inFile->close();
	inFile = NULL;
	if( info )
		*info = scriptInfo;
	return firstWindow;
}
#pragma comment(linker, "/alternatename:_strcpy=?ji_00629176@@YAXXZ")
