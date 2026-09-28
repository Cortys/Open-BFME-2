// ?setCursorTooltip@Mouse@@QAEXVUnicodeString@@HPBURGBColor@@M@Z
// partial score=0.98 date=2026-09-28
// ?setCursorTooltip@Mouse@@QAEXVUnicodeString@@HPBURGBColor@@M@Z
// partial score=0.98 date=2026-09-28
// cl: /O1 /MD /EHsc

// ?setCursorTooltip@Mouse@@QAEXVUnicodeString@@HPBURGBColor@@M@Z @0x001EEA6D 360B
// BFME2 Mouse::setCursorTooltip: m_tooltipString.set at +0x12FC, delay at +0x4FCC,
// text/back colors at +0x4FDC/+0x4FEC from +0x128C/+0x12BC with alt flags at
// +0x12E0/+0x12E1/+0x12E2. Caller at 0x001EB5FC passes TheEmptyString, -1, 0, 1.0f
// (matches ZH/BFME1 donor LoadScreenUpdates: setCursorTooltip(TheEmptyString, -1, 0, 1.0f)).
// Donor: reference/open-bfme-1/Code/GameEngine/Source/GameClient/Input/Mouse.cpp
// (ZH GeneralsMD Mouse.cpp setCursorTooltip with DisplayString/wordwrap removed in
// BFME2; width param unused, color conversion kept: (c+1)*127.5 vs c*255).
// TheMouse singleton at 0x009FDCA0 (TheMouse in MouseSetEngineVisibility.cpp).

template <typename T>
class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
	void set(const StringBase &other);
private:
	void releaseBuffer();
	T *m_data;
};

class UnicodeString : public StringBase<unsigned short>
{
};

struct RGBColor
{
	float red;
	float green;
	float blue;
};

struct RGBAColorInt
{
	unsigned int red;
	unsigned int green;
	unsigned int blue;
	unsigned int alpha;
};

class Mouse
{
	char _pad0[0x128c];
	RGBAColorInt m_tooltipColorText;
	char _pad1[0x12bc - 0x129c];
	RGBAColorInt m_tooltipColorBackground;
	char _pad2[0x12e0 - 0x12cc];
	bool m_useTooltipAltTextColor;
	bool m_useTooltipAltBackColor;
	bool m_adjustTooltipAltColor;
	char _pad3[0x12fc - 0x12e3];
	UnicodeString m_tooltipString;
	char _pad4[0x4fcc - 0x1300];
	int m_tooltipDelay;
	char _pad5[0x4fdc - 0x4fd0];
	RGBAColorInt m_tooltipTextColor;
	RGBAColorInt m_tooltipBackColor;
public:
	void setCursorTooltip(UnicodeString tooltip, int delay, const RGBColor *color, float width);
};

// ?setCursorTooltip@Mouse@@QAEXVUnicodeString@@HPBURGBColor@@M@Z present-unmatched
void Mouse::setCursorTooltip(UnicodeString tooltip, int delay, const RGBColor *color, float width)
{
	(void)width;
	m_tooltipDelay = delay;
	m_tooltipString.set(tooltip);
	if (color)
	{
		if (m_useTooltipAltTextColor)
		{
			if (m_adjustTooltipAltColor)
			{
				m_tooltipTextColor.red = (int)((color->red + 1.0f) * 127.5f);
				m_tooltipTextColor.green = (int)((color->green + 1.0f) * 127.5f);
				m_tooltipTextColor.blue = (int)((color->blue + 1.0f) * 127.5f);
			}
			else
			{
				m_tooltipTextColor.red = (int)(color->red * 255.0f);
				m_tooltipTextColor.green = (int)(color->green * 255.0f);
				m_tooltipTextColor.blue = (int)(color->blue * 255.0f);
			}
			m_tooltipTextColor.alpha = m_tooltipColorText.alpha;
		}
		if (m_useTooltipAltBackColor)
		{
			if (m_adjustTooltipAltColor)
			{
				m_tooltipBackColor.red = (int)(color->red * 127.5f);
				m_tooltipBackColor.green = (int)(color->green * 127.5f);
				m_tooltipBackColor.blue = (int)(color->blue * 127.5f);
			}
			else
			{
				m_tooltipBackColor.red = (int)(color->red * 255.0f);
				m_tooltipBackColor.green = (int)(color->green * 255.0f);
				m_tooltipBackColor.blue = (int)(color->blue * 255.0f);
			}
			m_tooltipBackColor.alpha = m_tooltipColorBackground.alpha;
		}
	}
	else
	{
		m_tooltipTextColor = m_tooltipColorText;
		m_tooltipBackColor = m_tooltipColorBackground;
	}
}
