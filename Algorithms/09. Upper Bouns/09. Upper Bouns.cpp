// 09. Upper Bouns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int upperBound(vector<int>& data, int target)
{
	int left = 0;
	int right = data.size();
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (data[mid] <= target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}

	return left;
}


int main()
{
	vector<int> data = { 1,2,4,4,5,6,8,9 };
	int target = 7;
	int index = upperBound(data, target);
	cout << "Upper bound index of " << target << " is: " << index << endl;
}
