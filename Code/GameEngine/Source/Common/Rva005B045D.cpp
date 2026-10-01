// cl: /O1 /MD
// ?rva005B045D@Rva005B045D@@QAEPAXXZ @0x005B045D 22B
// Evidence: caller 0x005B54A7; flag at +0x14c plus ptr at +0x144 else this.
class Rva005B045D
{
public:
	void *rva005B045D();
private:
	char m_pad[0x144];
	void *m_ptr144;
	char m_gap148[4];
	int m_flag14c;
};

void *Rva005B045D::rva005B045D()
{
	if (m_flag14c == 1)
	{
		void *p = m_ptr144;
		if (p)
			return p;
	}
	return this;
}
