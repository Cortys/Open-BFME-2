// cl: /O1 /MD
// Deleting destructor for the DefaultModule head base whose ??1 was rowed at
// 0x003A57E7 (DefaultModuleHeadBaseDtor.cpp). Public virtual (UAE) to match
// the rowed ??1; same-shape family pattern as FamilyDeletingDtors_0021C7e.cpp.

// ??_GDefaultModuleHeadBase@@UAEPAXI@Z @0x003a57fb
class DefaultModuleHeadBase { public: __declspec(noinline) virtual ~DefaultModuleHeadBase(); private: int m_famgen;
  friend void famgenDelete(DefaultModuleHeadBase *p); };
DefaultModuleHeadBase::~DefaultModuleHeadBase() { m_famgen = 0; }
void famgenDelete(DefaultModuleHeadBase *p) { delete p; }
