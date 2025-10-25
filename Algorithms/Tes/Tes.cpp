// Tes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int size = nums.size();

  
    for (int i = 0; i < size; i++) {
        if (nums[i] <= 0 || nums[i] > size) {
            nums[i] = size + 1;
        }
    }

    for (int i = 0; i < size; i++) {
        int val = abs(nums[i]);
        if (val <= size) {
            nums[val - 1] = -abs(nums[val - 1]);
        }
    }

    for (int i = 0; i < size; i++) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }

    return size + 1;
}

struct Section {
    int ticket;
    int result;
    int index;
};

bool operator<=(Section& s1, Section& s2) {
    if (s1.result == s2.result) {
        return s1.index < s2.index;
    }

    return s1.result < s2.result;
}

void merge(Section* arr1, size_t a1, Section* arr2, size_t a2)
{
    Section* result = new Section[a1 + a2];

    size_t a11 = 0, a22 = 0, r1 = 0;
    while (a11 < a1 && a22 < a2) {
        if (arr1[a11] <= arr2[a22]) {
            result[r1++] = arr1[a11++];
        }
        else {
            result[r1++] = arr2[a22++];
        }
    }

    while (a11 < a1)
        result[r1++] = arr1[a11++];

    while (a22 < a2)
        result[r1++] = arr2[a22++];

    for (size_t i = 0; i < r1; i++)
        arr1[i] = result[i];

    delete[] result;
}

void mergeSort(Section* arr, size_t length) {
    if (length <= 1)
        return;

    size_t mid = length / 2;
    mergeSort(arr, mid);
    mergeSort(arr + mid, length - mid);
    merge(arr, mid, arr + mid, length - mid);
}

int main() {
    size_t n;
    cin >> n;
    Section* sections = new Section[n];
    Section* copy = new Section[n];

    for (size_t i = 0; i < n; i++) {
        sections[i].index = i;
        cin >> sections[i].result;
        copy[i].index = i;
        copy[i].result = sections[i].result;
    }

    mergeSort(copy, n);

    for (size_t i = 0; i < n; i++) {
        size_t index = copy[i].index;
        sections[index].ticket = i;
    }

    for (size_t i = 0; i < n; i++) {
        std::cout << sections[i].ticket << " ";
    }
}
