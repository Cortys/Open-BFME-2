// ??0Rva007F0080Owner@@QAE@PAX0@Z @ 0x0065CF60 (43B)
// Donor: Open-BFME-1 reference/open-bfme-1/game/GameEngine/Source/GameNetwork/
// Rva007F0080DefaultPointers.cpp at submodule revision
// cd32c8ef06dfb0d995b2f47e93e41622e4447092. Retail preserves the donor's
// instructions and object layout; only the default function pointers differ.
// Target evidence: retail immediates at 0x0065CF71 and 0x0065CF81 are
// 0x00A5CEC0/0x00A5CED0, also established by matched sibling
// Rva007F00B0AllocatorInit at 0x0065CF90.

class Rva007F0080Owner
{
public:
    Rva007F0080Owner(void *first, void *second);
    virtual void slot();
private:
    void *m_first;
    void *m_second;
};

Rva007F0080Owner::Rva007F0080Owner(void *first, void *second)
{
    m_first = first ? first : reinterpret_cast<void *>(0x00A5CEC0);
    m_second = second ? second : reinterpret_cast<void *>(0x00A5CED0);
}
