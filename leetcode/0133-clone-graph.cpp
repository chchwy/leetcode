// 133. Clone Graph
// Graph
#include <iostream>
#include <deque>
#include <vector>
using std::vector;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if (!node) return nullptr;

        Node* clonedNodes[100 + 1]; // index 0 is not used
        for (int i = 0; i < 100 + 1; ++i)
            clonedNodes[i] = nullptr;

        bool visited[100 + 1];
        for (int i = 0; i < 100 + 1; ++i)
            visited[i] = false;

        std::deque<Node*> nodeQueue;
        nodeQueue.push_back(node);

        while (!nodeQueue.empty()) {

            Node* n1 = nodeQueue.front();
            nodeQueue.pop_front();

            if (visited[n1->val]) continue;

            visited[n1->val] = true;

            if (clonedNodes[n1->val] == nullptr) {
                clonedNodes[n1->val] = new Node(n1->val);
            }
            Node* n2 = clonedNodes[n1->val];

            for (int i = 0; i < n1->neighbors.size(); ++i) {

                Node* neighbor = n1->neighbors[i];
                if (!visited[neighbor->val])
                    nodeQueue.push_back(neighbor);

                if (clonedNodes[neighbor->val] == nullptr) {
                    clonedNodes[neighbor->val] = new Node(neighbor->val);
                }
                n2->neighbors.push_back(clonedNodes[neighbor->val]);
            }
        }
        return clonedNodes[node->val];
    }
};

int main() {
    Node nodes[4 + 1];
    for (int i = 0; i < 4 + 1; ++i)
        nodes[i].val = i;
    
    nodes[1].neighbors = vector<Node*>{ &nodes[2], &nodes[4] };
    nodes[2].neighbors = vector<Node*>{ &nodes[1], &nodes[3] };
    nodes[3].neighbors = vector<Node*>{ &nodes[2], &nodes[4] };
    nodes[4].neighbors = vector<Node*>{ &nodes[1], &nodes[3] };

    Solution sln;
    Node* cloned = sln.cloneGraph(&nodes[1]);

    std::cout << cloned->val << std::endl;
    return 0;
}
