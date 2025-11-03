// 01. IsPalindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <functional>
#include <iostream>

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

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    head->next = second;
    ListNode* third = new ListNode(2);
    second->next = third;
    ListNode* forth = new ListNode(1);
    third->next = forth;

    std::cout << std::boolalpha << isPalindrome(head) << std::endl;

}

