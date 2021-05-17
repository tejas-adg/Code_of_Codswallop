#pragma once
#ifndef _SINGLE_LINKED_LIST_H_
#define _SINGLE_LINKED_LIST_H_

#include "Nodes.h"
#include <iostream>

template<typename T>
class Single_Linked_List
{
private:
	Single_Link_Node<T>* tail;
	Single_Link_Node<T>* head;
	int number_of_nodes;

public:
	Single_Linked_List();
	~Single_Linked_List();

	void addItem(Single_Link_Node<T>* node_ptr, int pos = 0);
	Single_Link_Node<T>* removeItemByPosition(int pos = 0);
	Single_Link_Node<T>* removeItemByData(T* _obj = nullptr);
	Single_Link_Node<T>* removeItemByData(T obj);
	Single_Link_Node<T>* searchByData(T obj, int* ret_pos = nullptr);
	Single_Link_Node<T>* searchByPosition(int pos = 0);
	int getNumberOfNodes(void);
	void Clear_List(void);
	void Reverse_List(void);
	void Print_List(void);
	bool isEmpty(void);
};

template<typename T>
void Single_Linked_List<T>::Reverse_List()
{
	Single_Link_Node<T>* temp_var = head;
	head = tail;
	tail = temp_var;
}

template<typename T>
void Single_Linked_List<T>::Clear_List()
{
	Single_Link_Node<T>* curr_node = head;
	Single_Link_Node<T>* prev_node = nullptr;

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
Single_Link_Node<T>* Single_Linked_List<T>::searchByPosition(int pos)
{
	if ((pos == 0) || (pos == (-1 * (number_of_nodes))))
	{
		return head;
	}
	else
	{
		Single_Link_Node<T>* curr_node = head;
		int curr_pos = 0;

		while (curr_node != nullptr)
		{
			if (curr_pos == pos)
			{
				break;
			}
			curr_node = curr_node->getNextNode();
			curr_pos++;
		}

		return curr_node;
	}
}

template<typename T>
Single_Link_Node<T>* Single_Linked_List<T>::searchByData(T obj, int* ret_pos)
{
	Single_Link_Node<T>* curr_node = head;
	int curr_pos = 0;

	while (curr_node != nullptr)
	{
		if (curr_node->getData() == obj)
		{
			break;
		}

		curr_node = curr_node->getNextNode();
		curr_pos++;
	}

	(*ret_pos) = curr_pos;

	return curr_node;
}

template<typename T>
Single_Link_Node<T>* Single_Linked_List<T>::removeItemByData(T obj)
{
	T temp = obj;
	return removeItemByData(&temp);
}

template<typename T>
Single_Link_Node<T>* Single_Linked_List<T>::removeItemByPosition(int pos)
{
	if ((pos == 0) || (pos == (-1 * (number_of_nodes))))
	{
		Single_Link_Node<T>* curr_node = head;
		head = head->getNextNode();
		number_of_nodes--;
		return curr_node;
	}
	else
	{
		Single_Link_Node<T>* curr_node = head;
		int curr_pos = 0;

		while ((curr_node != nullptr) && (curr_pos < ((pos >= 0) ? (pos - 1) : (number_of_nodes + (pos - 1)))))
		{
			curr_node = curr_node->getNextNode();
			curr_pos++;
		}

		Single_Link_Node<T>* temp_node = curr_node->getNextNode();
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
Single_Link_Node<T>* Single_Linked_List<T>::removeItemByData(T* _obj)
{
	Single_Link_Node<T>* curr_node = head;
	Single_Link_Node<T>* prev_node = nullptr;

	while (curr_node != nullptr)
	{
		if (curr_node->getData() == (*_obj))
		{
			break;
		}

		prev_node = curr_node;
		curr_node = curr_node->getNextNode();
	}

	if (curr_node == nullptr)
	{
		return nullptr;
	}
	else
	{
		prev_node->setNextNode(curr_node->getNextNode());

		if (curr_node == tail)
		{
			tail = prev_node;
		}

		number_of_nodes--;

		return curr_node;
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
	Single_Link_Node<T>* curr_node = head;
	Single_Link_Node<T>* prev_node = nullptr;

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
void Single_Linked_List<T>::addItem(Single_Link_Node<T>* node_ptr, int pos)
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
		Single_Link_Node<T>* curr_node = head;
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

	Single_Link_Node<T>* temp = head;

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