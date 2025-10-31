// 11. Jump Search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int jumpSearch(vector<int>& data, int target)
{
	int len = data.size();
	int step = sqrt(len);
	int start = 0;
	int end = start + step;

	while (end < len && data[end] <= target)
	{
		start = end;
		end += step;
		if (end > len - 1)
		{
			end = len;
		}
	}

	for (int i = start; i < end; i++)
	{
		if (data[i] == target)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	vector<int> data = { 1,2,3,4,5,6,7,8,9,10 };
	int target = 7;
	int result = jumpSearch(data, target);
	if (result != -1)
	{
		cout << "Element found at index: " << result << endl;
	}
	else
	{
		cout << "Element not found in the array." << endl;
	}

	int a;
	switch (a)
	{
		case 3:
			cout << "error" << endl;
			break;
		case 1:
			cout << "one" << endl;

		default:
			cout << "13" << endl;
			break;

	}
}
