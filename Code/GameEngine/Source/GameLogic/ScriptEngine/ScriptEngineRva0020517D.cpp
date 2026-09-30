// cl: /O1 /EHsc
// ?rva0020517D@ScriptEngine@@QAEXPAVObject@@@Z @0x0020517D 58B: remove sequential scripts for an object.
// Evidence: caller 0x003BC259 passes getUnitNamed Object*; loops m_sequentialScripts +0x10..+0x14 calling rowed cleanupSequentialScript 0x00204733 with (it,1,1) when slot empty or +8 matches Object+0x74; same shape as siblings 0x00205140 and 0x002051B7.
class SequentialScript
{
public:
	char m_pad[8];
	int m_8; // +0x08 match key
	char m_padC[4]; // +0x0C..0x0F
	bool m_10; // +0x10 gate
	char m_pad11[3]; // +0x11..0x13
	SequentialScript *m_14; // +0x14 link
};

class Object
{
public:
	char m_pad[0x74];
	int m_74; // +0x74 match key
};

class ScriptEngine
{
protected:
	SequentialScript **cleanupSequentialScript(SequentialScript **it, bool cleanDanglers, bool removeEntry);
public:
	void rva0020517D(Object *obj);
	void rva00205140(SequentialScript *arg);
private:
	char m_pre[0x10];
	SequentialScript **m_begin; // +0x10
	SequentialScript **m_end; // +0x14
};

void ScriptEngine::rva0020517D(Object *obj)
{
	if (!obj)
		return;
	int id = obj->m_74;
	SequentialScript **it = m_begin;
	while (it != m_end) {
		SequentialScript *s = *it;
		if (!s || s->m_8 == id)
			it = cleanupSequentialScript(it, true, true);
		else
			++it;
	}
}

void ScriptEngine::rva00205140(SequentialScript *arg)
{
	if (!arg)
		return;
	if (!arg->m_10)
		return;
	SequentialScript **it = m_begin;
	while (it != m_end) {
		SequentialScript *s = *it;
		if (s && s->m_14 == arg)
			it = cleanupSequentialScript(it, true, true);
		else
			++it;
	}
}
