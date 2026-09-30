// cl: /O1 /EHsc /DNDEBUG /MD
//
// ?Rva004DD722Get@@YAMH@Z @ 0x004DD722 (25B).
// Free int-to-float scaler: zero returns BfmeZeroRange else (float)value * g_00C52AD4.
// Evidence: callers at 0x004DD846 0x004DE0DE 0x004DE4FA 0x004DE518 push one int;
// BfmeZeroRange extern name in use plus g_00C52AD4 float ref; prev/next both /O1.

extern const float BfmeZeroRange;
extern float g_00C52AD4;

float __cdecl Rva004DD722Get(int value)
{
	if (value == 0)
		return BfmeZeroRange;
	return (float)value * g_00C52AD4;
}
