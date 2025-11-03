// 02. Get Intersection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* currA = headA;
    ListNode* currB = headB;

    while (currA != currB) {
        currA = (currA != nullptr) ? currA->next : headB;
        currB = (currB != nullptr) ? currB->next : headA;
    }

    return currA;
}

int main()
{
    
}
