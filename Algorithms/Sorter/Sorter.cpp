#include "Sorter.h"
#include "../Utils/utils.h"
#include <queue>
#include <stdlib.h>
#include <time.h>  

Sorter::Sorter(std::istream& in)
{
	std::cout << "Enter size of vector\n";
	in >> m_nSize;

	for(int i = 0; i < m_nSize; i++)
	{
		int aux;
		in >> aux;
		m_unsortedElements.push_back(aux);
		m_mergeSortedElements.push_back(aux);
		m_quickSortElements.push_back(aux);
	}
}

Sorter::Sorter(std::vector<int> input)
{
	m_unsortedElements = input;
	m_mergeSortedElements = input;
	m_quickSortElements = input;
}

void Sorter::SelectionSort()
{
	std::vector<int> sortedVector;
	sortedVector = m_unsortedElements;

	// at step i we have the first i elements sorted 
	for(int i = 0; i < sortedVector.size() - 1; i++)
	{
		int minIndex = i;
		for(int j = i + 1; j < sortedVector.size(); j++)
		{
			if(sortedVector[j] < sortedVector[minIndex])
				minIndex = j;
		}
		if(minIndex != i)
			mySwap(sortedVector[i], sortedVector[minIndex]);
	}

	printVector(sortedVector);
}

void Sorter::InsertionSort()
{
	std::cout << "InsertionSort ";
	std::vector<int> sortedVector;
	sortedVector = m_unsortedElements;

	for(int i = 1; i < sortedVector.size(); ++i)
	{
		// what is to the left is sorted --> find where new element must be in the sorted part from left 
		for(int j = i; j > 0 ; --j)
		{
			if(sortedVector[j] > sortedVector[j - 1])
				break;


			mySwap(sortedVector[j], sortedVector[j - 1]);
		}
	}

	printVector(sortedVector);
}

void Sorter::Merge(std::vector<int>& elements, int nStart, int nMiddle, int nEnd)
{
	std::queue<int> leftSide;
	std::queue<int> rightSide;
	for(int i = nStart; i <= nEnd; i++)
	{
		if(i <= nMiddle)
		{

			leftSide.push(elements[i]);
		}
		else
		{
			rightSide.push(elements[i]);
		}
	}

	int index = nStart;
	while(!leftSide.empty() && !rightSide.empty())
	{
		if(leftSide.front() < rightSide.front())
		{
			elements[index] = leftSide.front();
			leftSide.pop();
		}
		else
		{
			elements[index] = rightSide.front();
			rightSide.pop();
		}

		index++;
	}

	/*copy rest of elements*/
	if(!leftSide.empty())
	{
		while(!leftSide.empty())
		{
			elements[index] = leftSide.front();
			leftSide.pop();
			++index;
		}
	}

	if(!rightSide.empty())
	{
		while(!rightSide.empty())
		{
			elements[index] = rightSide.front();
			rightSide.pop();
			++index;
		}
	}
}

void Sorter::MergeSort(int nStart, int nEnd)
{
	if(nStart < nEnd)
	{
		int nMiddle = (nStart + nEnd) / 2;
		MergeSort(nStart, nMiddle);
		MergeSort(nMiddle + 1, nEnd);
		Merge(m_mergeSortedElements, nStart, nMiddle, nEnd);
	}
}

void Sorter::PrintMergeSorted()
{
	std::cout << "Merge sorted: ";
	for(int i = 0; i < m_mergeSortedElements.size(); i++)
		std::cout << m_mergeSortedElements[i] << " ";

	std::cout << "\n";
}

void Sorter::QuickSort(std::vector<int>& elements, int nStart, int nEnd)
{
 	
	int nPivotIndex;

	if(nStart < nEnd)
	{
		nPivotIndex = Partition2(elements, nStart, nEnd);
		QuickSort(elements, nStart, nPivotIndex-1);
		QuickSort(elements, nPivotIndex + 1, nEnd);
	}
}

int Sorter::Partition(std::vector<int>& elements, int nStart, int nEnd)
{
	int nPivotIndex;
	srand (time(NULL));
	if(nStart < nEnd)
	{
		nPivotIndex = nEnd;//nStart + rand() % (nEnd - nStart + 1);
		int nLower = nStart;
		int nUpper = nEnd;

		bool bGoToLeft = false;
		bool bGoToRight = true;
		while(nLower != nUpper)
		{
			if(bGoToRight)
			{
				if(elements[nLower] < elements[nPivotIndex])
				{
					nLower++;
				}
				else
				{
					mySwap(elements[nLower], elements[nPivotIndex]);
					nPivotIndex = nLower;
					bGoToRight = false;
					bGoToLeft = true;
					//nUpper--;
				}
			}
			if(bGoToLeft)
			{
				if(elements[nUpper] > elements[nPivotIndex])
				{
					nUpper--;
				}
				else
				{
					mySwap(elements[nUpper], elements[nPivotIndex]);
					nPivotIndex = nUpper;
					bGoToLeft = false;
					bGoToRight = true;
					//nLower++;
				}
			}
		}
	}

	std::cout << "pivot = " <<nPivotIndex << " vector: ";
	for(int i = nStart; i<= nEnd; i++)
		std::cout << elements[i] << " ";

	std::cout << "\n";

	return nPivotIndex;
}

int Sorter::Partition2(std::vector<int>& elements, int nStart, int nEnd)
{
	int nPivotIndex = nEnd;
	int lowerIndex = nStart;

	for(int i = nStart; i < nEnd; i++)
	{
		if(elements[i] <elements[nPivotIndex])
		{
			if(i != lowerIndex)
				mySwap(elements[i], elements[lowerIndex]);
			lowerIndex++;
		}
	}

	if(nPivotIndex != lowerIndex)
		mySwap(elements[nPivotIndex], elements[lowerIndex]);

	return lowerIndex;

}


void Sorter::PrintQuickSorted()
{
	std::cout << "Quick sorted: ";
	for(int i = 0; i < m_quickSortElements.size(); i++)
		std::cout << m_quickSortElements[i] << " ";

	std::cout << "\n";
}





