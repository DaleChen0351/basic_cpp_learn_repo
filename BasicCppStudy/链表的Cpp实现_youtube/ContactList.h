#pragma once

#include "Contact.h"

class ContactList
{
	friend ContactNode;
public:
	ContactList();
	void addToHead(const std::string&);
private:
	ContactNode* head;
	int size;
};
