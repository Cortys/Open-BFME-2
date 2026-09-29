// cl: /O1 /DNDEBUG /MD
// ?buildFieldParse@Rva00238AB6@@SAXAAVMultiIniFieldParse@@@Z @0x00238AB6 17B single add table 0x00BED3E0 offset 0.
// Evidence: unlock lane single-table shape via rowed add 0x0002BC6E; caller 0x0004171A.
class MultiIniFieldParse;
struct FieldParse;
class MultiIniFieldParse
{
public:
	void add(const FieldParse *parse, unsigned int extraOffset);
};
class Rva00238AB6
{
public:
	static void buildFieldParse(MultiIniFieldParse &parse);
};
void Rva00238AB6::buildFieldParse(MultiIniFieldParse &parse)
{
	parse.add(reinterpret_cast<const FieldParse *>(0x00BED3E0), 0);
}
