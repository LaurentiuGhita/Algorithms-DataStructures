#include "Heap.h"
#include <iostream>

int main()
{
#if 0
	PriorityQueue pq;
	pq.Enqueue(10);
	pq.Enqueue(11);
	pq.Enqueue(5);
	pq.Enqueue(3);
	pq.Enqueue(20);
	pq.Enqueue(2);
	pq.Enqueue(1);
	
	pq.Print();
#endif

	Heap myHeap;

	myHeap.AddElement(5);
	myHeap.AddElement(3);
	myHeap.AddElement(2);
	myHeap.AddElement(7);
	myHeap.AddElement(1);
	myHeap.AddElement(5);

	myHeap.Print();
	int nr, k;
	std::cin >> nr;
	std::cin >> k;

	std::cout << myHeap.CheckIfSmallerThanKthElement(nr, 0, k) << "\n";

}
