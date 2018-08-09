/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
    {
        ListNode* pRoot = NULL;
        ListNode* pCurrentNode = NULL;
        
        int carry = 0;
        while( l1 != NULL || l2 != NULL || carry != 0 )
        {
            if ( pRoot == NULL )
            {
                pRoot = new ListNode( 0 );
                pCurrentNode = pRoot;
            }
            else
            {
                pCurrentNode->next = new ListNode( 0 );
                pCurrentNode = pCurrentNode->next;
            }
            
            int v1 = ( l1 ) ? l1->val : 0;
            int v2 = ( l2 ) ? l2->val : 0;
            
            pCurrentNode->val = v1 + v2 + carry;
            carry = 0;
            
            if ( pCurrentNode->val >= 10 )
            {
                carry = 1;
                pCurrentNode->val -= 10;
            }
            if ( l1 ) l1 = l1->next;
            if ( l2 ) l2 = l2->next;
        }
        return pRoot;
    }
};