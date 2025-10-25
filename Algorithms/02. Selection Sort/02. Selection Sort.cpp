// 02. Selection Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Selection Sort Algorithms

1. Time Complexity:
   - Best Case: O(N^2)
   - Average Case: O(N^2)
   - Worst Case: O(N^2)

2. Space Complexity:
   - O(1) auxiliary space, as selection sort is an in-place sorting algorithm.

3. Is it Stable?
   - No, selection sort is not stable. It swaps non-adjacent elements, which can change the relative order of equal elements.

4. Number of Swaps:
   - Always performs N - 1 swaps, unless we avoid unnecessary swaps when the minimum element is already in the correct position.
*/

void selection_sort(vector<int>& array)
{
	int size = array.size();
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			swap(array[i], array[minIndex]);
		}
	}
}

void selection_sort_pair(vector<pair<int, string>>& pairs)
{
	int size = pairs.size();
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (pairs[j].first < pairs[minIndex].first)
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			swap( pairs[minIndex], pairs[i]);
		}
	}
}


int main()
{
	vector<int> data = { 64, 25, 12, 22, 11 };
	selection_sort(data);
	cout << "Sorted array: \n";
	for (int num : data)
	{
		cout << num << " ";
	}

	vector<pair<int, string>> dataPairs = { {64, "sixty-four"}, {25, "twenty-five"}, {12, "twelve"}, {22, "twenty-two"}, {11, "eleven"} };
	selection_sort_pair(dataPairs);
	cout << "\nSorted pairs: \n";
	for (const auto& p : dataPairs)
	{
		cout << p.first << ": " << p.second << "\n";
	}
}

