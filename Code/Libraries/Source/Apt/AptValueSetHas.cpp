// The donor PDB names this AptValueSet<AptValue *>::has. Target instructions
// establish a 16-bit count at +2 and an array pointer at +4; target callers
// pass AptValue pointers after checking AptValue::isCIH. Field names and the
// read-only qualifier are source-level descriptions, not binary symbols.
class AptValue;

template <class T>
class AptValueSet
{
public:
	bool has(T value) const
	{
		const int count = m_count;
		int index = 0;
		if (count > 0)
		{
			T *item = m_items;
			do
			{
				if (*item == value)
					return true;
				++index;
				++item;
			} while (index < count);
		}
		return false;
	}

private:
	unsigned short m_reserved;
	unsigned short m_count;
	T *m_items;
};

template class AptValueSet<AptValue *>;
