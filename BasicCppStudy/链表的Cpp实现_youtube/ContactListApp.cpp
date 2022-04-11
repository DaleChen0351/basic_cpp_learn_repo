#include "ContactList.h"
using namespace std;

int main()
{
	ContactList* cl = new ContactList();


	string name = "";
	while (true)
	{
		cout << "Enter the  name of the contact  or q to quit   " << endl;
		cin >> name;
		if (name == "q")
		{
			break;
		}
		cl->insetToList(name);
	}
	cl->printList ();
	
}