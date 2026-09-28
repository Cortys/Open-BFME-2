// Address-named constructor at retail 0x006587C0 (27B).
// The BFME1 constructor body is an ICF-shared lead, not an identity claim.
// Retail establishes these fields and values directly; the owning class
// remains unidentified, so this uses an address-derived layout view.

struct Rva006587C0View
{
	void *m_vtable;
	void (*m_callback)(void);
	unsigned int m_fields[ 3 ];

	Rva006587C0View();
};

Rva006587C0View::Rva006587C0View()
{
	m_vtable = reinterpret_cast<void *>( 0x00CE157C );
	m_callback = reinterpret_cast<void (*)(void)>( 0x00A587B0 );
	m_fields[ 0 ] = 0;
	m_fields[ 1 ] = 0;
	m_fields[ 2 ] = 0;
}
