#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int value;
    Node* left{nullptr};
    Node* right{nullptr};
    Node* parent{nullptr};
    Node(int x) : value(x) {}
};

struct CompareNode {
    bool operator()(Node* const& n1, Node* const& n2) {
        return n1->value > n2->value;
    }
};

Node* build(priority_queue<Node*, vector<Node*>, CompareNode>& allNode) {
    if (allNode.empty()) return nullptr;
    while (!allNode.empty()) {
        if (allNode.size() == 1) return allNode.top();
        Node* tmp1 = allNode.top();
        allNode.pop();
        Node* tmp2 = allNode.top();
        allNode.pop();
        Node* tmp = new Node(tmp1->value + tmp2->value);
        tmp1->parent = tmp;
        tmp2->parent = tmp;
        tmp->left = tmp1;
        tmp->right = tmp2;
        allNode.push(tmp);
    }
}

long calculateLen(Node* node, const Node* root) {
    int depth{0};
    int freq{node->value};
    Node* tmp = node;
    while (tmp != root) {
        depth++;
        tmp = tmp->parent;
    }
    return depth * freq;
}

// void deleteTreeFromLeaf(Node* leaf) {
//     if (!leaf) return;
//     deleteTreeFromLeaf(leaf->parent);
//     delete leaf;
// }

void deleteTree(Node* root) {
    if (root->left) deleteTree(root->left);
    if (root->right) deleteTree(root->right);
    delete root;
}

int main() {
    int n, f;
    long ans{0};
    vector<Node*> allFreq;
    priority_queue<Node*, vector<Node*>, CompareNode> allNode;
    cin >> n;
    for (int i{0}; i < n; i++) {
        cin >> f;
        Node* tmp = new Node(f);
        allFreq.push_back(tmp);
        allNode.push(tmp);
    }
    Node* root = build(allNode);
    for (Node* node : allFreq) {
        ans+=calculateLen(node, root);
    }
    cout << ans << endl;
    deleteTree(root);
    return 0;
}