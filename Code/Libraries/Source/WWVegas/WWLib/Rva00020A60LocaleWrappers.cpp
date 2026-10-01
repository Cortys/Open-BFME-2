// cl: /MD
// Donor: Open-BFME-1 10af19f44a89ab7ecc23195bb9a842ceafbc02c9,
// game/Libraries/Source/WWVegas/WWLib/Rva0084D790LocaleWrappers.cpp.
// Its SDK short-directory include aliases do not resolve here; the declarations
// below retain the SDK's Win32 widths, C linkage, dllimport and stdcall ABI.
typedef unsigned short WCHAR;
typedef unsigned short WORD;
extern "C" __declspec(dllimport) int __stdcall GetStringTypeW(
    unsigned long, const WCHAR *, int, WORD *);

// Target evidence: [0x00020A60,0x00020A8F), then INT3 padding.
// IAT 0x00BBA1B0 declares kernel32!GetStringTypeW. Retail builds a terminated
// WCHAR pair, requests CT_CTYPE1 (1), and masks the first output word.
// The donor's address label is not an original target function identity.
int __cdecl Rva00020A60(const void *unused, int character, int mask)
{
    WCHAR input[2] = {(WCHAR)character, 0};
    WORD result[2];
    GetStringTypeW(1, input, -1, result);
    return result[0] & mask;
}
