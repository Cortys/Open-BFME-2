// Open-BFME5 conversion of the codec table-selector wrapper.

struct Rva009ACC40State
{
	int m_mode;
	unsigned char m_pad04[8];
	int m_tableIndex;
	unsigned char m_pad10[0x28];
	int m_result;
};

extern int *g_rva01356A9C;
extern int *Rva009ACBA0SetupBounding(Rva009ACC40State *, int);
// g_rva01356E64: VA 0x00E22F80 (.data BSS), a zero-initialized callback slot.
int (__cdecl *g_rva01356E64)(Rva009ACC40State *, int) = 0;

void Rva009ACC40SetupFilter(Rva009ACC40State *state)
{
	if (state->m_mode >= 2) {
		int value = g_rva01356A9C[state->m_tableIndex];
		state->m_result = (int)Rva009ACBA0SetupBounding(state, value);
	} else {
		int value = g_rva01356A9C[state->m_tableIndex];
		state->m_result = g_rva01356E64(state, value);
	}
}
