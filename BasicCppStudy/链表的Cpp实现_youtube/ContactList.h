#pragma once

#include "Contact.h"

class ContactList
{
public:
	ContactList();
	void addToHead(const std::string&);
	void printList();
private:
	ContactNode* head;
	int size;
};
