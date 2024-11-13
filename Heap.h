#pragma once
#include <vector>
#include <iostream>

using std::cout;
using std::vector;

//ToDo:
//1. Complete Remove Operation ()
//2. Heapify function
//3. Add Array

class Heap
{
private:
	vector<int> heap;
	bool max;

public:
	Heap(bool max = true)
	{
		this->max = max;
	}
	
	void InsertItem(int item)
	{
		//Add item to end of array
		heap.push_back(item);

		//restore the heap property by swapping the item with its parent.
		int curr_index = heap.size() - 1;

		bool restored = false;

		
		while (!restored)
		{
			//if item becomes root, then stop.
			if (curr_index == 0)
				restored = true;

			else
			{
				//calculate parent index
				int parent_index = (curr_index - 1) / 2;

				//if item's parent has higher priority, then stop
				if (ChildHasPriority(curr_index, parent_index) == false)
					restored = true;
				else
				{
					swap(curr_index, parent_index);
					curr_index = parent_index;
				}
			}
		}


	}

	bool GetNext(int & ret_item)
	{
		//Move last item in heap to root
		//move the item down until the heap property is restored

		if (heap.size() == 0)
			return false;

		else
		{
			if (heap.size() == 1)
			{
				ret_item = heap[0];
				heap.erase(heap.begin());
				return true;
			}
			else
			{
				//return the item back to where the function is called.
				ret_item = heap[0];

				//move the last item in the heap to the front.
				heap[0] = heap[heap.size() - 1];

				//delete the former position of the last item
				heap.erase(heap.end() - 1);

				//Restore the heap poperty on the root.
				RestoreHeap(0);
			}
		}
	}

	vector<int> HeapSort()
	{
		vector<int> result;

		int ret_item;
		while(GetNext(ret_item))
			result.push_back(ret_item);

		return result;
	}

	void BuildHeap(vector<int> arr)
	{
		heap = arr;

		int median = heap.size();
		median = median / 2;

		for (int i = median; i >= 0; i--)
			RestoreHeap(i);
	}

	void PrintHeap()
	{
		for (int i = 0; i < heap.size(); i++)
		{
			cout << heap[i] << " - ";
		}
	}

private:
	bool ChildHasPriority(int child_index, int parent_index)
	{
		if (max == true && heap[child_index] > heap[parent_index])
			return true;
		else if (max == false && heap[child_index] < heap[parent_index])
			return true;
		else
			return false;
	}

	void swap(int a, int b)
	{
		int temp = heap[a];
		heap[a] = heap[b];
		heap[b] = temp;
	}

	void RestoreHeap(int start_index)
	{
		bool done = false;
		int curr_index = start_index;
		do
		{
			int left_child_index = 2 * curr_index + 1;
			int right_child_index = 2 * curr_index + 2;

			//check if the item has childern  if not, we do not need
			//to continue.
			if (left_child_index >= heap.size())
				done = true;

			else if (right_child_index >= heap.size())
			{
				//look at the left side only
				if (ChildHasPriority(left_child_index, curr_index))
				{
					swap(left_child_index, curr_index);
					curr_index = left_child_index;
				}
				else
					done = true;
			}


			else
			{
				//if left has priority, look at the left child
				if (ChildHasPriority(left_child_index, right_child_index))
				{
					if (ChildHasPriority(left_child_index, curr_index))
					{
						swap(left_child_index, curr_index);
						curr_index = left_child_index;
					}
					else
						done = true;
				}
				//otherwise, the right child has priority over the left.
				else
				{
					if (ChildHasPriority(right_child_index, curr_index))
					{
						swap(right_child_index, curr_index);
						curr_index = right_child_index;
					}
					else
						done = true;
				}
			}
		} while (!done);
	}
};