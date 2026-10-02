// cl: /Od
// Siblings of the BfmeConv1428 wrapper recipe. Both are thin thiscall
// forwarders: the first hands its first two arguments to the private
// _M_range_initialize pinned at 0x000078C0 with a materialised iterator tag,
// and the second is the bfmeMakeOX run wrapper for Rva0002A270Thing (the same
// computed-length shape as Rva00028BC0Cluster.cpp). Names are address-derived.

int bfmeMakeOX(void *text);

class Rva00029F80
{
public:
	void rva00029f80(const char *first, const char *last, int unused);

private:
	void rva00078c0(const char *first, const char *last, void *tag);
};

void Rva00029F80::rva00029f80(const char *first, const char *last, int unused)
{
	char tag;
	int pad[4];
	rva00078c0(first, last, &tag);
}

class Rva0002A270Thing
{
public:
	void bfmeDoPF(char *at, void *what, int many);
	void rva0002a2a0(void *at, void *what);
};

void Rva0002A270Thing::rva0002a2a0(void *at, void *what)
{
	bfmeDoPF((char *)at, what, bfmeMakeOX(at));
}
