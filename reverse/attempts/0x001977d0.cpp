// ??1HAnimComboClass@@QAE@XZ
// partial score=0.95 date=2026-10-02
// cl: /G7 /arch:SSE /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /O1
class HAnimComboDataClass;

template <class T>
class VectorClass
{
public:
	virtual ~VectorClass()
	{
		if (Vector != 0 && IsAllocated)
		{
			delete[] Vector;
			Vector = 0;
		}
		IsAllocated = false;
		VectorMax = 0;
	}

	T *Vector;			// +0x04
	int VectorMax;			// +0x08
	bool IsValid;			// +0x0c
	bool IsAllocated;		// +0x0d
};

class HAnimComboClass
{
public:
	void Reset();
	~HAnimComboClass();

protected:
	VectorClass<HAnimComboDataClass *> HAnimComboData;
};

HAnimComboClass::~HAnimComboClass()
{
	Reset();
}
