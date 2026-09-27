// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0028B85B@Object@@QBE?AW4ObjectID@@XZ, retail 0x0028B85B, 26 bytes.
// Object ObjectID reader through the body at +0x254: calls the body vtable
// slot 0x3C, when non-null returns its dword at +8, else INVALID_ID.
// Evidence: caller at 0x0026A085 pushes the result to findObjectByID which
// takes W4ObjectID; +0x254 body proven by Object_attemptHealing; slot 0x3C is
// the retail call immediate; twin null checks share the xor-ret. Name stays
// address-derived; true method name unproven.
enum ObjectID
{
	INVALID_ID = 0
};

struct Rva0028B85BResult
{
	char m_pad[8];
	ObjectID m_id;
};

class BodyModuleInterface
{
public:
	virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
	virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
	virtual void slot08(); virtual void slot09(); virtual void slot10(); virtual void slot11();
	virtual void slot12(); virtual void slot13(); virtual void slot14();
	virtual Rva0028B85BResult *slot15();
};

class Object
{
	char m_pad[0x254];
	BodyModuleInterface *m_body;

public:
	ObjectID rva0028B85B() const;
};

ObjectID Object::rva0028B85B() const
{
	BodyModuleInterface *body = m_body;
	if (body != 0)
	{
		Rva0028B85BResult *result = body->slot15();
		if (result != 0)
			return result->m_id;
	}
	return INVALID_ID;
}
