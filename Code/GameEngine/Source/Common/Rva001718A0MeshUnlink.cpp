// cl: /DNDEBUG /MD /G6 /EHsc
//
// Retail 0x001718A0 (51 B) unlinks this owner from the +0xB4/+0xB8 list: when
// the link slot is set it stores the tail through it, back-points the tail at
// the link and clears the slot.
//
// Ported from Open-BFME-1's Small03hMeshLink.cpp (submodule 10af19f44a; BFME 1
// 0x009455F0), where the slots sit at +0xBC/+0xC0: game.dat's owner is eight
// bytes shorter ahead of them, which is the only difference. The link-reload
// spelling (m_link re-read for the back-pointer store) is what emits retail's
// second load of +0xB4. The paired link at 0x00171870 tests the slot with
// cmp [ecx+0xB4],0 where the donor's spelling loads and tests it, so it is
// not carried. IDENTITY IS NOT RECOVERED: the owner keeps an address token.
class Rva001718A0Box
{
public:
	void unlink();
	char m_pad[0xB4];
	void *m_link;
	void *m_tail;
};
void Rva001718A0Box::unlink()
{
	void *link = m_link;
	if (link != 0)
	{
		void *tail = m_tail;
		*(void **)link = tail;
		void *t2 = m_tail;
		if (t2 != 0)
		{
			void *l2 = m_link;
			*(void **)((char *)t2 + 0xB4) = l2;
		}
		m_link = 0;
	}
}
