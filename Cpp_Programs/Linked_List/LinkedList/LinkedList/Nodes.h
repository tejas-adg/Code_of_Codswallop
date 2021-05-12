#pragma once
#ifndef _NODES_H_
#define _NODES_H_

template<typename T>
class Single_Link_Node
{
private:
	 T obj;
	 Single_Link_Node<T>* nextNode;

public:
	Single_Link_Node();
	~Single_Link_Node();

	T getData(void);
	void setData(T);
	Single_Link_Node<T>* getNextNode(void);
	void setNextNode(Single_Link_Node<T>*);
};

template<typename T>
Single_Link_Node<T>::Single_Link_Node()
{
	obj = 0;
	nextNode = nullptr;
}

template<typename T>
Single_Link_Node<T>::~Single_Link_Node()
{
	obj = 0;
	nextNode = nullptr;
}

template<typename T>
T Single_Link_Node<T>::getData()
{
	return obj;
}

template<typename T>
void Single_Link_Node<T>::setData(T _obj)
{
	obj = _obj;
}

template<typename T>
Single_Link_Node<T>* Single_Link_Node<T>::getNextNode()
{
	return nextNode;
}

template<typename T>
void Single_Link_Node<T>::setNextNode(Single_Link_Node<T>* _next_Node)
{
	nextNode = _next_Node;
}

/*
template<typename T>
typename Double_Link_Node
{
private:
	T obj;
	Double_Link_Node<T>* nextNode;
	Double_Link_Node<T>* PreviousNode;

public:
	Double_Link_Node();
	~Double_Link_Node();

	T getData(void);
	void setData(T);
	Double_Link_Node<T>* getNextNode(void);
	void setNextNode(Double_Link_Node<T>*);
};*/

#endif