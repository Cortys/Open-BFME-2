// cl: /O1 /DNDEBUG /MD
//
// ?rva00262BEC@AIUpdateInterface@@QAE_NXZ, retail 0x00262BEC, 39 bytes.
// AIUpdateInterface method: checks if m_locomotorGoalType is 1 or 4, and if so
// tests if m_path is non-null and calls Path::rva003638BA().

class Rva003638BA
{
public:
	bool rva003638BA();
};

class AIUpdateInterface
{
	char m_pad00[0x140];
	Rva003638BA *m_path; // +0x140
	char m_pad144[0x1FC - 0x144];
	int m_locomotorGoalType; // +0x1FC
public:
	bool rva00262BEC();
};

bool AIUpdateInterface::rva00262BEC()
{
	switch (m_locomotorGoalType)
	{
	case 1:
	case 4:
		if (m_path && m_path->rva003638BA())
			return true;
		break;
	}
	return false;
}
