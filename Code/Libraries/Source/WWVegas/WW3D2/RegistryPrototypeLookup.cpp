// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// Retail RVA 0x009EBCE0: complete 211-byte counted registry lookup.
// The caller supplies hidden aggregate storage and one explicit name.
// The original registry/helper names are not independently established.

class Rva009EB7A0RefOwner
{
public:
	void Release_Ref();
};

class Rva009EBCE0AssetReference
{
public:
	Rva009EBCE0AssetReference() : m_object( 0 ) {}
	Rva009EBCE0AssetReference( const Rva009EBCE0AssetReference &that )
		: m_object( that.m_object )
	{
		if ( m_object )
		{
			++*(unsigned short *)((char *)m_object + 4);
		}
	}
	~Rva009EBCE0AssetReference()
	{
		if ( m_object )
		{
			((Rva009EB7A0RefOwner *)m_object)->Release_Ref();
		}
	}

private:
	void *m_object;
};

class Rva009EEC60Registry
{
public:
	Rva009EBCE0AssetReference Rva009EEC60_FindAsset( const char *name );
};

extern Rva009EEC60Registry *Rva00F4FAACRegistry;

Rva009EBCE0AssetReference Rva009EBCE0_GetPrototype( const char *name )
{
	if ( !name )
	{
		return Rva009EBCE0AssetReference();
	}

	return Rva00F4FAACRegistry
		? Rva00F4FAACRegistry->Rva009EEC60_FindAsset( name )
		: Rva009EBCE0AssetReference();
}
// ?Rva00F4FAACRegistry@@3PAVRva009EEC60Registry@@A: the global at VA 0xe09c0c is ?TheQ1Receiver@@3PAVQ1Receiver0134FAAC@@A.
#pragma comment(linker, "/alternatename:?Rva00F4FAACRegistry@@3PAVRva009EEC60Registry@@A=?TheQ1Receiver@@3PAVQ1Receiver0134FAAC@@A")
