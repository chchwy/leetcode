// 206. Reverse Linked List
// Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
 
 // The simplest and easiest to understand method is using 3 pointers
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if (!head || !head->next)
            return head;
        
        ListNode* node1 = head;
        ListNode* node2 = head->next;
        
        head->next = nullptr;
        
        // N1 -> N2 -> N3
        // N1 <- N2 -> N3
        while(node2) {
            ListNode* node3 = node2->next;
            node2->next = node1;
            
            node1 = node2;
            node2 = node3;
        }
        
        head = node1;
        return head;
    }
};