#pragma once
#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include "Nodes.h"
#include <iostream>

template<typename T>
class Doubly_Linked_List
{
private:
	Double_Link_Node<T>* head;
	Double_Link_Node<T>* tail;
	int number_of_nodes;

public:
	Doubly_Linked_List();
	~Doubly_Linked_List();

	Double_Link_Node<T>* removeItemByPosition(int pos = 0);
	Double_Link_Node<T>* removeItemByData(T obj);
	Double_Link_Node<T>* searchByData(T* _obj, int* ret_pos = nullptr);
	Double_Link_Node<T>* searchByPosition(int pos = 0);
	int getNumberOfNodes(void);
	void addItem(Double_Link_Node<T>* node_ptr, int pos = 0);
	void Clear_List(void);
	void Reverse_List(void);
	void Print_List(void);
	bool isEmpty(void);
};

template<typename T>
Double_Link_Node<T>* Doubly_Linked_List<T>::searchByPosition(int pos)
{
	Double_Link_Node<T>* temp = nullptr;
	int curr_pos = 0;

	if (pos <= ((pos > 0) ? (int)(number_of_nodes / 2) : (-1 * ((int)(number_of_nodes / 2) + 1))))
	{
		temp = head;
		curr_pos = (pos > 0) ? 0 : (-1 * number_of_nodes);

		while ((temp != nullptr) && (curr_pos < ((pos > 0) ? (pos) : (pos + 1))))
		{
			temp = temp->getNextNode();
			curr_pos++;
		}
	}
	else
	{
		temp = tail;
		curr_pos = (pos > 0) ? (number_of_nodes - 1) : -2;

		while ((temp != nullptr) && (curr_pos > pos))
		{
			temp = temp->getPreviousNode();
			curr_pos--;
		}
	}

	return temp;
}

template<typename T>
void Doubly_Linked_List<T>::addItem(Double_Link_Node<T>* node_ptr, int pos)
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
		head->setPreviousNode(node_ptr);
		head = node_ptr;
		number_of_nodes++;
		return;
	}
	else if ((pos == -1) || (pos == number_of_nodes))
	{
		tail->setNextNode(node_ptr);
		node_ptr->setPreviousNode(tail);
		tail = node_ptr;
		number_of_nodes++;
		return;
	}
	else
	{
		Double_Link_Node<T>* curr_node = searchByPosition(pos);

		node_ptr->setPreviousNode(curr_node->getPreviousNode());
		node_ptr->setNextNode(curr_node);
		curr_node->getPreviousNode()->setNextNode(node_ptr);
		curr_node->setPreviousNode(node_ptr);

		number_of_nodes++;
	}
}

template<typename T>
int Doubly_Linked_List<T>::getNumberOfNodes()
{
	return number_of_nodes;
}

template<typename T>
void Doubly_Linked_List<T>::Print_List()
{
	if (isEmpty())
	{
		std::cout << "List is empty";
	}

	Double_Link_Node<T>* temp = head;

	while (temp != nullptr)
	{
		std::cout << temp->getData() << " -> ";
		temp = temp->getNextNode();
	}
}

template<typename T>
bool Doubly_Linked_List<T>::isEmpty()
{
	return (number_of_nodes == 0);
}

template<typename T>
Doubly_Linked_List<T>::Doubly_Linked_List()
{
	number_of_nodes = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
Doubly_Linked_List<T>::~Doubly_Linked_List()
{
	number_of_nodes = 0;
	head = nullptr;
	tail = nullptr;
}

#endif