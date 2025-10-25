/*
Merge Sort Algorithm

1. Time Complexity:
   - Best Case: O(NlogN)
   - Average Case: O(NlogN)
   - Worst Case: O(NlogN)

2. Space Complexity:
   - O(N) auxiliary space due to the extra arrays created during merging.

3. Is it Stable?
   - Yes, merge sort is stable if implemented carefully. It preserves the relative order of equal elements.

4. Divide and Conquer principle:
   - Merge sort works by splitting the array in halves recursively and merging them back together in sorted order.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> leftArr(n1), rightArr(n2);

  
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
	int mid = left + (right - left) / 2;
    if (left < right) {
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
	}
}

int main()
{
	vector<int> array = { 38, 27, 43, 3, 9, 82, 10 };
    mergeSort(array, 0, array.size()-1);

    for (int num : array)
    {
        cout << num << " ";
    }
}
