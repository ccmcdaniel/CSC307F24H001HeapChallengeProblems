#pragma once
#include <vector>
using std::vector;

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
};