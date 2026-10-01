// cl: /O1 /DNDEBUG /MD
//
// ?rva00262BA9@AIUpdateInterface@@QAE_NXZ, retail 0x00262BA9, 67 bytes.
// ?rva00262BEC@AIUpdateInterface@@QAE_NXZ, retail 0x00262BEC, 39 bytes.
// AIUpdateInterface methods checking path state for locomotorGoalType 1 or 4.

class Rva001E3591
{
public:
	bool rva001E3591();
};

class Rva003638BA : public Rva001E3591
{
public:
	bool rva003638BA();
	bool rva00262176();
};

class AIUpdateInterface
{
	char m_pad00[0x140];
	Rva003638BA *m_path; // +0x140
	char m_pad144[0x1F0 - 0x144];
	int m_field1F0; // +0x1F0
	char m_pad1F4[0x1FC - 0x1F4];
	int m_locomotorGoalType; // +0x1FC
public:
	bool rva00262BA9();
	bool rva00262BEC();
};

bool AIUpdateInterface::rva00262BA9()
{
	if (!m_field1F0)
		return false;

	switch (m_locomotorGoalType)
	{
	case 1:
	case 4:
		if (Rva003638BA *path = m_path)
		{
			if (path->rva001E3591())
				return true;
			if (path->rva00262176())
				return true;
		}
		break;
	}
	return false;
}

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

