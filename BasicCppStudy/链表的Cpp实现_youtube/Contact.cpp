#include "Contact.h"

std::ostream & operator<<(std::ostream & os, const ContactNode & c)
{
	return os << "name = " << c.m_name;
}

ContactNode::ContactNode(std::string n):m_name(n),next(NULL)
{
}
