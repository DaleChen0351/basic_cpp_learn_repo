#pragma once

#include <string>
#include <iostream>


class ContactNode
{
	friend std::ostream& operator<<(std::ostream& os, const ContactNode& c);
	friend class ContactList;
public:
	ContactNode(std::string name);
private:
	std::string m_name;
	ContactNode* next;

};

