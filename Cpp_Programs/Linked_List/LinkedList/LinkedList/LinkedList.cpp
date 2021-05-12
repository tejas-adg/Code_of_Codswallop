#include "Single_Linked_List.h"

using namespace std;

int main()
{
	Single_Linked_List<int> s_ll;

	Single_Link_Node<int>* new_sln_ptr = new Single_Link_Node<int>();
	new_sln_ptr->setData(0);

	s_ll.addItem(new_sln_ptr);

	//s_ll.Print_List(); cout << endl;

	new_sln_ptr = new Single_Link_Node<int>();
	new_sln_ptr->setData(1);

	s_ll.addItem(new_sln_ptr, 1);

	//s_ll.Print_List(); cout << endl;

	new_sln_ptr = new Single_Link_Node<int>();
	new_sln_ptr->setData(2);

	s_ll.addItem(new_sln_ptr, 2);

	new_sln_ptr = new Single_Link_Node<int>();
	new_sln_ptr->setData(3);

	s_ll.addItem(new_sln_ptr, 3);

	new_sln_ptr = new Single_Link_Node<int>();
	new_sln_ptr->setData(4);

	s_ll.addItem(new_sln_ptr, 4);

	new_sln_ptr = new Single_Link_Node<int>();
	new_sln_ptr->setData(5);

	s_ll.addItem(new_sln_ptr, 3);

	s_ll.Print_List(); cout << endl;
}