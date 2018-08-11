/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };

難度: Medium
給兩個反序的 Linked list 來代表數字的每個位數

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
    {
        ListNode* pRoot = nullptr;
        ListNode* pCurrentNode = nullptr;
        
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            if ( pRoot == nullptr )
            {
                pRoot = new ListNode(0);
                pCurrentNode = pRoot;
            }
            else
            {
                pCurrentNode->next = new ListNode(0);
                pCurrentNode = pCurrentNode->next;
            }
            
            int v1 = (l1) ? l1->val : 0;
            int v2 = (l2) ? l2->val : 0;
            
            pCurrentNode->val = v1 + v2 + carry;
            carry = 0;
            
            if (pCurrentNode->val >= 10)
            {
                carry = 1;
                pCurrentNode->val -= 10;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return pRoot;
    }
};