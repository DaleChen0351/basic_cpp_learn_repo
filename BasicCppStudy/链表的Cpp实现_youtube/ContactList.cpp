#include "ContactList.h"
using namespace std;

ContactList::ContactList() :head(NULL), size(0) {

}

void ContactList::addToHead(const string& name)
{
	ContactNode* newNode = new ContactNode(name);

	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	size++;
}
void ContactList::printList()
{
	ContactNode* tp = this->head;
	while (tp != NULL)
	{
		cout << *tp << endl;
		tp = tp->next;
	}
}