// Retail 0x009EBDC0: return the registry's current counted asset.
// The dump's generated name is replaced by the recovered return-by-value ABI.

class CountedAsset
{
public:
	void Release_Ref();
};

class AssetReference
{
public:
	AssetReference() : m_object( 0 ) {}
	AssetReference( const AssetReference &that ) : m_object( that.m_object )
	{
		if ( m_object )
		{
			++*(unsigned short *)((char *)m_object + 4);
		}
	}
	~AssetReference()
	{
		if ( m_object )
		{
			m_object->Release_Ref();
		}
	}

private:
	CountedAsset *m_object;
};

class AssetRegistry
{
public:
	AssetReference Get_Current_Asset();
};

extern AssetRegistry *g_theAssetRegistry;

AssetReference Rva009EBDC0()
{
	return g_theAssetRegistry
		? g_theAssetRegistry->Get_Current_Asset()
		: AssetReference();
}

// ?g_theAssetRegistry@@3PAVAssetRegistry@@A: matched references place it at VA 0xe09c0c; also referenced as ?Rva00F4FAACRegistry@@3PAVRva009EEC60Registry@@A, ?g_bfmeObjEME@@3PAVBfmeObjEME@@A, ?g_bfmeP1025@@3PAVBfmeP1025@@A, ?g_bfmeP1024@@3PAVBfmeP1024@@A.
AssetRegistry * g_theAssetRegistry = 0;
#pragma comment(linker, "/alternatename:?Rva00F4FAACRegistry@@3PAVRva009EEC60Registry@@A=?g_theAssetRegistry@@3PAVAssetRegistry@@A")
#pragma comment(linker, "/alternatename:?g_bfmeObjEME@@3PAVBfmeObjEME@@A=?g_theAssetRegistry@@3PAVAssetRegistry@@A")
#pragma comment(linker, "/alternatename:?g_bfmeP1025@@3PAVBfmeP1025@@A=?g_theAssetRegistry@@3PAVAssetRegistry@@A")
#pragma comment(linker, "/alternatename:?g_bfmeP1024@@3PAVBfmeP1024@@A=?g_theAssetRegistry@@3PAVAssetRegistry@@A")
