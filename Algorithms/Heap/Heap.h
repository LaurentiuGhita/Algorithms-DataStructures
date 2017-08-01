#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>

const int START_SIZE = 10;
const int INVALID_INDEX = -1;
const int START_INDEX = 0;

struct HeapElement
{
	HeapElement();
	HeapElement(int nVal, int nIndex) : m_nVal(nVal), m_nPriority(nVal), m_nIndex(nIndex) {}
	HeapElement(int nVal, int nPriority, int nIndex) : m_nVal(nVal), m_nPriority(nPriority), m_nIndex(nIndex) {}
	void SetIndex(int nIndex) { m_nIndex = nIndex; }
	int m_nVal;
	int m_nPriority;
	int m_nIndex;

	HeapElement& operator^=(HeapElement& rhs);
};

class Heap
{
public:
	Heap() : m_nSize(START_INDEX), m_nMemorySize(START_SIZE) { m_Elements = (HeapElement*)malloc(sizeof(HeapElement) * START_SIZE);}
	//~Heap();

	int GetFirstChildIndex(int nParentIndex) { return nParentIndex * 2 + 1;}
	int GetSecondChildIndex(int nParentIndex) { return nParentIndex * 2 + 2; }
	int GetParentIndex(int nChildIndex);
	int GetMinimum();
	void DeleteMinimum();

	void AddElement(int nVal) { AddElement(nVal, nVal); } 
	void AddElement(int nVal, int nPriority);
	void Heapify();
	void Print();
	bool CheckIfSmallerThanKthElement(int nVal, int nStartIndex, int nKThPos);

protected:
	void HeapifyHelper(HeapElement* pRoot);
	void BubbleUp(int nHeapIndex);
	void BubbleDown(int nIndex);

	int m_nSize;
	int m_nMemorySize;
	HeapElement* m_Elements;
};

class PriorityQueue : private Heap
{
public:
	bool IsEmpty() { return m_nSize == START_INDEX; }
	int  GetSize() { return m_nSize; }
	void Enqueue(int nVal, int nPriority) { AddElement(nVal, nPriority); }
	void Enqueue(int nVal) { AddElement(nVal, nVal); }
	int  GetMin() { return GetMinimum(); }
	void Dequeue() { Heap::DeleteMinimum(); };
	void Print() { Heap::Print(); }
};

#endif