// 2095. Delete the Middle Node of a Linked List
// Linked List, Two Pointers

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

// Simple solution by counting
class Solution1 {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }

        int len = 0;
        ListNode* node = head;
        while(node) {
            len++;
            node = node->next;
        }

        int mid = (len / 2);
        node = head;
        for (int i = 0; i < mid - 1; ++i) {
            node = node->next;
        }
        
        ListNode* nodeToDelete = node->next;
        node->next = node->next->next;
        delete nodeToDelete;
        
        return head;
    }
};

// Two pointers trick
// however, the trick doesn't really help in this problem
class Solution2 {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        
        while(fast && fast->next) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* midNode = prev->next;
        prev->next = prev->next->next;
        delete midNode;
        
        return head;
    }
};
