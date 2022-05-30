// 160. Intersection of Two Linked Lists
// Linked List, Two Pointers
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lengthA = 0;
        int lengthB = 0;
        
        ListNode* nodeA = headA;
        while (nodeA)
        {
            lengthA++;
            nodeA = nodeA->next;
        }
        
        ListNode* nodeB = headB;
        while (nodeB)
        {
            lengthB++;
            nodeB = nodeB->next;
        }
        
        ListNode* fastNode;
        ListNode* slowNode;
        if (lengthA > lengthB)
        {
            fastNode = headA;
            slowNode = headB;
        }
        else
        {
            fastNode = headB;
            slowNode = headA;
        }
        
        int diff = std::abs(lengthA - lengthB);
        
        for (int i = 0; i < diff; ++i)
            fastNode = fastNode->next;
        
        while(fastNode)
        {
            if (slowNode == fastNode)
            {
                return slowNode;
            }
            
            slowNode = slowNode->next;
            fastNode = fastNode->next;
        }
        
        return nullptr;
    }
};
