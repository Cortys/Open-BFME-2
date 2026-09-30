// ?rva0031B53D@Rva0031B53D@@QAEEXZ
// partial score=0.95 date=2026-09-30
// ?rva0031B53D@Rva0031B53D@@QAEEXZ
// partial score=0.95 date=2026-09-30
// cl: /O1 /EHsc
// ?rva0031B53D@Rva0031B53D@@QAEEXZ @0x0031B53D 102B: thiscall uchar method building a stack INI then tailing through Rva0031B4D6Load with type (m_flag ? 5 : 1). Evidence: chain from just-landed 0x0031B4D6 caller bytes plus xor/setne/lea type select plus EH prolog with INI ctor/dtor pins.
class INI {
public:
  INI();
  ~INI();
private:
  char m_data[0x87C];
};
class Rva0031B53D {
public:
  unsigned char rva0031B53D();
private:
  int m_pad0;
  unsigned char m_flag;
};
unsigned char __stdcall Rva0031B4D6Load(INI *ini, int type);
unsigned char Rva0031B53D::rva0031B53D()
{
  INI ini;
  unsigned char flag = m_flag;
  int t = (flag != 0);
  unsigned char r = Rva0031B4D6Load(&ini, t * 4 + 1);
  return r;
}
