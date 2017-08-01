#ifndef LIST_H
#define LIST_H

#include <iostream>

struct Node
{
	Node(int m_nVal);

	int m_nVal;
	Node* pNext;
};

class List
{
public:
	List() : headNode(NULL) {}
	~List();

	void Add(int nval);
	void Print();
	bool Search(int nVal);
	bool Delete(int nVal);
private:
	
	Node* headNode;

};

#endif