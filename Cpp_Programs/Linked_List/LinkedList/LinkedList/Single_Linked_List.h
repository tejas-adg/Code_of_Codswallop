#pragma once
#ifndef _SINGLE_LINKED_LIST_H_
#define _SINGLE_LINKED_LIST_H_

#include "Nodes.h"
#include <iostream>

#ifndef POINTER_DECLARING_SYMBOL
#define POINTER_DECLARING_SYMBOL *
#endif

#ifndef POINTER_TO_POINTER_DECLARING_SYMBOL
#define POINTER_TO_POINTER_DECLARING_SYMBOL **
#endif

#ifndef DECLARE_NODE_POINTER
#define DECLARE_NODE_POINTER Single_Link_Node<T>##POINTER_DECLARING_SYMBOL
#endif

#ifndef DECLARE_POINTER_TO_NODE_POINTER
#define DECLARE_POINTER_TO_NODE_POINTER Single_Link_Node<T>##POINTER_TO_POINTER_DECLARING_SYMBOL
#endif

template<typename T>
class Single_Linked_List
{
private:
	DECLARE_NODE_POINTER tail;
	DECLARE_NODE_POINTER head;
	int number_of_nodes;

public:
	Single_Linked_List();
	~Single_Linked_List();

	void addItem(DECLARE_NODE_POINTER node_ptr, int pos = 0);
	DECLARE_NODE_POINTER removeItemByPosition(int pos = 0);
	DECLARE_NODE_POINTER removeItemByData(T obj);
	DECLARE_NODE_POINTER searchByData(T POINTER_DECLARING_SYMBOL _obj, int POINTER_DECLARING_SYMBOL ret_pos = nullptr, DECLARE_POINTER_TO_NODE_POINTER one_prev_node = nullptr);
	DECLARE_NODE_POINTER searchByPosition(int pos = 0, DECLARE_POINTER_TO_NODE_POINTER one_prev_node = nullptr);
	int getNumberOfNodes(void);
	void Clear_List(void);
	void Reverse_List(void);
	void Print_List(void);
	bool isEmpty(void);
};

template<typename T>
void Single_Linked_List<T>::Reverse_List()
{
	DECLARE_NODE_POINTER curr_node = head;
	DECLARE_NODE_POINTER prev_node = nullptr;
	DECLARE_NODE_POINTER next_node = head->getNextNode();;
	tail = head;

	while (curr_node != nullptr)
	{
		next_node = curr_node->getNextNode();

		curr_node->setNextNode(prev_node);

		prev_node = curr_node;
		curr_node = next_node;
	}

	head = prev_node;
}

template<typename T>
void Single_Linked_List<T>::Clear_List()
{
	DECLARE_NODE_POINTER curr_node = head;
	DECLARE_NODE_POINTER prev_node = nullptr;

	while (curr_node != nullptr)
	{
		prev_node = curr_node;
		curr_node = curr_node->getNextNode();
		delete prev_node;
	}

	head = nullptr;
	number_of_nodes = 0;
}

template<typename T>
DECLARE_NODE_POINTER Single_Linked_List<T>::searchByPosition(int pos, DECLARE_POINTER_TO_NODE_POINTER one_prev_node)
{
	if ((pos == 0) || (pos == (-1 * (number_of_nodes))))
	{
		return head;
	}
	else if ((pos == -1) || (pos == number_of_nodes))
	{
		return tail;
	}
	else
	{
		DECLARE_NODE_POINTER curr_node = head;
		DECLARE_NODE_POINTER prev_node = nullptr;
		int curr_pos = 0;

		while (curr_node != nullptr)
		{
			if (curr_pos == pos)
			{
				break;
			}
			prev_node = curr_node;
			curr_node = curr_node->getNextNode();
			curr_pos++;
		}

		if (one_prev_node != nullptr)
		{
			(*one_prev_node) = prev_node;
		}

		return curr_node;
	}
}

template<typename T>
DECLARE_NODE_POINTER Single_Linked_List<T>::searchByData(T POINTER_DECLARING_SYMBOL _obj, int POINTER_DECLARING_SYMBOL ret_pos, DECLARE_POINTER_TO_NODE_POINTER one_prev_node)
{
	DECLARE_NODE_POINTER curr_node = head;
	DECLARE_NODE_POINTER prev_node = nullptr;
	int curr_pos = 0;

	while (curr_node != nullptr)
	{
		if (curr_node->getData() == (*_obj))
		{
			break;
		}

		prev_node = curr_node;
		curr_node = curr_node->getNextNode();
		curr_pos++;
	}

	if (one_prev_node != nullptr)
	{
		(*one_prev_node) = prev_node;
	}

	if (ret_pos != nullptr)
	{
		(*ret_pos) = curr_pos;
	}

	return curr_node;
}

template<typename T>
DECLARE_NODE_POINTER Single_Linked_List<T>::removeItemByPosition(int pos)
{
	if ((pos == 0) || (pos == (-1 * (number_of_nodes))))
	{
		DECLARE_NODE_POINTER curr_node = head;
		head = head->getNextNode();
		number_of_nodes--;
		return curr_node;
	}
	else
	{
		DECLARE_NODE_POINTER curr_node = head;
		int curr_pos = 0;

		while ((curr_node != nullptr) && (curr_pos < ((pos >= 0) ? (pos - 1) : (number_of_nodes + (pos - 1)))))
		{
			curr_node = curr_node->getNextNode();
			curr_pos++;
		}

		DECLARE_NODE_POINTER temp_node = curr_node->getNextNode();
		curr_node->setNextNode(curr_node->getNextNode()->getNextNode());

		if (temp_node == tail)
		{
			tail = curr_node;
		}

		number_of_nodes--;

		return temp_node;
	}
}

template<typename T>
DECLARE_NODE_POINTER Single_Linked_List<T>::removeItemByData(T obj)
{
	DECLARE_NODE_POINTER retn_node = head;
	DECLARE_NODE_POINTER prev_node = nullptr;

	retn_node = searchByData(&obj, nullptr, &prev_node);

	if (retn_node == nullptr)
	{
		return nullptr;
	}
	else if (retn_node == head)
	{
		head = head->getNextNode();
		number_of_nodes--;
		return retn_node;
	}
	else if (retn_node == tail)
	{
		tail = prev_node;
		number_of_nodes--;
		return retn_node;
	}
	else
	{
		prev_node->setNextNode(retn_node->getNextNode());

		number_of_nodes--;

		return retn_node;
	}
}

template<typename T>
int Single_Linked_List<T>::getNumberOfNodes()
{
	return number_of_nodes;
}

template<typename T>
Single_Linked_List<T>::Single_Linked_List()
{
	head = nullptr;
	tail = nullptr;
	number_of_nodes = 0;
}

template<typename T>
Single_Linked_List<T>::~Single_Linked_List()
{
	DECLARE_NODE_POINTER curr_node = head;
	DECLARE_NODE_POINTER prev_node = nullptr;

	while (curr_node != nullptr)
	{
		prev_node = curr_node;
		curr_node = curr_node->getNextNode();
		delete prev_node;
	}

	head = nullptr;
	number_of_nodes = 0;
}

template<typename T>
void Single_Linked_List<T>::addItem(DECLARE_NODE_POINTER node_ptr, int pos)
{
	if (node_ptr == nullptr)
	{
		return;
	}

	if (isEmpty())
	{
		head = node_ptr;
		tail = node_ptr;
		number_of_nodes++;
		return;
	}
	else if ((pos == 0) || (pos == (-1 * (number_of_nodes + 1))))
	{
		node_ptr->setNextNode(head);
		head = node_ptr;
		number_of_nodes++;
		return;
	}
	else if ((pos == -1) || (pos == number_of_nodes))
	{
		tail->setNextNode(node_ptr);
		tail = node_ptr;
		number_of_nodes++;
		return;
	}
	else
	{
		DECLARE_NODE_POINTER curr_node = head;
		int curr_pos = 0;

		while ((curr_node != nullptr) && (curr_pos < ((pos >= 0) ? (pos - 1) : (number_of_nodes + pos))))
		{
			curr_node = curr_node->getNextNode();
			curr_pos++;
		}

		node_ptr->setNextNode(curr_node->getNextNode());
		curr_node->setNextNode(node_ptr);

		number_of_nodes++;
	}	
}

template<typename T>
void Single_Linked_List<T>::Print_List()
{
	if (isEmpty())
	{
		std::cout << "List is empty";
	}

	DECLARE_NODE_POINTER temp = head;

	while (temp != nullptr)
	{
		std::cout << temp->getData() << " -> ";
		temp = temp->getNextNode();
	}
}

template <typename T>
bool Single_Linked_List<T>::isEmpty()
{
	return (number_of_nodes == 0);
}

#endif