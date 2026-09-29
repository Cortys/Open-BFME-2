// cl: /O1 /MD
// ?rva005F0152@Rva005F0152@@QAEPBVImage@@H@Z retail 0x005F0152 51B
// Cached image fetch by index through AsciiString names at +8 and Image
// slots at +0x3C via ImageCollection::findImageByName. Evidence: unlock lane
// plus 2 callers plus prev Rva005F002CImageFind donor TU and flags.

template <typename T> class StringBase
{
public:
	bool isEmpty() const;

private:
	T *m_data;
};

class AsciiString : public StringBase<char>
{
};

class Image;
class ImageCollection
{
public:
	const Image *findImageByName(const AsciiString &n);
};

#define TheMappedImageCollection (*(ImageCollection **)0x00DFF078)

class Rva005F0152
{
public:
	const Image *rva005F0152(int index);

private:
	char m_pad[8];
	AsciiString m_names[13];
	const Image *volatile m_images[13];
};

const Image *Rva005F0152::rva005F0152(int index)
{
	const Image *volatile *slot = &m_images[index];
	if (*slot)
		return *slot;
	const AsciiString &name = m_names[index];
	if (name.isEmpty())
		return *slot;
	*slot = TheMappedImageCollection->findImageByName(name);
	return *slot;
}

extern Rva005F0152 Rva00A06858;

const Image *Rva005F01B8Get(int index)
{
	return Rva00A06858.rva005F0152(index);
}

struct Rva005F020BMid
{
	char m_pad[0x2C];
	int m_index;
};

struct Rva005F020BIn
{
	char m_pad[0x28];
	Rva005F020BMid *m_mid;
};

const Image *Rva005F020BGet(Rva005F020BIn *in)
{
	return Rva00A06858.rva005F0152(in->m_mid->m_index);
}
