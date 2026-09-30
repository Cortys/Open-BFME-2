// cl: /GX-
// ?rva00380200@Rva00380200@@QAEPAVAsciiString@@XZ @ 0x00380200 (13B): getter returning +4 or AsciiString::TheEmptyString. Callers 0x00380230 0x00380265 push result. Twin of EmptyString fallback pattern.
class AsciiString
{
public:
	static AsciiString TheEmptyString;
};

class Rva00380200
{
	int m_00;
	AsciiString *m_ptr;
public:
	AsciiString *rva00380200();
};

AsciiString *Rva00380200::rva00380200()
{
	if (m_ptr)
		return m_ptr;
	return &AsciiString::TheEmptyString;
}
