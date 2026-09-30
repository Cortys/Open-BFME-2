// cl: /Ireference/shims/bfme2_ascii /O1 /MD
// One-argument CRC-32 string hash at retail 0x003EC922 (49 bytes). Same
// table-driven accumulation as the two-argument family in realcrc.cpp, but a
// standalone one-shot wrapper: a null or empty input
// returns 0, otherwise the seed is 0xFFFFFFFF and the result is inverted. The
// index is the raw ((char)crc ^ c) xor with no 0xFF mask. /O1 keeps the retail
// inc-edx pointer step; /O2 widens it to add edx,1.
// Not WWLib's CRC32_Table (.data 0x00DD5A90): both bodies here read the
// identical-content .rdata copy at 0x00C35BD0, so it gets its own
// address-derived name (owner unknown).
extern unsigned long Rva00835BD0Crc32Table[256];

unsigned long CRC_String(char const *string)
{
  unsigned long crc = 0;
  char c;
  if (string != 0 && (c = *string) != 0) {
    crc = 0xFFFFFFFF;
    do {
      ++string;
      crc = (crc >> 8) ^ Rva00835BD0Crc32Table[(char)crc ^ c];
      c = *string;
    } while (c != 0);
    crc = ~crc;
  }
  return crc;
}

unsigned long CRC_Stringi(char *string)
{
  unsigned long crc = 0;
  char c;
  if (string != 0 && (c = *string) != 0) {
    crc = 0xFFFFFFFF;
    do {
      ++string;
      if (c >= 'a' && c <= 'z')
        c &= 0xDF;
      crc = (crc >> 8) ^ Rva00835BD0Crc32Table[(char)crc ^ c];
      c = *string;
    } while (c != 0);
    crc = ~crc;
  }
  return crc;
}

// ?Rva003ECA13Get@@YAKABVAsciiString@@@Z, retail 0x003ECA13 (28B). Free-function
// wrapper over the rowed one-arg CRC_String at 0x003EC922: inlines
// AsciiString::str() (m_data ? m_data->text : the "" literal at VA 0x00BBAC1C)
// then tail-calls CRC_String. Evidence: 26 callers (e.g. 0x00206255 0x00207DF4
// 0x003571B8) push their AsciiString arg and pop ecx after the call (__cdecl
// one-arg shape) and use the result as an unsigned map key; byte shape matches
// the rowed NameKeyGenerator AsciiString wrappers at 0x002D91AF and 0x0009FA65
// modulo the callee and the cdecl ret shape.
template <typename T> struct BfmeStringData
{
  int refCount;
  unsigned short length;
  unsigned short capacity;
  T text[1];
};

#include "ascii_string.h"

unsigned long Rva003ECA13Get(const AsciiString &s)
{
  return CRC_String(s.str());
}
