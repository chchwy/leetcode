// 232. Implement Queue using Stacks
// Stack, Queue

#include <deque>
using std::deque;

class MyQueue {
public:
    deque<int> in;
    deque<int> out;

    MyQueue() {
    }

    void push(int x) {
        while (!out.empty()) {
            in.push_back(out.back());
            out.pop_back();
        }

        in.push_back(x);
    }

    int pop() {
        while (!in.empty()) {
            out.push_back(in.back());
            in.pop_back();
        }
        int top = out.back();
        out.pop_back();
        return top;
    }

    int peek() {
        while (!in.empty()) {
            out.push_back(in.back());
            in.pop_back();
        }
        return out.back();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};

int main() {
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.peek();  // return 1
    myQueue.pop();   // return 1, queue is [2]
    myQueue.empty(); // return false

    return 0;
}