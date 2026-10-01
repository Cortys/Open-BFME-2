// cl: /O1 /MD /arch:SSE
// ?rva005DB928@Elem005DB98E@@QAEMXZ @0x005DB928 51B, caller 0x005DB96B (same
// this as 0x005DB95B). Falloff: 0 when m_08 <= 1, else
// max(m_08 - m_0C - 1, 0) / m_08.
// Target evidence: SSE comiss of the pooled 1.0 at 0x00BBB8D8 against +0x08,
// pooled 0.0 at 0x00BBAEAC on the low path, x87 subtract chain with the
// float memory operand 1.0 (fsub dword, so the 1.0 is the established
// g_Va00BBB8D8 global rather than a literal folded to double), fldz/fcomip
// clamp, then fdiv by +0x08.
// Structural inference: the clamp runs in double and the quotient divides
// the float-converted value, which keeps the fdiv memory form as retail.
extern float g_Va00BBB8D8;
extern const float BfmeZeroRange;

struct Elem005DB98E
{
	int m_00;
	float m_04;
	float m_08;
	float m_0C;
	unsigned long m_10;
	char m_14[4];
public:
	float rva005DB928();
};

float Elem005DB98E::rva005DB928()
{
	if (m_08 <= g_Va00BBB8D8)
		return BfmeZeroRange;
	double t = (double)m_08 - (double)m_0C - (double)g_Va00BBB8D8;
	if (t < 0.0)
		t = 0.0;
	return (float)t / m_08;
}
