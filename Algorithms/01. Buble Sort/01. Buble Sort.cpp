
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Bubble Sort Algorithms

1. Time Complexity:
   - Best Case: O(N) when the array is already sorted (for optimized bubble sort with early exit).
   - Average Case: O(N^2) for a random unsorted array.
   - Worst Case: O(N^2) when the array is sorted in reverse order.

2. Space Complexity:
   - O(1) auxiliary space, as bubble sort is an in-place sorting algorithm.

3. Is it Stable?
   - Yes, bubble sort is a stable sorting algorithm. Equal elements maintain their relative positions after sorting.

4. Theoretical Worst-Case Swaps:
   - In the worst case, the number of swaps is N * (N - 1) / 2, where N is the size of the array.
*/

void bubble_sort(vector<int>& array)
{
	int size = array.size();

	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1-i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
			}
		}
	}
}

void optimized_bubble_sort(vector<int>& array)
{
	int size = array.size();
	for (int i = 0; i < size-1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
				swapped = true;	
			}
		}

		if (!swapped)
		{
			break; // Array is already sorted
		}
	}
}



int main()
{
	vector<int> array = { 64, 34, 25, 12, 22, 11, 90 };
	optimized_bubble_sort(array);
	cout << "Sorted array using Bubble Sort: ";
	for (int num : array)
	{
		cout << num << " ";
	}

}

