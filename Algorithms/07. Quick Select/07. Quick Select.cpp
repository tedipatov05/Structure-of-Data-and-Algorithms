// 07. Quick Select.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& data, int low, int high)
{
	int pivot = high;
	int i = low;

	for (int j = low; j < high; j++)
	{
		if (data[j] < pivot)
		{
			swap(data[j], data[i]);
			i++;
		}
	}

	swap(data[i], data[high]);

	return i;
}

int quickSelect(vector<int>& data, int low, int high, int k)
{
	if (low < high)
	{
		int pivotIndex = partition(data, low, high);
		if (pivotIndex == k)
			return data[k];
		else if (pivotIndex < k)
			quickSelect(data, pivotIndex + 1, high, k);
		else
			quickSelect(data, low, pivotIndex - 1, k);
	}
}

vector<int> mergeArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merged;

    int left = 0;
    int right = 0;

    while (left < nums1.size() && right < nums2.size()) {
        if (nums1[left] > nums2[right]) {
            merged.push_back(nums2[right]);
            right++;
        }
        else {
            merged.push_back(nums1[left]);
            left++;
        }
    }

    for (int i = left; i < nums1.size(); i++) {
        merged.push_back(nums1[left]);
    }

    for (int i = right; i < nums2.size(); i++) {
        merged.push_back(nums2[right]);
    }

    return merged;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merged = mergeArrays(nums1, nums2);
    int size = merged.size();
    double median;
    if (merged.size() % 2 == 1) {
        median = merged[size / 2];
    }
    else {
        median = merged[size / 2] + merged[size / 2 - 1];
    }

    return median;

}

int main()
{
    vector<int> num1 = { 1,3 };
	vector<int> num2 = { 2 };
	cout << findMedianSortedArrays(num1, num2);
}

