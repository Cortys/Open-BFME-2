// ?rva000A9DC4@Rva000A9DC4@@QAEPAVAssetReference@@PAV2@@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /Oy- /DNDEBUG /MD
// ?rva000A9DC4@Rva000A9DC4@@QAEXPAVAssetReference@@@Z @0x000A9DC4 47B
// __thiscall asset fetch: p=*(this); if !p or !p->GetRef() clear out->m_object else copy-construct out from *ref; return out.
// Evidence: EBP frame ret4; mov ecx [ecx] and ebp-4 0 test je; mov eax [ecx] call [eax+0x10] test jne; and [eax] 0 jmp; mov ecx out push eax call AssetReference copy 0x000424BB mov eax out; caller at 0x000A9F3C unblocks 0x000A9F23.
class AssetReference
{
public:
	AssetReference(const AssetReference &that);
};
class Rva000A9DC4Iface
{
public:
	virtual void _0();
	virtual void _1();
	virtual void _2();
	virtual void _3();
	virtual const AssetReference *GetRef() const;
};
class Rva000A9DC4
{
public:
	AssetReference *rva000A9DC4(AssetReference *out);
private:
	Rva000A9DC4Iface *m_p;
};

// ?rva000A9DC4@Rva000A9DC4@@QAEPAVAssetReference@@PAV2@@Z present-unmatched
AssetReference *Rva000A9DC4::rva000A9DC4(AssetReference *out)
{
	volatile int _e = 0;
	Rva000A9DC4Iface *p = m_p;
	if (p == 0) {
		*(int *)out = 0;
		return out;
	}
	const AssetReference *ref = p->GetRef();
	if (ref == 0) {
		*(int *)out = 0;
		return out;
	}
	out->AssetReference::AssetReference(*ref);
	return out;
}
