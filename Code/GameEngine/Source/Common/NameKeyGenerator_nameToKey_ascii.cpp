// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD
//
// NameKeyGenerator::nameToKey(const AsciiString&), retail 0x0009FA65, 29 bytes.
// Thin wrapper over the landed char* overload at 0x00148E1A. Header text
// lives at +8; empty strings go through the "" literal.

enum NameKeyType
{
	NAMEKEY_INVALID = 0
};

#include "ascii_string.h"

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *nameString);
	NameKeyType nameToKey(const AsciiString &nameString);
};

NameKeyType NameKeyGenerator::nameToKey(const AsciiString &nameString)
{
	return nameToKey(nameString.str());
}
