// cl: /O1 /MD
// ??_GUserParser@@UAEPAXI@Z @0x00307382 28B
// Deleting dtor slot 0 of vtable 0x00807EB0; calls rowed ??1 at 0x0030739E then rowed operator delete at 0x0002FD60.
class UserParser { public: __declspec(noinline) virtual ~UserParser(); private: int m_famgen; };
UserParser::~UserParser() { m_famgen = 0; }
void famgenDelete(UserParser *p) { delete p; }
