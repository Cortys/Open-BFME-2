// cl: /MD /Oi
// The native GTT writer at 6C8120 calls the graph walk at 6C7DD0; that walk
// tests visited edge pairs through 6C7440. The independent 125B boundary and
// stores show an 8-byte edge array at +10, count at +14, capacity at +18,
// grown in steps of 1000 via the verified profiler realloc. The recovered
// GTT constructor initializes all three fields to zero. Field/method labels
// follow the established GTT factory view; the membership behavior is native.
void *ProfileReAllocMemory(void *memory, unsigned int size);
class ProfileResultInterface
{
public:
	virtual void WriteResults() = 0;
	virtual void Delete() = 0;
};

class ProfileResultFileGTT : public ProfileResultInterface
{
public:
	static ProfileResultInterface *Create(int argn, const char *const *argv);
	ProfileResultFileGTT(const char *fileName, const char *frameName, int percentThreshold);

	virtual void WriteResults();
	virtual void Delete();

	bool MarkVisited(unsigned from, unsigned to);

private:
	struct Edge
	{
		unsigned from;
		unsigned to;
	};

	char *m_fileName;
	char *m_frameName;
	int m_percentThreshold;
	Edge *m_visited;
	unsigned m_numVisited;
	unsigned m_visitedAlloc;
};

bool ProfileResultFileGTT::MarkVisited(unsigned from, unsigned to)
{
    Edge *visited=m_visited;
    Edge *edge=visited;
    for (unsigned i=0;i<m_numVisited;i++,edge++)
        if (edge->from==from && edge->to==to)
            return true;
    if (m_numVisited==m_visitedAlloc)
    {
        m_visitedAlloc+=1000;
        m_visited=(Edge *)ProfileReAllocMemory(visited,m_visitedAlloc*sizeof(Edge));
    }
    m_visited[m_numVisited].from=from;
    m_visited[m_numVisited].to=to;
    m_numVisited++;
    return false;
}
