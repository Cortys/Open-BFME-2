// cl: /Ireference/shims/bfme2_ascii /O1 /GX /MD /DNDEBUG /DWIN32 /D_WINDOWS
//
// ??1AudioEventRTS@@QAE@XZ, retail 0x000793FA, 53 bytes. Dedicated TU.
//
// AudioEventRTS teardown destroys its two strings through the folded string
// teardown (0x36410 pin). The retail body follows that shape with the usual
// cookie and state transitions; the class view matches the constructor TU.

#include "ascii_string.h"

class AudioEventRTS
{
public:
	~AudioEventRTS();

private:
	AsciiString m_first;
	AsciiString m_second;
};

// ??1AudioEventRTS@@QAE@XZ
AudioEventRTS::~AudioEventRTS()
{
}
