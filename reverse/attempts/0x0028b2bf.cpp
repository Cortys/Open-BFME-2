// ?rva0028B2BF@Object@@QAEXXZ
// partial score=0.98 date=2026-09-30
// ?rva0028B2BF@Object@@QAEXXZ
// partial score=0.98 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0028B2BF@Object@@QAEXXZ, retail 0x0028B2BF, 91 bytes.
// Unlock: compacts 8-byte entries at +0x3C5 skipping zeros counted by signed
// byte at +0x43A. Evidence: unlock lane, callers 0x0028B352 0x0029208A,
// neighbours ObjectRva0028B265/0028B38D share flags.

class Object
{
public:
	void rva0028B2BF();
	char m_pad[0x43B];
};

// ?rva0028B2BF@Object@@QAEXXZ present-unmatched
void Object::rva0028B2BF()
{
	int outCount = 0;
	if (*(signed char *)(m_pad + 0x43A) > 0) {
		unsigned char *src = (unsigned char *)(m_pad + 0x3C6);
		unsigned char *dst = (unsigned char *)(m_pad + 0x3C5);
		int i = 0;
		do {
			if (*src != 0) {
				outCount++;
				dst[-1] = 0;
				dst[0] = 0;
				dst[1] = *src;
				*(int *)(dst - 5) = *(int *)(src - 6);
				dst += 8;
			}
			src += 8;
			i++;
		} while (i < *(signed char *)(m_pad + 0x43A));
	}
	*(unsigned char *)(m_pad + 0x43A) = (unsigned char)outCount;
}
