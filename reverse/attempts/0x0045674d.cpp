// ?rva0045674D@Rva0045674D@@QAE?AVAsciiString@@HH@Z
// partial score=0.94 date=2026-10-04
// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD
// ?rva0045674D@Rva0045674D@@QAE?AVAsciiString@@HH@Z @ 0x0045674D 39B thiscall bridge string copy via StringBase copy
// Evidence: caller 0x00456B52; rowed callee 0x000365F0 StringBase copy; EBP frame with and [m]0 imul lea.
#include "ascii_string.h"

class Rva0045674D
{
public:
	AsciiString m_strings[80];
	AsciiString rva0045674D(int a, int b);
};

// ?rva0045674D@Rva0045674D@@QAE?AVAsciiString@@HH@Z present-unmatched
AsciiString Rva0045674D::rva0045674D(int a, int b)
{
	return m_strings[(a + 19) * 3 + b];
}
