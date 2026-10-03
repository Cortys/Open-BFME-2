// ?rva00274591@Drawable@@QAEXXZ
// partial score=0.93 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /EHsc /Oy- /G7 /arch:SSE
//
// ?rva00274591@Drawable@@QAEXXZ, retail 0x00274591, 551 bytes.
// Drawable low-offset state machine over +0x38 with vector accumulate at
// +0x28 when lengths pass plus global threshold at 0x007FAC14.
// Evidence: prev Drawable 0x00274445 plus next Drawable 0x00274C62 plus
// callers 0x00275C4E and 0x00275C5A plus EBP frame matching /Oy- /G7.
//
extern float g_00BFAC14;

class WWMath { public: __forceinline static float Sqrt(float val) {
    float retval;
    __asm { fld val
        fsqrt
        fstp retval }
    return retval;
} };

class Drawable
{
public:
	void rva00274591();
private:
	unsigned char m_pad0[4];
	float m_cx;
	float m_cy;
	float m_cz;
	float m_ax;
	float m_ay;
	float m_az;
	float m_ox;
	float m_oy;
	float m_oz;
	float m_bx;
	float m_by;
	float m_bz;
	unsigned int m_counter;
	signed char m_state;
	unsigned char m_flag39;
};

static inline float VecLen(float x, float y, float z)
{
	float q = x * x + y * y + z * z;
	return WWMath::Sqrt(q);
}

// ?rva00274591@Drawable@@QAEXXZ present-unmatched
void Drawable::rva00274591()
{
	switch (m_state) {
	case 0:
		m_bx = 0.0f;
		m_by = 0.0f;
		m_bz = 0.0f;
		m_flag39 = 0;
		break;
	case 1:
	{
		float lenC = VecLen(m_cx, m_cy, m_cz);
		float dx = m_bx - m_ox;
		float dy = m_by - m_oy;
		float dz = m_bz - m_oz;
		float lenD = VecLen(dx, dy, dz);
		if (lenC > lenD)
			goto set23;
		if (g_00BFAC14 >= VecLen(dx, dy, dz))
			goto set23;
		float tbx = m_cx;
		tbx += m_bx;
		m_bx = tbx;
		float tby = m_cy;
		tby += m_by;
		m_by = tby;
		float tbz = m_cz;
		tbz += m_bz;
		m_bz = tbz;
		m_flag39 = 1;
		break;
	set23:;
		if (m_counter != 0)
			m_state = 3;
		else
			m_state = 2;
		break;
	}
	case 2:
	{
		float lenA = VecLen(m_ax, m_ay, m_az);
		float lenB = VecLen(m_bx, m_by, m_bz);
		if (lenA > lenB || g_00BFAC14 >= VecLen(m_bx, m_by, m_bz)) {
			m_state = 0;
			m_flag39 = 0;
			break;
		}
		float tbx2 = m_ax;
		tbx2 += m_bx;
		m_bx = tbx2;
		float tby2 = m_ay;
		tby2 += m_by;
		m_by = tby2;
		float tbz2 = m_az;
		tbz2 += m_bz;
		m_bz = tbz2;
		m_flag39 = 1;
		break;
	}
	case 3:
		if (m_counter > 0u)
			m_counter--;
		else
			m_state = 2;
		break;
	default:
		break;
	}
}
