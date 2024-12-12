#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int value;
    Node* left{NULL};
    Node* right{NULL};
    Node(const int x): value(x) {}
};

Node* findNode(int x, const vector<Node*> allNodes) {
    for (Node* node: allNodes) {
        if (node->value == x) return node;
    }
    return new Node(x);
}

void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->value << " ";
}

void deleteTree(Node* root) {
    if (root->left) deleteTree(root->left);
    if (root->right) deleteTree(root->right);
    delete root;
}

int main() {
    int n, value, childLEFT, childRIGHT;
    cin >> n;
    Node* root;
    vector<Node*> allNodes;
    for (int i{0}; i < n; i++) {
        cin >> value >> childRIGHT >> childLEFT;
        Node* tmp = findNode(value, allNodes);
        if(childLEFT != -1) {
            Node* tmpChildLeft = new Node(childLEFT);
            tmp->left = tmpChildLeft;
            allNodes.push_back(tmpChildLeft);
        }
        if(childRIGHT != -1) {
            Node* tmpChildRight = new Node(childRIGHT);
            tmp->right = tmpChildRight;
            allNodes.push_back(tmpChildRight);
        }
        if (i == 0) root = tmp;
    }
    postOrder(root);
    allNodes.empty();
    deleteTree(root);
    cout << endl;
    return 0;
}