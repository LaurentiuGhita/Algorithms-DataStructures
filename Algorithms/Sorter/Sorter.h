#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <fstream>
#include <vector>

class Sorter
{
public:
	Sorter(std::istream& stream);
	Sorter(std::vector<int> input);

	void Merge(std::vector<int>& elements, int nStart, int nMiddle, int nEnd);

	void MergeSort() { MergeSort(0, m_mergeSortedElements.size() - 1);}
	void MergeSort(int nStart, int nEnd);
	void SelectionSort();
	void InsertionSort();
	void QuickSort() { QuickSort(m_quickSortElements, 0, m_quickSortElements.size() -1);}
	void QuickSort(std::vector<int>& elements, int nStart, int nEnd);
	int  Partition(std::vector<int>& elements, int nStart, int nEnd);
	int  Partition2(std::vector<int>& elements, int nStart, int nEnd);


	void PrintMergeSorted();
	void PrintQuickSorted();
private:

	int m_nSize;
	std::vector<int> m_unsortedElements;
	std::vector<int> m_mergeSortedElements;
	std::vector<int> m_quickSortElements;
};

#endif