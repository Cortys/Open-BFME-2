// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi-
//
// ?getNextToken@INI@@QAEPBDPBD@Z, retail 0x002DF97, 75 bytes.
// Dedicated TU.
//
// Throwing next-token helper: delegates to getNextTokenOrNull (pinned at
// 0x002DEED, whose 168B BFME2 body reads the default separator set at
// this+0x418 just like this body does) and throws INIException(3,
// "Expected additional data after '%s'") through the shared filler (pinned
// at 0x002F681) plus __CxxThrowException when the stream is exhausted.
// BFME1 ini.cpp shape verbatim; the only BFME2 delta is the default-seps
// member sitting at this+0x418 (BFME1: +0x414).

class INI
{
public:
	const char *getNextToken(const char *seps);
	const char *getNextTokenOrNull(const char *seps);
private:
	char _pad[0x418];
	const char *m_seps;
};

struct INIException
{
	INIException(int argCount, const char *format, ...);
	char *mFailureMessage;
	int mErrorCode;
	INIException(const INIException &that);
	~INIException();
};


// ?getNextToken@INI@@QAEPBDPBD@Z
const char *INI::getNextToken(const char *seps)
{
	const char *token = getNextTokenOrNull(seps);
	if (token == 0) {
		throw INIException(3, "Expected additional data after '%s'", (seps == 0) ? m_seps : seps);
	}
	return token;
}
