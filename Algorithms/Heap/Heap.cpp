#include "Heap.h"

#include <iostream>
#include <stdlib.h>


HeapElement& HeapElement::operator^=(HeapElement& rhs)
{
	this->m_nVal ^= rhs.m_nVal;
	this->m_nPriority ^= rhs.m_nPriority;
	this->m_nIndex ^= rhs.m_nIndex;
}

void swapElements(HeapElement& a, HeapElement& b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}

int Heap::GetParentIndex(int nChildIndex)
{
	if(nChildIndex <= START_INDEX)
		return INVALID_INDEX;

	if(nChildIndex % 2 == 0)
		return (nChildIndex - 2) / 2;
	else
		return (nChildIndex - 1) / 2; 
}

int Heap::GetMinimum()
{
	if(m_nSize == START_INDEX)
	{
		std::cout << "No elements \n";
		return 0;
	}
	else
		return m_Elements[START_INDEX].m_nVal;
}

void Heap::DeleteMinimum()
{
	if(m_nSize == START_INDEX)
	{
		std::cout << "No elements \n";
	}
	HeapElement& newRoot = m_Elements[m_nSize-1];

	/* swap last element with root */
	--m_nSize;
	swapElements(newRoot, m_Elements[START_INDEX]);
	BubbleDown(START_INDEX);
}

void Heap::BubbleDown(int nIndex)
{
	int nFirstChildIndex = GetFirstChildIndex(nIndex);
	int nSecondChildIndex = GetSecondChildIndex(nIndex);

	HeapElement* pFirstChild = NULL;
	HeapElement* pSecondChild = NULL;
	HeapElement* pSmallestNode = NULL;

	if(nFirstChildIndex < m_nSize)
		pFirstChild = &m_Elements[nFirstChildIndex];

	if(nSecondChildIndex < m_nSize)
		pSecondChild = &m_Elements[nSecondChildIndex];

	/* no need to do sth */
	if(pSecondChild == NULL && pFirstChild == NULL)
		return;

	if(pSecondChild == NULL && pFirstChild != NULL)
		pSmallestNode = pFirstChild;

	if(pSecondChild != NULL && pFirstChild != NULL)
	{
		if(pFirstChild->m_nPriority < pSecondChild->m_nPriority)
		{
			pSmallestNode = pFirstChild;
		}
		else
		{
			pSmallestNode = pSecondChild;
		}
	}

	if(pSmallestNode->m_nPriority < m_Elements[nIndex].m_nPriority)
	{
		int indexToBubbleDown = pSmallestNode->m_nIndex;
		swapElements(*pSmallestNode, m_Elements[nIndex]);
		BubbleDown(indexToBubbleDown);
	}
	else
	{
		/* no need to do anything */
		return;
	}
}

void Heap::BubbleUp(int nIndex)
{
	if(nIndex == 0)
		return;

	int nParentIndex = GetParentIndex(nIndex);

	/*no parent*/
	if(nParentIndex == INVALID_INDEX)
		return;

	if(m_Elements[nIndex].m_nPriority < m_Elements[nParentIndex].m_nPriority)
	{
		swapElements(m_Elements[nIndex],m_Elements[nParentIndex]);
		BubbleUp(nParentIndex);
	}

}

void Heap::AddElement(int nVal, int nPriority)
{
	int nIndexToInsert = m_nSize;

	/*double size of heap*/
	if(m_nSize >= m_nMemorySize)
	{
		m_nMemorySize *= 2;
		m_Elements = (HeapElement*)realloc(m_Elements, m_nMemorySize);
	}

	if(m_nSize == INVALID_INDEX)
		m_nSize = START_INDEX;

	HeapElement newElement(nVal, nPriority, m_nSize);
	m_Elements[m_nSize] = newElement;
	BubbleUp(m_nSize);
	++m_nSize;
	
}

void Heap::Heapify()
{

}

void Heap::HeapifyHelper(HeapElement* pRoot)
{
	int nFirstChildIndex = GetFirstChildIndex(pRoot->m_nIndex);
	int nSecondChildIndex = GetSecondChildIndex(pRoot->m_nIndex);

	HeapElement* pFirstChild = NULL;
	HeapElement* pSecondChild = NULL;

	if(nFirstChildIndex < m_nSize)
		pFirstChild = &m_Elements[nFirstChildIndex];

	if(nSecondChildIndex < m_nSize)
		pSecondChild = &m_Elements[nFirstChildIndex];
}

/* true if element nVal smaller than nKthPos */
bool Heap::CheckIfSmallerThanKthElement(int nVal, int nStartIndex, int nKThPos)
{
	static int searchedElements = 0;
	static bool bElementFound = false;
	bool bRet = false;

	if(bElementFound == true)
	{
		return true;
	}
	else
	{
		
		if(searchedElements >= nKThPos)
			return false;
		
		searchedElements++;

		if(m_Elements[nStartIndex].m_nVal >= nVal)
		{
			bElementFound = true;
			return true;
		}
		else
		{
				int nFirstChildIndex = GetFirstChildIndex(nStartIndex);

				if(m_Elements[nStartIndex].m_nVal < nVal)
				{
					if(nFirstChildIndex < m_nSize)
					{
						if(m_Elements[nFirstChildIndex].m_nVal <= nVal)
							bRet = CheckIfSmallerThanKthElement(nVal, nFirstChildIndex, nKThPos);
					}

					if(bRet == false && searchedElements < nKThPos)
					{
						int nSecondChildIndex = GetSecondChildIndex(nStartIndex);
						if(nSecondChildIndex < m_nSize)
						{
							if(m_Elements[nSecondChildIndex].m_nVal <= nVal)
								bRet = CheckIfSmallerThanKthElement(nVal, nSecondChildIndex, nKThPos);
						}
					}
				}
				return bRet;
		}
	}
}


void Heap::Print()
{
	if(m_nSize == START_INDEX)
		std::cout << "Empty heap\n";
	else
		for(int i = 0; i < m_nSize; ++i)
		{
			std::cout << m_Elements[i].m_nVal << " priority " << m_Elements[i].m_nPriority << "\n";
		}
	std::cout << "------------------------------------\n";
}
