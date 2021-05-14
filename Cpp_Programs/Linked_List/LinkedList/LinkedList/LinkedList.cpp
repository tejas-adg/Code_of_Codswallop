#include "Single_Linked_List.h"

using namespace std;

int main()
{
	Single_Linked_List<char> s_ll;

	s_ll.addItem(Single_Link_Node<char>::createNode('t'));

	s_ll.addItem(Single_Link_Node<char>::createNode('e'), 1);

	s_ll.addItem(Single_Link_Node<char>::createNode('j'), 2);

	s_ll.addItem(Single_Link_Node<char>::createNode('a'), 3);

	s_ll.addItem(Single_Link_Node<char>::createNode('s'), 4);

	s_ll.addItem(Single_Link_Node<char>::createNode('Z'), 3);
	
	s_ll.Print_List(); cout << endl;

	delete s_ll.removeItemByPosition(-2);

	s_ll.Print_List(); cout << endl;

	delete s_ll.removeItemByPosition(-4);

	s_ll.Print_List(); cout << endl;

	delete s_ll.removeItemByPosition(-1);

	s_ll.Print_List(); cout << endl;
}