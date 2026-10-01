// ?rva0005824D@MilesAudioManager@@QAEXPAXM@Z
// partial score=0.95 date=2026-09-30
// ?rva0005824D@MilesAudioManager@@QAEXPAXM@Z
// partial score=0.95 date=2026-09-30
// cl: /O1 /G7 /arch:SSE /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /D_STLP_USE_STATIC_LIB
// stlport
// ?rva0005824D@MilesAudioManager@@QAEXPAXM@Z @0x0005824D 199B: volume override with clamp and vector
// Evidence: chain from 0x0004120E MilesMutexGuard; callers none; global 1.0f g_Va00BBB8D8; vector push_back 0x00539A2E rowed; vslot 0x178; offsets 0x9D4 0xB54 0x6AA from Rva0005710F and StopAudio.
#include <vector>

extern float g_Va00BBB8D8;

struct BfmeE8
{
	int key;
	float value;
};

class MilesMutexGuard
{
public:
	MilesMutexGuard(void *mutex, int defer);
	~MilesMutexGuard();
private:
	void *m_mutex;
	bool m_held;
};

class MilesAudioManager
{
public:
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
	virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
	virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
	virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
	virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
	virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
	virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
	virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
	virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
	virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
	virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
	virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
	virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
	virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91();
	virtual void v92(); virtual void v93();
	virtual void vf178(void *key);
	void rva0005824D(void *key, float value);
private:
	char m_pad004[0x6AA - 4];
	bool m_flag6AA;
	char m_pad6AB[0x9D4 - 0x6AB];
	void *m_mutex9D4;
	char m_pad9D8[0xB54 - 0x9D8];
	_STL::vector<BfmeE8> m_vecB54;
};

// ?rva0005824D@MilesAudioManager@@QAEXPAXM@Z present-unmatched
void MilesAudioManager::rva0005824D(void *key, float value)
{
	MilesMutexGuard guard(&m_mutex9D4, 0);
	if (key == 0)
		return;
	if (g_Va00BBB8D8 == value) {
		vf178(key);
		return;
	}
	float v = value;
	float g = g_Va00BBB8D8;
	if (v > g)
		v = g;
	if (v < 0.0f)
		v = 0.0f;
	for (_STL::vector<BfmeE8>::iterator it = m_vecB54.begin(); it != m_vecB54.end(); ++it) {
		if (it->key == (int)key) {
			if (it->value == v)
				goto done;
			it->value = v;
			m_flag6AA = true;
			goto done;
		}
	}
	{
		BfmeE8 e;
		e.key = (int)key;
		e.value = v;
		m_vecB54.push_back(e);
		m_flag6AA = true;
	}
done:
	return;
}
