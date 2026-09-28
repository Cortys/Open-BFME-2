// Disp8 word setters: twelve-byte __thiscall members with one shape:
//
//     mov ax,[esp+4] / mov [ecx+<DISP>],ax / ret 4
//
// One word is taken from the stack argument slot and stored at a fixed
// displacement from `this`. Same macro as Disp8ByteFieldSetters.cpp; every
// displacement here fits disp8 (MSVC 7.1 uses disp8 whenever the offset
// fits, so every offset is below 0x80).
// Identity is not recovered: every name is derived from its address,
// following Disp8ByteFieldSetters.cpp.
// No // cl: line (defaults match the frameless twelve-byte shape).
#define BFME_DISP8_WORD_SETTER(NAME, DISP) \
	class NAME \
	{ \
	public: \
		void set(unsigned short value); \
		char m_lead[DISP]; \
		unsigned short m_value; \
	}; \
	void NAME::set(unsigned short value) \
	{ \
		m_value = value; \
	}

BFME_DISP8_WORD_SETTER(Rva004D5978WordSlot, 0x20)
BFME_DISP8_WORD_SETTER(Rva004D59ACWordSlot, 0x1C)
