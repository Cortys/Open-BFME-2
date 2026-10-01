// ?lookup@Rva00DFF024Registry@@QAEPAXHH@Z
// partial score=0.72 date=2026-10-01
// cl: /O1 /MD
//
// ?lookup56@Rva00DFF024Registry@@QAEPAXHH@Z
// RVA 0x002D2371 size 48. Pinned fallback lookup; tries (a 5) then (a 6) when
// b is -1 else (a b). Evidence: pin name; callers at 0x22329A (unclaimed) and
// 0x3163DA in parseWinClass; callee lookup at 0x2D225F via pin; neighbours in
// GameEngineDeletingBaseDerived.cpp share /O1 /MD.

class Rva00DFF024Registry
{
public:
    void *lookup(int a, int b);
    void *lookup56(int a, int b);
    void *lookup34(int a, int b);
    void *rva002D2235(int key, void *slot);

private:
    char m_header[12];
    void *m_slots[12];
};

struct Rva002D2235Entry
{
    int key;
    int name;
    void *callback;
};

void *Rva00DFF024Registry::lookup56(int a, int b)
{
    if (b == -1) {
        void *r = lookup(a, 5);
        if (r)
            return r;
        return lookup(a, 6);
    }
    return lookup(a, b);
}

void *Rva00DFF024Registry::rva002D2235(int key, void *slot)
{
    if (key == 0)
        return 0;

    Rva002D2235Entry *entry = (Rva002D2235Entry *)slot;
    if (entry == 0)
        return 0;

    while (entry->key != 0) {
        if (entry->key == key)
            return entry->callback;
        ++entry;
    }
    return 0;
}

void *Rva00DFF024Registry::lookup(int key, int index)
{
    if (key == 0)
        return 0;

    if (index == -1) {
        int i = 0;
        void **slot = m_slots;
        do {
            void *result = rva002D2235(key, *slot);
            if (result)
                return result;
            ++i;
            ++slot;
        } while (i < 12);
        return 0;
    }

    return rva002D2235(key, m_slots[index]);
}

void *Rva00DFF024Registry::lookup34(int a, int b)
{
    if (b == -1) {
        void *r = lookup(a, 3);
        if (r)
            return r;
        return lookup(a, 4);
    }
    return lookup(a, b);
}
