// cl: /O1 /MD
// ??0Rva0065CA4@@QAE@XZ @0x00065D40 18B ctor calls GenericMultiListClass base then vtable
// Stores vtable 0x007C5C78 at [this] after calling rowed base ctor at 0x00065815; caller 0x00049EE6; layout matches dtor pin at 0x00065CA4 with same vtable
class GenericMultiListClass
{
public:
	GenericMultiListClass();
	virtual ~GenericMultiListClass();
};
class Rva0065CA4 : public GenericMultiListClass
{
public:
	Rva0065CA4();
	virtual ~Rva0065CA4();
};
Rva0065CA4::Rva0065CA4()
{
}
