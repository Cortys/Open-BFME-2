// cl: /O1 /MD
// ??1BfmeStringTailRecord156@@QAE@XZ @0x0010F149 12B. Non-virtual dtor:
// if (m_ptr) m_ptr->Release_Ref() tail-jmp to rowed
// ?Release_Ref@OpaqueRefCounted@@QAEXXZ. Pins name the dtor; callers include
// FamilyDeletingDtors2 ??_G plus STL destroy helpers.
class OpaqueRefCounted {
public:
	void Release_Ref();
};
class BfmeStringTailRecord156 {
public:
	~BfmeStringTailRecord156();
private:
	OpaqueRefCounted *m_ptr;
};
BfmeStringTailRecord156::~BfmeStringTailRecord156()
{
	if (m_ptr)
		m_ptr->Release_Ref();
}
