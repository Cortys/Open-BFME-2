// ?changeObjectPanelFlagForSingleObject@ScriptActions@@IAEXPAVObject@@ABVAsciiString@@_N@Z
// partial score=0.9 date=2026-09-26
// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?changeObjectPanelFlagForSingleObject@ScriptActions@@IAEXPAVObject@@ABVAsciiString@@_N@Z,
// retail 0x003C4C07, 341 bytes. Dedicated TU.
//
// Zero Hour reference
// (reference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/
// GameEngine/Source/GameLogic/ScriptEngine/ScriptActions.cpp,
// ScriptActions::changeObjectPanelFlagForSingleObject): seven AsciiString
// comparisons against TheObjectFlagsNames[0..6] in declaration order, each
// arm applying one object panel flag.  Retail keeps that structure exactly:
//
//   [0] Enabled            -> setScriptStatus(1, !newVal)      (call 0x292969)
//   [1] Powered            -> setScriptStatus(2, !newVal)
//   [2] Indestructible     -> body->setIndestructible(newVal)  (vtable +0x84)
//   [3] Unsellable         -> setScriptStatus(4, newVal)
//   [4] Selectable         -> isSelectable (0x28D7FD) then setSelectable
//                             (0x28B76D) only when the value differs
//   [5] AI Recruitable     -> inlined store of newVal at ai+0x3BE
//   [6] Player Targetable  -> setScriptStatus(0x10, newVal)
//
// Target-evidence deltas from the Zero Hour donor, both read from the retail
// bytes rather than carried from the donor source:
//
//  * arm [2] does not stop at the body module.  After the setIndestructible
//    call retail loads the contain module from the SAME object base it had
//    just used for the body module (`add esi, 0x250`; the body module was
//    read at [esi+0x254]), tests one bool-returning virtual at +0x7C, then
//    calls the +0x118 virtual with a pointer to an 8-byte stack temporary and
//    walks the doubly linked list reached through that temporary's second
//    dword, recursing into this function for every non-null contained object.
//    Zero Hour has no such propagation.  The list walk is the STLport node
//    shape (next/prev/value, value at +8) and re-reads the list head through
//    the temporary on every iteration, which is what the source below spells.
//  * arm [5] is an inlined byte store at ai+0x3BE where the donor calls
//    AIUpdateInterface::setIsRecruitable.
//
// The 8-byte temporary is the only piece whose donor-side spelling is not
// recovered: retail passes its address as a hidden return slot, so the +0x118
// virtual returns an 8-byte aggregate whose second dword is the contained
// items list.  The first dword is never read here, so its meaning is unknown
// and the struct below records that rather than inventing a name for it.
//
// TheObjectFlagsNames is the array defined in Scripts.cpp; its seven entries
// sit at 0x009C10FC..0x009C1114 and reach this body through masked DIR32
// slots, so no data pin is required.

typedef int Int;
typedef unsigned char UnsignedByte;
typedef bool Bool;

#define NULL 0

// Shared StringBase<char> implementation; the comparison arm calls the matched
// ?compare@?$StringBase@D@@QBEHPBD@Z body at 0x000069B1 out of line.
template <typename T>
class StringBase
{
public:
	int compare( const T *other ) const;

protected:
	void *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	Bool operator==( const char *other ) const { return compare( other ) == 0; }
};

extern const char *TheObjectFlagsNames[];

// Vtable padding: the two module interfaces are reached only through fixed
// slots, so declare the untouched slots as placeholders to put the used ones
// at the retail offsets.
#define VSLOT( n ) virtual void slot##n( void );
#define VSLOT8( a, b, c, d, e, f, g, h ) \
	VSLOT( a ) VSLOT( b ) VSLOT( c ) VSLOT( d ) VSLOT( e ) VSLOT( f ) VSLOT( g ) VSLOT( h )

class BodyModuleInterface
{
public:
	VSLOT8( b00, b01, b02, b03, b04, b05, b06, b07 )
	VSLOT8( b08, b09, b10, b11, b12, b13, b14, b15 )
	VSLOT8( b16, b17, b18, b19, b20, b21, b22, b23 )
	VSLOT8( b24, b25, b26, b27, b28, b29, b30, b31 )
	VSLOT( b32 )
	virtual void setIndestructible( Bool indestructible );	// slot 33, +0x84
};

class Object;

// Doubly linked list of contained objects, STLport node shape: the list holds
// one pointer to its sentinel node, each node is { next, prev, value }.
struct ContainedItemNode
{
	ContainedItemNode *m_next;
	ContainedItemNode *m_prev;
	Object *m_object;
};

struct ContainedItemsList
{
	ContainedItemNode *m_node;
};

// 8-byte aggregate returned through the hidden return slot by the +0x118
// virtual.  Only the second dword is read by this body; the first is unknown.
struct ContainedItemsListResult
{
	Int m_unread;
	const ContainedItemsList *m_list;
};

class ContainModuleInterface
{
public:
	// slots 0..30
	VSLOT8( c00, c01, c02, c03, c04, c05, c06, c07 )
	VSLOT8( c08, c09, c10, c11, c12, c13, c14, c15 )
	VSLOT8( c16, c17, c18, c19, c20, c21, c22, c23 )
	VSLOT( c24 ) VSLOT( c25 ) VSLOT( c26 ) VSLOT( c27 )
	VSLOT( c28 ) VSLOT( c29 ) VSLOT( c30 )
	virtual Int hasContainedItems( void ) const;	// slot 31, +0x7C
	// slots 32..69
	VSLOT8( c32, c33, c34, c35, c36, c37, c38, c39 )
	VSLOT8( c40, c41, c42, c43, c44, c45, c46, c47 )
	VSLOT8( c48, c49, c50, c51, c52, c53, c54, c55 )
	VSLOT8( c56, c57, c58, c59, c60, c61, c62, c63 )
	VSLOT( c64 ) VSLOT( c65 ) VSLOT( c66 )
	VSLOT( c67 ) VSLOT( c68 ) VSLOT( c69 )
	virtual void getContainedItemsList( ContainedItemsListResult *result ) const;	// slot 70, +0x118
};

class AIUpdateInterface
{
public:
	unsigned char m_pad[ 0x3BE ];
	Bool m_isRecruitable;	// +0x3BE
};

enum ObjectScriptStatusBit
{
	OBJECT_STATUS_SCRIPT_DISABLED = 0x01,
	OBJECT_STATUS_SCRIPT_UNPOWERED = 0x02,
	OBJECT_STATUS_SCRIPT_UNSELLABLE = 0x04,
	OBJECT_STATUS_SCRIPT_TARGETABLE = 0x10
};

class Object
{
public:
	void setScriptStatus( ObjectScriptStatusBit bit, Bool set );
	Bool isSelectable( void ) const;
	void setSelectable( Bool selectable );

	ContainModuleInterface *getContain( void ) const { return m_contain; }
	BodyModuleInterface *getBodyModule( void ) const { return m_body; }
	AIUpdateInterface *getAIUpdateInterface( void ) const { return m_ai; }

private:
	unsigned char m_pad00[ 0x250 ];
	ContainModuleInterface *m_contain;	// +0x250
	BodyModuleInterface *m_body;		// +0x254
	AIUpdateInterface *m_ai;			// +0x258
};

class ScriptActions
{
protected:
	void changeObjectPanelFlagForSingleObject( Object *obj, const AsciiString &flagToChange, Bool newVal );
};

// ?changeObjectPanelFlagForSingleObject@ScriptActions@@IAEXPAVObject@@ABVAsciiString@@_N@Z
void ScriptActions::changeObjectPanelFlagForSingleObject( Object *obj, const AsciiString &flagToChange, Bool newVal )
{
	// Enabled flag
	if( flagToChange == TheObjectFlagsNames[ 0 ] )
	{
		obj->setScriptStatus( OBJECT_STATUS_SCRIPT_DISABLED, !newVal );
		return;
	}

	// Powered flag
	if( flagToChange == TheObjectFlagsNames[ 1 ] )
	{
		obj->setScriptStatus( OBJECT_STATUS_SCRIPT_UNPOWERED, !newVal );
		return;
	}

	// Indestructible flag
	if( flagToChange == TheObjectFlagsNames[ 2 ] )
	{
		BodyModuleInterface *body = obj->getBodyModule();
		if( body )
		{
			body->setIndestructible( newVal );
		}

		ContainModuleInterface *contain = obj->getContain();
		if( contain == NULL || !contain->hasContainedItems() )
		{
			return;
		}

		ContainedItemsListResult items;
		obj->getContain()->getContainedItemsList( &items );
		for( ContainedItemNode *node = items.m_list->m_node->m_next;
				node != items.m_list->m_node;
				node = node->m_next )
		{
			Object *contained = node->m_object;
			if( contained )
			{
				changeObjectPanelFlagForSingleObject( contained, flagToChange, newVal );
			}
		}
		return;
	}

	// Unsellable flag
	if( flagToChange == TheObjectFlagsNames[ 3 ] )
	{
		obj->setScriptStatus( OBJECT_STATUS_SCRIPT_UNSELLABLE, newVal );
		return;
	}

	// Selectable flag
	if( flagToChange == TheObjectFlagsNames[ 4 ] )
	{
		if( obj->isSelectable() != newVal )
		{
			obj->setSelectable( newVal );
		}
		return;
	}

	// AI Recruitable flag
	if( flagToChange == TheObjectFlagsNames[ 5 ] )
	{
		AIUpdateInterface *ai = obj->getAIUpdateInterface();
		if( ai )
		{
			ai->m_isRecruitable = newVal;
		}
		return;
	}

	// Player targetable flag
	if( flagToChange == TheObjectFlagsNames[ 6 ] )
	{
		obj->setScriptStatus( OBJECT_STATUS_SCRIPT_TARGETABLE, newVal );
		return;
	}
}
