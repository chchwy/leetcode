// 225. Implement Stack using Queues
// Stack, Queue

#include <deque>
using std::deque;

class MyStack {
public:
    deque<int> queue1;
    deque<int> queue2;

    MyStack() {

    }

    void push(int x) {

        deque<int>& filledQueue = (!queue1.empty()) ? queue1 : queue2;
        filledQueue.push_back(x);
    }

    int pop() {
        deque<int>& filledQueue = (!queue1.empty()) ? queue1 : queue2;
        deque<int>& emptyQueue = (queue1.empty()) ? queue1 : queue2;

        while (filledQueue.size() > 1) {
            emptyQueue.push_back(filledQueue.front());
            filledQueue.pop_front();
        }

        int topValue = filledQueue.front();
        filledQueue.pop_front();
        return topValue;
    }

    int top() {
        deque<int>& filledQueue = (!queue1.empty()) ? queue1 : queue2;
        deque<int>& emptyQueue = (queue1.empty()) ? queue1 : queue2;

        while (filledQueue.size() > 1) {
            emptyQueue.push_back(filledQueue.front());
            filledQueue.pop_front();
        }

        int topValue = filledQueue.front();
        emptyQueue.push_back(topValue);
        filledQueue.pop_front();
        return topValue;
    }

    bool empty() {
        return (queue1.empty() && queue2.empty());
    }
};

int main() {
    deque<int> d;
    d.pop_back();

    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.top(); // return 2
    myStack.pop(); // return 2
    myStack.empty(); // return False

    return 0;
}