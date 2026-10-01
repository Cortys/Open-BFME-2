// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD
// Recovered map-preview description update at RVA 0x0057C892.
// Descriptive bfme names do not claim original source spellings. The metadata
// getter calls the cached map.str text loader, then returns its first line.

#include "unicode_string.h"


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
private:
    char m_unmodelled[0x2C];
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
