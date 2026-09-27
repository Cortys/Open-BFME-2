// Doubly-linked list insert with prev at +0x328 and next at +0x32C.
// ?Rva0028A6E7@Rva28A6E7Node@@QAEXPAPAV1@@Z 0x0028A6E7 29B: caller 0x0028A776; neighbours 0x0028A6C7 0x0028A704 share 0x328/0x32C
class Rva28A6E7Node
{
public:
	void Rva0028A6E7(Rva28A6E7Node **head);
	char m_pad[0x328];
	Rva28A6E7Node *m_prev;
	Rva28A6E7Node *m_next;
};

void Rva28A6E7Node::Rva0028A6E7(Rva28A6E7Node **head)
{
	m_next = *head;
	if (*head != 0)
		(*head)->m_prev = this;
	*head = this;
}
