// Trimmed port of reference/open-bfme-1/Code/GameEngine/Source/Common/
// Q3MakeDerivedFamily.cpp: the Rva007E9B40, Rva007F2E60, Rva007F3410,
// Rva007F40F0 and Rva007FBB20 helpers are carried; the three sibling helpers
// stay with the donor until rows land. See the donor for the full
// multiple-inheritance analysis.

void *Gen007F0130( unsigned int size );

class Q3MakeBaseA
{
public:
	virtual void primary();
	static void *operator new( unsigned int size ) { return Gen007F0130( size ); }
};

class Q3MakeBaseB
{
public:
	virtual void secondary();
	void *m_payload;
	Q3MakeBaseB( void *payload ) { m_payload = payload; }
};

class Rva007E9B40Object : public Q3MakeBaseA, public Q3MakeBaseB
{
public:
	Rva007E9B40Object( void *payload ) : Q3MakeBaseB( payload ) {}
	virtual void primary();
	virtual void secondary();
};

Rva007E9B40Object *Rva007E9B40( void *payload )
{
	return new Rva007E9B40Object( payload );
}

class Rva007F2E60Object : public Q3MakeBaseA, public Q3MakeBaseB
{
public:
	Rva007F2E60Object( void *payload ) : Q3MakeBaseB( payload ) {}
	virtual void primary();
	virtual void secondary();
};

Rva007F2E60Object *Rva007F2E60( void *payload )
{
	return new Rva007F2E60Object( payload );
}

class Rva007F3410Object : public Q3MakeBaseA, public Q3MakeBaseB
{
public:
	Rva007F3410Object( void *payload ) : Q3MakeBaseB( payload ) {}
	virtual void primary();
	virtual void secondary();
};

Rva007F3410Object *Rva007F3410( void *payload )
{
	return new Rva007F3410Object( payload );
}

class Rva007F40F0Object : public Q3MakeBaseA, public Q3MakeBaseB
{
public:
	Rva007F40F0Object( void *payload ) : Q3MakeBaseB( payload ) {}
	virtual void primary();
	virtual void secondary();
};

Rva007F40F0Object *Rva007F40F0( void *payload )
{
	return new Rva007F40F0Object( payload );
}

class Rva007FBB20Object : public Q3MakeBaseA, public Q3MakeBaseB
{
public:
	Rva007FBB20Object( void *payload ) : Q3MakeBaseB( payload ) {}
	virtual void primary();
	virtual void secondary();
};

Rva007FBB20Object *Rva007FBB20( void *payload )
{
	return new Rva007FBB20Object( payload );
}

// Callers elsewhere reach bodies in this unit through other spellings; retail's
// call sites in their matched rows land on these addresses (same ABI). Bind them.
#pragma comment(linker, "/alternatename:?Gen007E9B40@@YAPAURva007E9D70Cached@@PAURva007E9D70Owner@@@Z=?Rva007E9B40@@YAPAVRva007E9B40Object@@PAX@Z")
#pragma comment(linker, "/alternatename:?Gen007F2E60@@YAPAURva007E9DF0Cached@@PAURva007E9DF0Owner@@@Z=?Rva007F2E60@@YAPAVRva007F2E60Object@@PAX@Z")
#pragma comment(linker, "/alternatename:?Gen007F3410@@YAPAURva007E9E30Cached@@PAURva007E9E30Owner@@@Z=?Rva007F3410@@YAPAVRva007F3410Object@@PAX@Z")
#pragma comment(linker, "/alternatename:?Gen007F40F0@@YAPAURva007E9E70Cached@@PAURva007E9E70Owner@@@Z=?Rva007F40F0@@YAPAVRva007F40F0Object@@PAX@Z")
