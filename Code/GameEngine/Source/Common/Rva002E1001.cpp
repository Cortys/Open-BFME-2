// cl: /O1
// ?rva002E1001@Rva002E1001@@QAEHXZ retail 0x002E1001 69 bytes.
// Unlock-lane counter: triple-deref global at 0x00DFEF10 through +0xB0 and
// +8, plus 0x2C bias or zero, counts array entries whose +0x13C field equals
// this+0x14. Evidence: unlock lane (unblocks 0x004FC970 plus four more);
// five callers pass this in ecx with no stack args and ret 0; same
// sub-sar-2 count plus inc-eax loop shape as pool counters; neighbours carry
// /O1.
class Rva002E1001
{
public:
	int rva002E1001();
private:
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	int m_14;
};

int Rva002E1001::rva002E1001()
{
	int c = 0;
	void **pp = *(void ***)0x00DFEF10;
	pp = *(void ***)((char *)pp + 0xB0);
	pp = *(void ***)((char *)pp + 8);
	char *p;
	if (pp)
		p = (char *)pp + 0x2C;
	else
		p = 0;
	if (!p)
		goto done;
	{
		int *start = *(int **)p;
		int *end = *(int **)(p + 4);
		int n = (int)(end - start);
		if (n == 0)
			goto done;
		int id = *(int *)((char *)this + 0x14);
		int *cur = start;
		int left = n;
		while (left) {
			void *e = *(void **)cur;
			if (*(int *)((char *)e + 0x13C) == id)
				c++;
			cur = (int *)((char *)cur + 4);
			left--;
		}
	}
done:
	return c;
}
