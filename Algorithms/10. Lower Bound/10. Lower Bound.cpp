// 10. Lower Bound.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lowerBound(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

	return left == nums.size() ? -1 : left;
}

int main()
{
	vector<int> data = { 1,2,4,4,5,6,8,9 };
	int target = 3;
	int index = lowerBound(data, target);
	cout << "The lower bound index of " << target << " is: " << index << endl;
}

