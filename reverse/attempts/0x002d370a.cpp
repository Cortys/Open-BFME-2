// ?rva002D370A@RadarWindowOverrideSource@@QAEXXZ
// partial score=0.95 date=2026-09-28
// ?rva002D370A@RadarWindowOverrideSource@@QAEXXZ
// partial score=0.95 date=2026-09-28
// cl: /O1
//
// Radar window override accessors, retail 0x002D35CF (7B) and 0x002D35D6 (16B).
// Split into a dedicated TU so RadarNewMap.cpp keeps its matched newMap:
// defining these in the same unit lets MSVC see the callee and changes the
// caller's register save set (docs/matching.md pattern five).

class GameWindow;

void setHideScroll();
void Rva005CB260();

class Rva00524A4C
{
public:
	void Rva00524A65(int arg);
private:
	char m_pad[0x24];
public:
	unsigned char m_flags;
};

struct RadarWindowOverrideInner
{
	char m_pad[ 0x60 ];
	bool m_flag0 : 1;
	bool m_flag1 : 1;
	bool m_flag2 : 1;
	bool m_unused : 5;
	char m_pad61[ 3 ];
	GameWindow *m_window;
	char m_pad68[ 0x10 ];
	Rva00524A4C *m_78;
	bool m_7C;
	char m_pad7D[ 0x4B ];
	void *m_C8;
};

class RadarWindowOverrideSource
{
public:
	bool hasOverrideWindow( void ) const;
	GameWindow *getOverrideWindow( void ) const;
	bool rva002D35E6( void ) const;
	void rva002D35F2( void );
	void rva002D370A( void );
	void rva002D3615( bool value );

private:
	char m_pad[ 0x10 ];
	RadarWindowOverrideInner *m_inner;
};

GameWindow *RadarWindowOverrideSource::getOverrideWindow( void ) const
{
	return m_inner->m_window;
}

bool RadarWindowOverrideSource::hasOverrideWindow( void ) const
{
	return ( m_inner->m_flag0 || m_inner->m_flag1 || m_inner->m_flag2 ) ? 0 : 1;
}

bool RadarWindowOverrideSource::rva002D35E6( void ) const
{
	return m_inner->m_flag2;
}

void RadarWindowOverrideSource::rva002D35F2( void )
{
	Rva00524A4C *p = m_inner->m_78;
	if (p->m_flags & 1)
		p->Rva00524A65(500);
}

void RadarWindowOverrideSource::rva002D3615( bool value )
{
	m_inner->m_7C = value;
	setHideScroll();
}

// ?rva002D370A@RadarWindowOverrideSource@@QAEXXZ present-unmatched
void RadarWindowOverrideSource::rva002D370A( void )
{
	void *p = m_inner->m_C8;
	if (p)
		Rva005CB260();
}
