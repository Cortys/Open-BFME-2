// cl: /O1 /DNDEBUG /MD
// ?rva0044E6AE@Rva0044E6AE@@QAEXXZ @0x0044E6AE 10B
// Virtual forward with (0 1) through slot 0x34. Retail is mov eax [ecx]
// push 1 push 0 call [eax+0x34] ret. Evidence: unlock lane; callers at
// 0x0029314E 0x0049C96F 0x0049C9BD plus jmp at 0x0049C937; unblocks 0x0049C8FC
// 0x00293105 0x0049C93F; abuts prev row 0x0044E6A7 which ends at this start;
// flags copied from next TU ModuleDataBuildFieldParseChained.cpp. Owner
// unproven so the name stays address-derived.
class Rva0044E6AE
{
public:
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
	virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
	virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
	virtual void v12();
	virtual void virt34(int a, int b);
	void rva0044E6AE();
};

void Rva0044E6AE::rva0044E6AE()
{
	virt34(0, 1);
}
