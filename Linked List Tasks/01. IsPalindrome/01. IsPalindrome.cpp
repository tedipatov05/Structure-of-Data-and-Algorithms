// 01. IsPalindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <functional>
#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* rev = reverse(slow);
    while (rev != nullptr) {
        if (head->val != rev->val) {
            return false;
        }
        head = head->next;
        rev = rev->next;
    }
    return true;
}

int peakIndexInMountainArray(std::vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    int solution = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1]) {
            solution = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }


    return solution;
}

int main()
{
    std::vector<int> data = { 0, 2, 1, 0 };
    int peakIndex = peakIndexInMountainArray(data);

}

