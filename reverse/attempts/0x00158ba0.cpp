// ?rva00158BA0@Rva00158BA0@@QAEXPAMPBG@Z
// partial score=0.9 date=2026-09-30
// ?rva00158BA0@Rva00158BA0@@QAEXPAMPBG@Z
// partial score=0.90 date=2026-09-30
// cl: /O2 /G7 /DNDEBUG /MD /EHsc /arch:SSE
// Retail RVA 0x00158BA0, 192 bytes.
// ?rva00158BA0@Rva00158BA0@@QAEXPAMPBG@Z
// Wide-string extent measurer: x accumulates glyph advances, y holds CharHeight.
// Loops WCHARs until null, skips 0x0A, resolves each via
// FontCharsClass::loadCharacterData (rowed 0x00158580); Thai composed ranges
// 0x0E01-0x0E3A / 0x0E3F-0x0E5B use Width+ExtraSpacing, others Width minus the
// two spacing members at +0x34/+0x38; caller 0x00105CF6 pushes str then out
// (first stack arg is out, second is str) and passes ecx+4 as this.
// Evidence: callee loadCharacterData row; prev FontCharsClassRva001588A0 // cl:;
// caller 0x00105CF6 (cvttss2si pair, TheNullChr fallback).
struct FontCharsClassCharDataStruct
{
	unsigned short Value;
	short Width;
	short ExtraSpacing;
	char m_pad06[2];
	unsigned short *Buffer;
};

class FontCharsClass
{
public:
	const FontCharsClassCharDataStruct *loadCharacterData(unsigned short character);
public:
	char m_pad00[0x2C];
	int CharHeight; // +0x2C
	char m_pad30[0x34 - 0x30];
	int m_spacing34; // +0x34
	int m_spacing38; // +0x38
};

class Rva00158BA0
{
public:
	void rva00158BA0(float *out, const unsigned short *str);
private:
	char m_pad00[0x4C];
	FontCharsClass *m_font; // +0x4C
};

// ?rva00158BA0@Rva00158BA0@@QAEXPAMPBG@Z present-unmatched
void Rva00158BA0::rva00158BA0(float *out, const unsigned short *str)
{
	float x = 0.0f;
	float y = (float)m_font->CharHeight;
	const unsigned short *p = str;
	unsigned short ch = *p;
	if (ch != 0) {
		do {
			p++;
			if (ch != 0x0A) {
				const FontCharsClassCharDataStruct *data = m_font->loadCharacterData(ch);
				int w;
				if (data == 0 || data->Width == 0) {
					w = 0;
				} else if ((ch >= 0x0E01 && ch <= 0x0E3A) || (ch >= 0x0E3F && ch <= 0x0E5B)) {
					w = (int)data->ExtraSpacing + (int)data->Width;
				} else {
					w = (int)data->Width - m_font->m_spacing38 - m_font->m_spacing34;
				}
				x += (float)w;
			}
			ch = *p;
		} while (ch != 0);
	}
	out[0] = x;
	out[1] = y;
}
