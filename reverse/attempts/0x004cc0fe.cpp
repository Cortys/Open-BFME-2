// ??1ModelConditionAudioLoopClientBehavior@@UAE@XZ
// partial score=0.93 date=2026-09-26
// ??1ModelConditionAudioLoopClientBehavior@@UAE@XZ
// partial score=0.93 date=2026-09-26
// cl: /O1 /DNDEBUG /MD /EHsc

class Rva004CBF9A
{
public:
	void clear();
};

class OpaqueRefCounted
{
public:
	void Release_Ref();
};

struct AudioHolder
{
	~AudioHolder()
	{
		if (m_ptr)
			m_ptr->Release_Ref();
	}

	OpaqueRefCounted *m_ptr;
};

namespace FXParticleSystem
{
class WindModuleInfo
{
public:
	virtual ~WindModuleInfo();
};
}

class PrimaryCaller
{
public:
	virtual void b0();
	~PrimaryCaller()
	{
		*(const void **)this = reinterpret_cast<const void *>(0x00BEFE48);
		((FXParticleSystem::WindModuleInfo *)this)->~WindModuleInfo();
	}

private:
	unsigned char m_pad[8];
};

class B1
{
public:
	virtual void b1();
};

class B2
{
public:
	virtual void b2();
};

class ModelConditionAudioLoopClientBehavior : public PrimaryCaller, public B1, public B2
{
public:
	virtual ~ModelConditionAudioLoopClientBehavior();

private:
	int m_14;
	AudioHolder m_18;
};

// ??1ModelConditionAudioLoopClientBehavior@@UAE@XZ present-unmatched
ModelConditionAudioLoopClientBehavior::~ModelConditionAudioLoopClientBehavior()
{
	((Rva004CBF9A *)this)->clear();
}
