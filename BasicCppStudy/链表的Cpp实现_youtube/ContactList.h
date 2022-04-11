#pragma once

#include "Contact.h"

class ContactList
{
public:
	ContactList();
	void addToHead(const std::string&);
	void printList();
	void insetToList(const std::string&);
private:
	ContactNode* head;
	int size;
};
