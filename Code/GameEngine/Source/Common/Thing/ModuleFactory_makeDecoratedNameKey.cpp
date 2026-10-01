// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD
//
// ModuleFactory::makeDecoratedNameKey, retail 0x00255C5E, 74 bytes.
// Dedicated TU. Prefixes the AsciiString text with '0'+type then nameToKey.

#include <string.h>
extern "C" char *__cdecl _mbscpy(char *dst, const char *src);

enum NameKeyType
{
	NAMEKEY_INVALID = 0
};

enum ModuleType
{
	MODULETYPE_FIRST = 0
};

#include "ascii_string.h"

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *nameString);
};

NameKeyGenerator *TheNameKeyGenerator;

class ModuleFactory
{
protected:
	static NameKeyType makeDecoratedNameKey(const AsciiString &name, ModuleType type);
};

NameKeyType ModuleFactory::makeDecoratedNameKey(const AsciiString &name, ModuleType type)
{
	char tmp[256];
	tmp[0] = (char)('0' + (int)type);
	_mbscpy(&tmp[1], name.str());
	return TheNameKeyGenerator->nameToKey(tmp);
}
