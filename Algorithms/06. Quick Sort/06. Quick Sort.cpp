
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high]; 
    int i = low;          

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]); 
            i++;                  
        }
    }
    swap(arr[i], arr[high]);

    return i;
}

void quickSort(vector<int>& arr, int left,int right)
{
	if (left < right)
	{
		int pi = partition(arr, left, right);

		quickSort(arr, left, pi - 1);
		quickSort(arr, pi + 1, right);
	}
}

int main()
{
	vector<int> arr = { 10, 7, 8, 9, 1, 5 };
	int n = arr.size();
	quickSort(arr, 0, n - 1);
	for (int num : arr)
	{
		cout << num << " ";
	}
}
