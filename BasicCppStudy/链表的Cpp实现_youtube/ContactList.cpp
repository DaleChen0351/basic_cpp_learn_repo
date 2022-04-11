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
void ContactList::insetToList(const string& newName)
{
	ContactNode* newNode = new ContactNode(newName);
	//case one: the list is empty;
	if (this->head == NULL)
	{
		head = newNode;
	}
	else
	{
		ContactNode* currNode = head;
		ContactNode* prevNode = NULL;
		while (currNode != NULL)
		{
			if (currNode->m_name >= newNode->m_name)
			{
				break;
			}
			else
			{
				prevNode = currNode;
				currNode = currNode->next;
			}
		}
		
		//case two: the list is not empty, but the newNode add to the head
		if (currNode == this->head)
		{
			newNode->next = this->head;
			this->head = newNode;
		}
	    //case three: the list is not empyt, but the newNode add to the middle of the list
		else
		{
			newNode->next = currNode;
			prevNode->next = newNode;
		}
	}
}