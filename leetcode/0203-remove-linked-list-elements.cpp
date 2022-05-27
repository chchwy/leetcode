// 203. Remove Linked List Elements
// Linked List

#include<cstdio>

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {

		while (head && head->val == val) {
			ListNode* tmp = head;
			head = head->next;
			delete tmp;
		}

		ListNode* node = head;
		while (node && node->next) {
			if (node->next->val == val) {
				ListNode* tmp = node->next;
				node->next = node->next->next;
				delete tmp;
			} else {
				node = node->next;
			}
		}
		return head;
	}
};

int main()
{
	//[1, 2, 6, 3, 4, 5, 6]
	// val =6
	ListNode* n6 = new ListNode(6, nullptr);
	ListNode* n5 = new ListNode(5, n6);
	ListNode* n4 = new ListNode(4, n5);
	ListNode* n3 = new ListNode(3, n4);
	ListNode* n2 = new ListNode(6, n3);
	ListNode* n1 = new ListNode(2, n2);
	ListNode* n0 = new ListNode(1, n1);

	Solution s;
	ListNode* head = s.removeElements(n0, 6);

	int i = 0;
	while (head)
	{
		printf("Node[%d] = %d\n", i++, head->val);
		head = head->next;
	}
}
