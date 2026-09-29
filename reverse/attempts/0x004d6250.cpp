// ?rva004D6250@Rva004D632D@@QAEXVAsciiString@@@Z
// partial score=0.95 date=2026-09-29
// ?rva004D6250@Rva004D632D@@QAEXVAsciiString@@@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /Oy- /MD /EHsc
// ?rva004D6250@Rva004D632D@@QAEXVAsciiString@@@Z @0x004D6250 (89B):
// AsciiString setter on Rva004D632D: converts the by-value argument via
// GameState::realMapPathToPortableMapPath then assigns into the +0x1c member
// via pin-only operator= 0x000366F0; temp and parameter destroyed via rowed
// releaseBuffer 0x00036410. Reverse of the 0x004D632D getter.
// Evidence: callers 0x004D19D4 0x004D2E21 plus TheGameState 0x009FF08C.
template <typename T> class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	T *m_data;
};
class AsciiString : public StringBase<char>
{
public:
	AsciiString &operator=(const AsciiString &other);
};
class GameState
{
public:
	AsciiString realMapPathToPortableMapPath(const AsciiString &in) const;
};
extern GameState *TheGameState;
class Rva004D632D
{
public:
	void rva004D6250(AsciiString s);
private:
	char m_pad[0x1c];
	AsciiString m_str1c;
};
// ?rva004D6250@Rva004D632D@@QAEXVAsciiString@@@Z present-unmatched
void Rva004D632D::rva004D6250(AsciiString s)
{
	m_str1c = TheGameState->realMapPathToPortableMapPath(s);
}
