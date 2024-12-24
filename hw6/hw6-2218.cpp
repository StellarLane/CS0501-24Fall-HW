#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int value;
    Node* left{nullptr};
    Node* right{nullptr};
    Node(int x) : value(x) {}
};

class BSTree {
public:
    Node* root{nullptr};
    BSTree() {}
};

Node* buildTree(vector<int>& input, int& index) {
    if (index >= input.size() || input[index] == -1) {
        index++;
        return nullptr;
    }
    Node* node = new Node(input[index++]);
    node->left = buildTree(input, index);
    node->right = buildTree(input, index);
    return node;
}

void iterate(Node* node, vector<int>& output) {
    if (!node) return;
    iterate(node->left, output);
    output.push_back(node->value);
    iterate(node->right, output);
}

void deleteTree(Node* node) {
    if (node->left) deleteTree(node->left);
    if (node->right) deleteTree(node->right);
    delete node;
}

int main() {
    int tmp, index{0}, ans{10000000};
    vector<int> input;
    vector<int> output;
    BSTree tree;
    while (cin >> tmp) {
        input.push_back(tmp);
        if (cin.peek() == '\n') {
            break;
        }
    }
    tree.root = buildTree(input, index);
    iterate(tree.root, output);
    for (int i{1}; i < output.size(); i++) {
        ans = output[i] - output[i - 1] < ans ? output[i] - output[i - 1] : ans;
    }
    cout << ans << endl;

    return 0;
}