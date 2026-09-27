// cl: /O1 /MD
// ??_GCDownload@@QAEPAXI@Z @0x005E046F 28B: deleting dtor calls the rowed
// ??1CDownload@@QAE@XZ at 0x006C9730 then rowed operator delete 0x0002FD60
// on flag; chain-unlocked by the CDownload dtor landing.
class CDownload
{
public:
	~CDownload();
};

void CDownload_Delete(CDownload *p) { delete p; }
