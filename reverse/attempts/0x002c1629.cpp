// ?getWindowUnderCursor@CursorManagerView@@QAEPAVRva003141BCWindowView@@HH_N@Z
// partial score=0.99 date=2026-10-03
// cl: /O1 /G7 /MD /EHsc /DNDEBUG
// Readable ZH donor via BFME1 6d9434269; target Ghidra2C1629/323.
// Native manager capture+1C/grab+28/modal+24/list+C; signed bounds and next+1F8.
// View names disclaim original types. Field labels follow reference semantics.
typedef int Int; typedef bool Bool;
#define NULL 0
#define BitTest(value,mask) (((value)&(mask))!=0)
enum { WIN_STATUS_ABOVE=0x20, WIN_STATUS_BELOW=0x40, WIN_STATUS_HIDDEN=0x10, WIN_STATUS_ENABLED=8, WIN_STATUS_NO_INPUT=0x200 };
struct CursorCoord { int x,y; };
struct CursorRegion { CursorCoord lo,hi; };
class Rva003141BCWindowView {
public:
 unsigned char opaque0[8]; unsigned m_status; CursorCoord m_size;
 CursorRegion m_region; unsigned char opaque24[0x1F8-0x24];
 Rva003141BCWindowView*m_next; void*unknown1FC; Rva003141BCWindowView*m_parent; Rva003141BCWindowView*m_child;
 Rva003141BCWindowView*winPointInChild(int,int,bool,bool=false);
};
struct CursorModalView { void*unknown0; Rva003141BCWindowView*window; };
class CursorManagerView {
public:
 unsigned char opaque0[12]; Rva003141BCWindowView*m_windowList;
 unsigned char opaque10[12]; Rva003141BCWindowView*m_mouseCaptor;
 void*unknown20; CursorModalView*m_modalHead; Rva003141BCWindowView*m_grabWindow;
 Rva003141BCWindowView*getWindowUnderCursor(int,int,bool);
};
Rva003141BCWindowView *CursorManagerView::getWindowUnderCursor( Int x, Int y, Bool ignoreEnabled )
{
	if( m_mouseCaptor )
	{
		// in what what window within the captured window are we?
		return m_mouseCaptor->winPointInChild( x, y, ignoreEnabled );
	}

	if( m_grabWindow )
	{
		// in what what window within the grabbed window are we?
		return m_grabWindow->winPointInChild( x, y, ignoreEnabled );
	}

	Rva003141BCWindowView *window = NULL;
	if( m_modalHead && m_modalHead->window )
	{
		return m_modalHead->window->winPointInChild( x, y, ignoreEnabled );
	}
	else
	{
		// search for top-level window which contains pointer
		for( window = m_windowList; window; window = window->m_next )
		{

			if( BitTest( window->m_status, WIN_STATUS_ABOVE ) &&
					!BitTest( window->m_status, WIN_STATUS_HIDDEN ) &&
					x >= window->m_region.lo.x &&
					x <= window->m_region.hi.x &&
					y >= window->m_region.lo.y &&
					y <= window->m_region.hi.y)
			{
				if( BitTest( window->m_status, WIN_STATUS_ENABLED ) || ignoreEnabled )
				{
					// determine which child window the mouse is in
					window = window->winPointInChild( x, y, ignoreEnabled );
					break;  // exit for
				}
			}  // end if
		}  // end for window

		// check !above, below and hidden
		if( window == NULL )
		{
			for( window = m_windowList; window; window = window->m_next )
			{
				if( !BitTest( window->m_status, WIN_STATUS_ABOVE | 
																				WIN_STATUS_BELOW | 
																				WIN_STATUS_HIDDEN ) &&
						x >= window->m_region.lo.x &&
						x <= window->m_region.hi.x &&
						y >= window->m_region.lo.y &&
						y <= window->m_region.hi.y)
				{
					if( BitTest( window->m_status, WIN_STATUS_ENABLED )|| ignoreEnabled)
					{								
						// determine which child window the mouse is in
						window = window->winPointInChild( x, y, ignoreEnabled );
						break;  // exit for
					}
				}
			}
		}  // end if, window == NULL

		// check below and !hidden
		if( window == NULL )
		{
			for( window = m_windowList; window; window = window->m_next )
			{
				if( BitTest( window->m_status, WIN_STATUS_BELOW ) &&
						!BitTest( window->m_status, WIN_STATUS_HIDDEN ) &&
						x >= window->m_region.lo.x &&
						x <= window->m_region.hi.x &&
						y >= window->m_region.lo.y &&
						y <= window->m_region.hi.y)
				{
					if( BitTest( window->m_status, WIN_STATUS_ENABLED )|| ignoreEnabled)
					{
						// determine which child window the mouse is in
						window = window->winPointInChild( x, y, ignoreEnabled );
						break;  // exit for
					}
				}
			}
		}  // end if
	}  // end else, no modal head

	if( window )
	{
		if( BitTest( window->m_status, WIN_STATUS_NO_INPUT ))
		{
			// this window does not accept input, discard
			window = NULL;
		}
		else if( ignoreEnabled && !( BitTest( window->m_status, WIN_STATUS_ENABLED ) ))
		{
			window = NULL;
		}
	}

	return window;
}
