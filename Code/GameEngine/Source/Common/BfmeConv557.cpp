struct BfmeHolderBZB
{
	void *m_bfmePtr;
};

void bfmeOneBZB(void *what);
void bfmeFreeOneJT(void *what);

void bfmeGoBZB(BfmeHolderBZB *holder)
{
	if (holder->m_bfmePtr != 0)
	{
		bfmeOneBZB(holder->m_bfmePtr);
		bfmeFreeOneJT(holder->m_bfmePtr);
		holder->m_bfmePtr = 0;
	}
}

// Callers elsewhere reach bodies in this unit through other spellings; retail's
// call sites in their matched rows land on these addresses (same ABI). Bind them.
#pragma comment(linker, "/alternatename:?releaseCodecCallback@@YAXPAPAX@Z=?bfmeGoBZB@@YAXPAUBfmeHolderBZB@@@Z")
