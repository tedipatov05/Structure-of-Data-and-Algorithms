// 03. Remove duplicates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* iter = head;

    while (iter && iter->next) {
        if (iter->val == iter->next->val) {
            ListNode* next = iter->next->next;
            delete iter->next;
            iter->next = next;
        }
        else {
            iter = iter->next;
        }
    }

    return head;

}

int main()
{
    
}

