// ?setCursorTooltip@Mouse@@QAEXVUnicodeString@@HPBURGBColor@@M@Z
// partial score=0.97 date=2026-09-27
// ?setCursorTooltip@Mouse@@QAEXVUnicodeString@@HPBURGBColor@@M@Z
// partial score=0.97 date=2026-09-27
// cl: /O1 /DNDEBUG /MD /EHsc
// ?setCursorTooltip@Mouse@@QAEXVUnicodeString@@HPBURGBColor@@M@Z @0x001EEA6D 360B
// Evidence: this is TheMouse (*(Mouse **)0x00DFDCA0, DisplaySetHeight.cpp); callers
// construct a UnicodeString temp via 0x00037050 from TheEmptyString 0x00A0C898 then
// call here with (tmp, -1/0, NULL, 1.0f) (0x00355FF9, 0x002BEFE5, 0x005830AE) or with a
// GameText-fetched tooltip (0x005F6F0C via slot 0x3C on 0x00DFF0BC STRATEGIChud string).
// Float immediates are 127.5f at 0x00BE03E4 (with MouseCursor string), 1.0f at
// 0x00BBB8D8, 255.0f at 0x00BC2900. Color math matches ZH/BFME1 Mouse::setCursorTooltip
// (reference/open-bfme-1/.../Input/Mouse.cpp): text (color+1)*255/2 vs color*255,
// back color*255*0.5 vs color*255, null color copies 16B defaults. Width ignored.
// Prev 0x001EE5D6 Mouse::setVisibility /O1 /MD, next 0x001EEFB6 deleting dtor /O1 /MD.
typedef unsigned short WideChar;

template <typename T>
class StringBase
{
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
	void releaseBuffer();
public:
	void set(const StringBase &src);
	~StringBase() { releaseBuffer(); }
};

class UnicodeString : public StringBase<WideChar>
{
};

struct RGBColor
{
	float red;
	float green;
	float blue;
};

struct RGBAInt
{
	int r;
	int g;
	int b;
	int a;
};

class Mouse
{
public:
	void setCursorTooltip(UnicodeString tooltip, int delay, const RGBColor *color, float);
private:
	char m_pad00[0x128C];
	RGBAInt m_128C;
	char m_pad129C[0x12BC - (0x128C + 16)];
	RGBAInt m_12BC;
	char m_pad12CC[0x12E0 - (0x12BC + 16)];
	bool m_12E0;
	bool m_12E1;
	bool m_12E2;
	char m_pad12E3[0x12FC - 0x12E3];
	UnicodeString m_12FC;
	char m_pad1300[0x4FCC - (0x12FC + 4)];
	int m_4FCC;
	char m_pad4FD0[0x4FDC - (0x4FCC + 4)];
	RGBAInt m_4FDC;
	RGBAInt m_4FEC;
};

// ?setCursorTooltip@Mouse@@QAEXVUnicodeString@@HPBURGBColor@@M@Z present-unmatched
void Mouse::setCursorTooltip(UnicodeString tooltip, int delay, const RGBColor *color, float)
{
	m_4FCC = delay;
	m_12FC.set(tooltip);
	if (color)
	{
		if (m_12E0)
		{
			if (m_12E2)
			{
				m_4FDC.r = (int)((color->red + 1.0f) * 255.0f / 2.0f);
				m_4FDC.g = (int)((color->green + 1.0f) * 255.0f / 2.0f);
				m_4FDC.b = (int)((color->blue + 1.0f) * 255.0f / 2.0f);
			}
			else
			{
				m_4FDC.r = (int)(color->red * 255.0f);
				m_4FDC.g = (int)(color->green * 255.0f);
				m_4FDC.b = (int)(color->blue * 255.0f);
			}
			m_4FDC.a = m_128C.a;
		}
		if (m_12E1)
		{
			if (m_12E2)
			{
				m_4FEC.r = (int)(color->red * 255.0f * 0.5f);
				m_4FEC.g = (int)(color->green * 255.0f * 0.5f);
				m_4FEC.b = (int)(color->blue * 255.0f * 0.5f);
			}
			else
			{
				m_4FEC.r = (int)(color->red * 255.0f);
				m_4FEC.g = (int)(color->green * 255.0f);
				m_4FEC.b = (int)(color->blue * 255.0f);
			}
			m_4FEC.a = m_12BC.a;
		}
	}
	else
	{
		m_4FDC = m_128C;
		m_4FEC = m_12BC;
	}
}
