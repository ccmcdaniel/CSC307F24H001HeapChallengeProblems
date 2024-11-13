#include <iostream>
#include "Heap.h"

using std::cout;

int main()
{
	Heap test_heap;

	test_heap.InsertItem(45);
	test_heap.PrintHeap();
	cout << "\n";
	test_heap.InsertItem(78);
	test_heap.PrintHeap();
	cout << "\n";
	test_heap.InsertItem(56);
	test_heap.PrintHeap();
	cout << "\n";
	test_heap.InsertItem(22);
	test_heap.PrintHeap();
	cout << "\n";
	test_heap.InsertItem(98);
	test_heap.PrintHeap();
	cout << "\n";
	test_heap.InsertItem(61);
	test_heap.PrintHeap();
	cout << "\n";
	test_heap.InsertItem(5);
	test_heap.PrintHeap();
	cout << "\n";

	vector<int> sorted_items = test_heap.HeapSort();

	for (int i = 0; i < sorted_items.size(); i++)
		cout << sorted_items[i] << ", ";

	cout << "\n";

	test_heap.BuildHeap({ 3, 89, 1, 12, 15, 17, 19, 88, 72, 100, 1, 2, 4 });
	test_heap.PrintHeap();

	//98, 78, 61, 22, 45, 56, 5
}