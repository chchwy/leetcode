// 21. Merge Two Sorted Lists
// Linked List
#include <limits.h>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummyHead(INT_MIN);
        ListNode* mergedList = &dummyHead;

        while (list1 && list2)
        {
            if (list1->val < list2->val) {
                mergedList->next = list1;
                list1 = list1->next;
            }
            else {
                mergedList->next = list2;
                list2 = list2->next;
            }

            mergedList = mergedList->next;
        }

        if (list1) mergedList->next = list1;
        if (list2) mergedList->next = list2;

        return dummyHead.next;
    }
};

int main() {
    // list1 = [1, 2, 4]
    // list2 = [1, 3, 4]
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    Solution sln;
    ListNode* mergedList = sln.mergeTwoLists(list1, list2);

    while (mergedList) {
        std::cout << mergedList->val << ", ";
        mergedList = mergedList->next;
    }
    std::cout << std::endl;

    return 0;
}
