
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Insertion Sort Algorithm

1. Time Complexity:
   - Best Case: O(N) when the array is already sorted.
   - Average Case: O(N^2)
   - Worst Case: O(N^2)

2. Space Complexity:
   - O(1) auxiliary space since insertion sort is an in-place sorting algorithm.

3. Is it Stable?
   - Yes, insertion sort is stable. Equal elements maintain their relative order.

4. Number of Swaps:
   - In the worst case (reverse sorted array), insertion sort performs approximately N * (N - 1) / 2 comparisons and shifts.

*/

void insertion_sort(vector<int>& arr)
{
	size_t size = arr.size();
	for (size_t i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}

void stable_insertion_sort(vector<int>& arr)
{
	size_t size = arr.size();
	for (size_t i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] >= key)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}



int main()
{
	vector<int> arr = { 12, 11, 13, 5, 6 };
	insertion_sort(arr);
	for (int num : arr)
	{
		cout << num << " ";
	}
}
