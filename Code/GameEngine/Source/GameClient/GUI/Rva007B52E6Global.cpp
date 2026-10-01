// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD
// Target GUI-string global: startup 0x007B52E6 uses "UpgradeUnitButton",
// constructs the address-named object at VA0x00E06900 through rowed5E16DA,
// and registers the cleanup at0x007B9A05. Its application class name is unknown.
// Constructor and destructor ABI reuse the existing recovered Rva005E16DA
// bodies; their four post-vptr words cover the observed 20-byte object.
// The constructor's existing int declaration is a one-word ABI view. Retail
// passes the ADDRESS of an AsciiString temporary, not an integer identifier.

class Rva005E16DA {
public:
    Rva005E16DA(int argumentWord);
    virtual ~Rva005E16DA();
private:
    unsigned int opaqueWords[4];
};

extern Rva005E16DA g_rva00E06900;

void rva007B9A05()
{
    g_rva00E06900.~Rva005E16DA();
}
