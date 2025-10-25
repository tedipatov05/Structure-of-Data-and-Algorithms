// 08. Binary Search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& data, int target)
{
	int left = 0;
	int right = data.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (data[mid] == target)
			return mid;
		else if (data[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;
}

int binarySearchRecursive(vector<int>& data,int left, int right, int target)
{
	if (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (data[mid] == target)
			return mid;
		else if (data[mid] < target)
			return binarySearchRecursive(data, mid + 1, right, target);
		else
			return binarySearchRecursive(data, left, mid - 1, target);
	}

	return -1;
}

int main()
{
	vector<int> data = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
	int target = 7;
	int result = binarySearchRecursive(data, 0, data.size()-1, target);
	cout << result;
}

