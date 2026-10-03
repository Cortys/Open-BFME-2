// cl: /O1 /DNDEBUG /MD

// GameWindow small setters, retail 0x00313B87/0x00313CF2/0x00314147.
// Ported from Open-BFME-1 Code/GameEngine/Source/GameClient/GUI/GameWindow.cpp
// (BFME1 0x00478250/0x00478440/0x00478E70). BFME moves the window fields:
// status at +0x08, size at +0x0C/+0x10, region at +0x14..0x20, input callback
// at +0x1E0. The manager's winSendSystemMsg sits at vtable +0xE8 (slot 58),
// like GadgetListBoxReset's +0xE8 call.

typedef int Int;
#define NULL 0
#define BitTest(value, mask) (((value) & (mask)) != 0)
enum { WIN_STATUS_TAB_STOP = 0x100 };
typedef unsigned int UnsignedInt;
typedef UnsignedInt WindowMsgData;

enum WindowMsgHandledType
{
	MSG_IGNORED,
	MSG_HANDLED
};

enum
{
	WIN_ERR_OK = 0,
	GGM_RESIZED = 16388
};

class GameWindow;

typedef WindowMsgHandledType (*GameWinInputFunc)(GameWindow *, UnsignedInt, WindowMsgData, WindowMsgData);

class GameWindowManager
{
public:
#define V(n) virtual void pad##n() = 0;
	V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
	V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
	V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23)
	V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31)
	V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
	V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47)
	V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55)
	V(56) V(57)
#undef V
	virtual WindowMsgHandledType winSendSystemMsg(GameWindow *window, UnsignedInt msg, WindowMsgData mData1, WindowMsgData mData2) = 0;
};

extern GameWindowManager *TheWindowManager;

class GameWindow
{
public:
	Int winSetSize(Int width, Int height);
	UnsignedInt winClearStatus(UnsignedInt status);
	Int winSetInputFunc(GameWinInputFunc input);

protected:
	GameWindow *findFirstLeaf();
	GameWindow *findLastLeaf();
	GameWindow *findPrevLeaf();
	GameWindow *findNextLeaf();

private:
	unsigned char m_pad0[0x08];
	UnsignedInt m_status;
	Int m_sizeX;
	Int m_sizeY;
	Int m_regionLoX;
	Int m_regionLoY;
	Int m_regionHiX;
	Int m_regionHiY;
	unsigned char m_pad1[0x1E0 - 0x24];
	GameWinInputFunc m_inputFunc;
	unsigned char m_pad1E4[0x1F8 - 0x1E4];
	GameWindow *m_next;
	GameWindow *m_prev;
	GameWindow *m_parent;
	GameWindow *m_child;
};

// ?winSetSize@GameWindow@@QAEHHH@Z, retail 0x00313B87 (63B).
Int GameWindow::winSetSize(Int width, Int height)
{
	m_sizeX = width;
	m_sizeY = height;
	m_regionHiX = m_regionLoX + width;
	m_regionHiY = m_regionLoY + height;

	TheWindowManager->winSendSystemMsg(this, GGM_RESIZED, (WindowMsgData)width, (WindowMsgData)height);

	return WIN_ERR_OK;
}

// ?winClearStatus@GameWindow@@QAEII@Z, retail 0x00313CF2 (17B).
UnsignedInt GameWindow::winClearStatus(UnsignedInt status)
{
	UnsignedInt oldStatus;

	oldStatus = m_status;
	m_status &= ~status;

	return oldStatus;
}

// ?winSetInputFunc@GameWindow@@QAEHP6A?AW4WindowMsgHandledType@@PAV1@III@Z@Z, retail 0x00314147 (19B).
Int GameWindow::winSetInputFunc(GameWinInputFunc input)
{
	if (input)
		m_inputFunc = input;

	return WIN_ERR_OK;
}

// ?findFirstLeaf@GameWindow@@IAEPAV1@XZ
// Clean BFME1 GameWindow.cpp at revision
// 6d9434269164392c5ba62aaa7c15a86b5b020d76, compiled under BFME2 /O1 /G7,
// emitted a unique 31-byte first-leaf walk at RVA 0x0031396B. Native boundary
// 0x0031396B-0x0031398A proves the parent (+0x200) and first-child (+0x204)
// chains; the native next-leaf body tail-calls it after ascending to the root.
// The donor's auxiliary layout emitted the bytes; this is the established
// GameWindow first-leaf operation, using the target-measured window offsets.
GameWindow *GameWindow::findFirstLeaf()
{
    GameWindow *leaf = this;
    while (leaf->m_parent)
        leaf = leaf->m_parent;
    while (leaf->m_child)
        leaf = leaf->m_child;
    return leaf;
}

// ?findNextLeaf@GameWindow@@IAEPAV1@XZ
// Same clean BFME1 donor revision as findFirstLeaf. Native boundary
// 0x00313A25-0x00313A9E proves next +0x1F8, parent +0x200, child +0x204,
// and the stop bit 0x100. Ascending to the root tail-calls the rowed
// first-leaf walk at 0x0031396B. Donor control flow and labels are retained;
// all member accesses use the independently measured target window layout.
GameWindow *GameWindow::findNextLeaf( void )
{
	GameWindow *leaf = (GameWindow *)this;

	if( leaf->m_next )
	{

		if( leaf->m_next->m_status & WIN_STATUS_TAB_STOP )
			return (GameWindow *)leaf->m_next;

		for( leaf = leaf->m_next; leaf; leaf = leaf->m_child )
			if( leaf->m_child == NULL || BitTest( leaf->m_status,
																						WIN_STATUS_TAB_STOP ) )
				return (GameWindow *)leaf;

	}  // end if
	else 
	{

		while( leaf->m_parent )
		{

			leaf = leaf->m_parent;

			if( leaf->m_parent && leaf->m_next )
			{

				for( leaf = leaf->m_next; leaf; leaf = leaf->m_child )
					if( leaf->m_child == NULL ||
							BitTest( leaf->m_status, WIN_STATUS_TAB_STOP ) )
						return (GameWindow *)leaf;

			}  // end if

		}  // end while

		if( leaf )
			return (GameWindow *)leaf->findFirstLeaf();
		else
			return NULL;

	}  // end else

	return NULL;

}  // end findNextLeav


// ?findLastLeaf@GameWindow@@IAEPAV1@XZ
// The 114-byte previous-leaf donor names an opaque walk callee. Native
// 0x0031398A-0x003139B3 proves that callee ascends parents at +0x200,
// then follows first children at +0x204 and their final siblings at +0x1F8.
// This independently matches the original donor's last-leaf operation.
GameWindow *GameWindow::findLastLeaf( void )
{
	GameWindow *leaf = this;

	// Find the root of this branch
	while( leaf->m_parent )
		leaf = leaf->m_parent;

	// Find the last leaf
	while( leaf->m_child ) 
	{

		leaf = leaf->m_child;

		while( leaf->m_next )
			leaf = leaf->m_next;

	}  // end while

	return leaf;

}  // end findLastLeaf


// ?findPrevLeaf@GameWindow@@IAEPAV1@XZ
// Clean BFME1 donor control flow, with its opaque fallback resolved to the
// native last-leaf walk at 0x0031398A. Native boundary 0x003139B3-0x00313A25
// independently proves previous sibling +0x1FC, next +0x1F8, parent +0x200,
// child +0x204, and status bit 0x100. The prior family members stay byte-exact.
GameWindow *GameWindow::findPrevLeaf( void )
{

	GameWindow *leaf = (GameWindow *)this;

	if( leaf->m_prev )
	{

		leaf = leaf->m_prev;

		while( leaf->m_child &&
						 BitTest( leaf->m_status, WIN_STATUS_TAB_STOP ) == false )
		{

			leaf = leaf->m_child;

			while( leaf->m_next )
				leaf = leaf->m_next;

		}  // end while

		return (GameWindow *)leaf;

	}   // end if
	else 
	{

		while( leaf->m_parent )
		{

			leaf = leaf->m_parent;

			if( leaf->m_parent && leaf->m_prev )
			{

				leaf = leaf->m_prev;

				while( leaf->m_child &&
							 BitTest( leaf->m_status, WIN_STATUS_TAB_STOP ) == false )
				{

					leaf = leaf->m_child;

					while( leaf->m_next )
						leaf = leaf->m_next;

				}  // end while

				return (GameWindow *)leaf;

			}  // end if

		}  // end while

		if( leaf )
			return leaf->findLastLeaf();
		else
			return NULL;

	}  // end else

	return NULL;

}  // end findPrevLeaf

