// cl: /O1 /MD /arch:SSE
// ?rva000E459F@Rva000E459F@@QAE_NXZ retail 0x000E459F 315B
// Evidence: chain from 0x00272C9E Drawable::rva00272C9E plus pin getTransformMatrix; callers 0x000E5B57; matrix at +0x50 floats +0x84 +0x88 flag +0x98 Drawable +0x2C
extern float g_Va00BBB8D8;
class Matrix3D
{
public:
	float m[3][4];
};

class Drawable
{
public:
	float rva00272C9E(int key);
	const Matrix3D *getTransformMatrix() const;
};

class Rva000E459F
{
public:
	bool rva000E459F();
private:
	char m_pad00[0x2C];
	Drawable *m_2C;
	char m_pad30[0x20];
	Matrix3D m_50;
	char m_pad80[0x4];
	float m_84;
	float m_88;
	char m_pad8C[0xC];
	int m_98;
};

bool Rva000E459F::rva000E459F()
{
	if (!m_2C || m_98 != 1)
		return false;
	bool changed = false;
	float v;
	if (m_88 != 0.0f) {
		v = m_84 + m_88;
		if (v < 0.0f)
			v = 0.0f;
		if (v > g_Va00BBB8D8)
			v = g_Va00BBB8D8;
	} else {
		v = m_2C->rva00272C9E(0);
		const Matrix3D *m1 = m_2C->getTransformMatrix();
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (m_50.m[i][j] != m1->m[i][j])
					goto copy_mat;
			}
		}
		goto have_v;
	copy_mat: {
		const int *s = (const int *)m_2C->getTransformMatrix();
		int *d = (int *)&m_50;
		d[0] = s[0];
		d[1] = s[1];
		d[2] = s[2];
		d[3] = s[3];
		d[4] = s[4];
		d[5] = s[5];
		d[6] = s[6];
		d[7] = s[7];
		d[8] = s[8];
		d[9] = s[9];
		d[10] = s[10];
		d[11] = s[11];
		changed = true;
	}
	have_v:;
	}
	if (m_84 != v) {
		m_84 = v;
		changed = true;
	}
	return changed;
}
