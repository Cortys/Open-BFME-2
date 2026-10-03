// cl: /O1 /EHs /MD
// Retail 0x00170999 33B: Rva00170999 ctor copying AssetReference at +0 via
// rowed ??0AssetReference@@QAE@ABV0@@Z and 16 bytes at +4 from second arg.
// Evidence: callees rowed; callers 0x00170A58 (by-value wrapper) and 0x00171128
// (stack temp from zeroed AssetReference plus 16-byte value, then map insert
// with TextureClass Release_Ref at 0x0061ED10).

class CountedAsset;
class AssetReference
{
public:
	AssetReference(const AssetReference &that);
private:
	CountedAsset *m_object;
};

struct Rva00170999Data
{
	unsigned int w;
	unsigned int x;
	unsigned int y;
	unsigned int z;
};

class Rva00170999
{
public:
	Rva00170999(const AssetReference &a, const Rva00170999Data &d);
private:
	AssetReference m_asset;
	Rva00170999Data m_data;
};

Rva00170999::Rva00170999(const AssetReference &a, const Rva00170999Data &d)
	: m_asset(a)
	, m_data(d)
{
}
