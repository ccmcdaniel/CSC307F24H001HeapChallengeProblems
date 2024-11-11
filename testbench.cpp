#include <iostream>
#include "Heap.h"

using std::cout;

int main()
{
	Heap test_heap(false);

	test_heap.InsertItem(45);
	test_heap.InsertItem(78);
	test_heap.InsertItem(56);
	test_heap.InsertItem(22);
	test_heap.InsertItem(98);
	test_heap.InsertItem(61);
	test_heap.InsertItem(5);

	//98, 78, 61, 22, 45, 56, 5
}