// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc

typedef int Int;

class NetCommandMsg
{
public:
	Int m_unknown00[3];
	Int m_playerID;
};

class NetCommandNode
{
public:
	void detach();
};

class NetCommandRef
{
public:
	NetCommandMsg *getCommand() { return m_msg; }
	NetCommandRef *getNext() { return m_next; }
	~NetCommandRef() { ((NetCommandNode *)this)->detach(); }

	NetCommandMsg *m_msg;
	NetCommandRef *m_next;
};

class NetCommandList
{
public:
	NetCommandRef *getFirstMessage() { return m_first; }
	void removeMessage(NetCommandRef *message);

	void *m_vptr;
	NetCommandRef *m_first;
};

class Connection
{
public:
	void clearCommandsExceptFrom(Int playerIndex);

	char m_unknown00[0x18];
	NetCommandList *m_netCommandList;
};

void Connection::clearCommandsExceptFrom(Int playerIndex)
{
	NetCommandRef *tmp = m_netCommandList->getFirstMessage();
	while (tmp != 0)
	{
		if (tmp->getCommand()->m_playerID != playerIndex)
		{
			m_netCommandList->removeMessage(tmp);
			NetCommandRef *toDelete = tmp;
			tmp = tmp->getNext();
			delete toDelete;
		}
		else
		{
			tmp = tmp->getNext();
		}
	}
}
