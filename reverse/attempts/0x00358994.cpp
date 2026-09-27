// ??1DisplayString@@UAE@XZ
// partial score=1.0 date=2026-09-27
// cl: /O1 /MD /EHsc
//
// ??1DisplayString@@UAE@XZ, retail 0x00358994, 57 bytes.
// DisplayString virtual dtor: sets vtable 0x00815338, calls virtual reset
// (pinned ?reset@DisplayString@@UAEXXZ at 0x00358946 which releases +0x04
// via 0x00036E70 and zeroes +0x08), then releases +0x04 again via member
// dtor (no-op on nulled buffer). Called by W3DDisplayString dtor 0x001061AC
// as base at +0x00. Donor: GameClient/DisplayString.h (virtual dtor + reset,
// UnicodeString m_textString + GameFont* m_font + next/prev).
struct MyString {
  ~MyString() { releaseBuffer(); }
  void releaseBuffer();
  unsigned short *m_data;
};
class GameFont;
class DisplayString {
public:
  virtual ~DisplayString();
  virtual void reset();
private:
  MyString m_text;
  GameFont *m_font;
  void *m_next;
  void *m_prev;
};
// ??1DisplayString@@UAE@XZ present-unmatched
DisplayString::~DisplayString()
{
  DisplayString::reset();
}
