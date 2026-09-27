// cl: /O1 /DNDEBUG /MD
//
// ?rva0028AC34@Object@@QAEX_N@Z @0x0028AC34 26B
// Private-status bit setter at Object+0x438 (bit 1). The +0x438 private
// status byte is proven by Object::friend_notifyOfNewMapBoundary
// (retail 0x0028B5EE in Object_friendNotifyOfNewMapBoundary.cpp) and the
// 11 callers of this body. Identity beyond Object+0x438 is unproven so the
// name stays address-derived. Flags from Object setters
// (ObjectSetProducer.cpp /O1 /DNDEBUG /MD); /O1 selects the retail
// cmp-je plus or-byte/and-byte shape.

class Object
{
public:
	void rva0028AC34(bool on);

private:
	unsigned char m_pad00[0x438];
	unsigned char m_privateStatus; // +0x438
};

void Object::rva0028AC34(bool on)
{
	if (on)
		m_privateStatus |= 2;
	else
		m_privateStatus &= ~2;
}
