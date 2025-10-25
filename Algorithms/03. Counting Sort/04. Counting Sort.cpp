

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Counting Sort Algorithm

1. Time Complexity:
   - Best Case: O(N + K)
   - Average Case: O(N + K)
   - Worst Case: O(N + K)
   - N = number of elements in the input array
   - K = range of input values (difference between maximum and minimum values)

2. Space Complexity:
   - O(N + K) auxiliary space, where we use additional space for the count and output arrays.

3. Is it Stable?
   - Yes, counting sort is stable. Elements with the same value retain their relative order after sorting.

4. When to Use:
   - Counting sort is useful when the range of input values is not significantly larger than the number of elements (K is close to N).
   - Not suitable for data with a very large range of values (K is much larger than N).
*/


void counting_sort(vector<int>& arr)
{
	int size = arr.size();
	if (size == 0)
	{
		return;
	}

	int maxElem = *max_element(arr.begin(), arr.end()) + 1;
	vector<int> count(maxElem, 0);
	vector<int> output(size);

	// count occurrences
	for (int i = 0; i < size; i++)
	{
		count[arr[i]]++;
	}

	// accumulate the counts
	for (int i = 1; i < maxElem; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = output[i];
	}
}

void counting_sort_with_negatives(vector<int>& array)
{
	int size = array.size();
	int minElement = *min_element(array.begin(), array.end());
	int maxElement = *max_element(array.begin(), array.end());
	int range = (maxElement - minElement) + 1;

	vector<int> count(range, 0);
	vector<int> output(size);

	for (int i = 0; i < size; i++)
	{
		count[array[i] - minElement]++;
	}

	for (int i = 1; i < range; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[array[i] - minElement] - 1] = array[i];
		count[array[i] - minElement]--;
	}

	for (size_t i = 0; i < size; i++)
	{
		array[i] = output[i];
	}
}


int main()
{
	vector<int> arr = { 4, 2, 2, 8, 3, 3, 1, -3, -3, -3 };
	counting_sort_with_negatives(arr);
	for (int num : arr)
	{
		cout << num << " ";
	}
}

