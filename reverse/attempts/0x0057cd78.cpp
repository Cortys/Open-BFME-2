// ?rva0057CD78@AptMapPreview@@QAEXXZ
// partial score=0.9 date=2026-09-28
// ?rva0057CD78@AptMapPreview@@QAEXXZ
// partial score=0.9 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
// Recovered map-preview description update at RVA 0x0057C892.
// Descriptive bfme names do not claim original source spellings. The metadata
// getter calls the cached map.str text loader, then returns its first line.

template <typename T> class StringBase
{
    friend class UnicodeString;
private:
    StringBase(const StringBase<T> &other);
    ~StringBase();
    void *m_data;
};

class UnicodeString : private StringBase<unsigned short>
{
public:
    UnicodeString(const UnicodeString &other) : StringBase<unsigned short>(other) {}
    ~UnicodeString() {}
};

class GameWindow
{
public:
	int winEnable(bool enable);
};
extern "C" void __cdecl free(void *p);
void GadgetListBoxReset(GameWindow *listbox);
int GadgetListBoxAddEntryText(GameWindow *listbox, UnicodeString text,
    int color, int row, int column, bool overwrite);

class MapMetaData
{
public:
    UnicodeString bfme_getDescriptionFirstLine();
};

class AptMapPreview
{
public:
    void bfmeSetMapDescription(MapMetaData *map);
    void rva0057C597(bool show);
    void rva0057CC43(struct Rva0057CC43Node *head);
    void rva0057CD78();
private:
    void *volatile m_head00;
    int m_count04;
    char m_pad08[0x2C - 8];
    GameWindow *m_descriptionList;
    GameWindow *m_windows[8];
};

struct Rva0057CC43Node
{
    char m_pad00[8];
    Rva0057CC43Node *m_next;
    Rva0057CC43Node *m_child;
};

void AptMapPreview::bfmeSetMapDescription(MapMetaData *map)
{
    if (m_descriptionList)
    {
        GadgetListBoxReset(m_descriptionList);
        if (map)
            GadgetListBoxAddEntryText(m_descriptionList,
                map->bfme_getDescriptionFirstLine(), -1, -1, -1, true);
    }
}

void AptMapPreview::rva0057C597(bool show)
{
    for (int i = 0; i < 8; ++i) {
        GameWindow *w = m_windows[i];
        if (w) {
            w->winEnable(show);
        }
    }
}

void AptMapPreview::rva0057CC43(Rva0057CC43Node *head)
{
    for (Rva0057CC43Node *node = head; node; ) {
        rva0057CC43(node->m_child);
        Rva0057CC43Node *next = node->m_next;
        free(node);
        node = next;
    }
}

// ?rva0057CD78@AptMapPreview@@QAEXXZ present-unmatched
void AptMapPreview::rva0057CD78()
{
    if (m_count04 == 0) {
        return;
    }
    Rva0057CC43Node *head = *(Rva0057CC43Node **)((char *)m_head00 + 4);
    rva0057CC43(head);
    Rva0057CC43Node *sentinel = (Rva0057CC43Node *)m_head00;
    sentinel->m_next = sentinel;
    *(int *)((char *)sentinel + 4) = 0;
    sentinel->m_child = sentinel;
    m_count04 = 0;
}
