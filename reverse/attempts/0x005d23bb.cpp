// ?Rva005D23BBGet@@YAPBVImage@@PAURva005D23BBIn@@@Z
// partial score=0.96 date=2026-09-28
// ?Rva005D23BBGet@@YAPBVImage@@PAURva005D23BBIn@@@Z
// partial score=0.96 date=2026-09-28
// cl: /O1 /MD
template <typename T>
class StringBase
{
public:
	bool isEmpty() const;
private:
	char *m_data;
};
class AsciiString : public StringBase<char>
{
};
class Image;
class ImageCollection { public: const Image *findImageByName(const AsciiString &n); };
#define TheMappedImageCollection (*(ImageCollection **)0x00DFF078)
struct Rva005D23BBHolder { char pad[0x2C]; AsciiString str; };
class Rva002E2903Player { public: char pad[0x40]; Rva005D23BBHolder *holder; };
class Rva002BA8F1Logic { public: Rva002E2903Player *find(int, unsigned int *); };
#define TheRva00DFEF10 (*(Rva002BA8F1Logic **)0x00DFEF10)
struct Rva005D23BBMid { char pad[0x13C]; int id; };
struct Rva005D23BBIn { char pad[0x1C]; Rva005D23BBMid *mid; };
const Image *Rva005D23BBGet(Rva005D23BBIn *in)
{
	int id = in->mid->id;
	Rva002E2903Player *p = TheRva00DFEF10->find(id, 0);
	if (!p)
		return 0;
	Rva005D23BBHolder *h = p->holder;
	const AsciiString &s = h->str;
	if (s.isEmpty())
		return 0;
	return TheMappedImageCollection->findImageByName(s);
}
