// 707. Design Linked List


#include <iostream>

class MyLinkedList {
public:
    MyLinkedList() {
        dummyHead = new Node(0);
        tail = dummyHead;
    }
    ~MyLinkedList() {
        delete dummyHead;
    }
    int get(int index) {
        if (index >= len)
            return -1;

        Node* node = dummyHead->next;
        for (int i = 0; i < index; ++i) {
            node = node->next;
        }
        return node->val;
    }

    void addAtHead(int val) {
        Node* oldHead = dummyHead->next;
        dummyHead->next = new Node(val);
        dummyHead->next->next = oldHead;

        if (tail == dummyHead) tail = dummyHead->next;

        len++;
    }

    void addAtTail(int val) {
        if (tail == dummyHead) {
            dummyHead->next = new Node(val);
            tail = dummyHead->next;
        }
        else {
            tail->next = new Node(val);
            tail = tail->next;
        }
        len++;
    }

    void addAtIndex(int index, int val) {
        if (index > len)
            return;

        Node* node = dummyHead;
        for (int i = 0; i < index; ++i)
            node = node->next;

        Node* tmp = node->next;
        node->next = new Node(val);
        node->next->next = tmp;

        if (index == len)
            tail = node->next;

        len++;
    }

    void deleteAtIndex(int index) {

        if (index >= len) return;

        Node* node = dummyHead;
        for (int i = 0; i < index; ++i)
            node = node->next;

        Node* tmp = node->next->next;

        if (node->next == tail)
            tail = node;
        delete node->next;
        node->next = tmp;

        len--;
    }

    int length() { return len; }

    struct Node
    {
        int val = 0;
        Node* next = nullptr;
        Node() = default;
        Node(int v) : val(v) {}
    };

    Node* dummyHead = nullptr;
    Node* tail = nullptr;
    int len = 0;
};

void printLinkedList(MyLinkedList* list)
{
    std::cout << "Len=" << list->length() << " ";

    for (int i = 0; i < list->length(); ++i)
    {
        std::cout << "[" << list->get(i) << "] ";
    }
    std::cout << std::endl;
}


int main()
{
    MyLinkedList* obj = new MyLinkedList();

    obj->addAtHead(7); printLinkedList(obj);
    obj->addAtHead(2); printLinkedList(obj);
    obj->addAtHead(1); printLinkedList(obj);
    obj->addAtIndex(3, 0); printLinkedList(obj);
    obj->deleteAtIndex(2); printLinkedList(obj);
    obj->addAtHead(6); printLinkedList(obj);
    obj->addAtTail(4); printLinkedList(obj);
    std::cout << obj->get(4) << std::endl; printLinkedList(obj);
    obj->addAtHead(4); printLinkedList(obj);
    obj->addAtIndex(5, 0); printLinkedList(obj);
    obj->addAtHead(6); printLinkedList(obj);
}