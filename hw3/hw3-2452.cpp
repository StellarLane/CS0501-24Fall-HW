#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

class TreeNode {
public:
    long long value;
    int child{0};
    TreeNode* left{NULL};
    TreeNode* right{NULL};
    TreeNode(long long x) : value(x) {}
};

TreeNode* build(const vector<long long>& values) {
    queue<TreeNode*> treeQueue;
    if (values.empty()) return NULL;
    TreeNode* root = new TreeNode(values[0]);
    treeQueue.push(root);
    for (int i{1}; i < values.size(); i++) {
        TreeNode* tmp = new TreeNode(values[i]);
        treeQueue.push(tmp);
        switch (treeQueue.front()->child) {
            case 0:
                treeQueue.front()->left = tmp;
            treeQueue.front()->child++;
            break;
            case 1:
                treeQueue.front()->right = tmp;
            treeQueue.front()->child++;
            break;
            case 2:
                treeQueue.pop();
            treeQueue.front()->left = tmp;
            treeQueue.front()->child++;
            break;
            default: ;
        }
    }
    return root;
}

void deleteTree(TreeNode* root) {
    if (!root->left) deleteTree(root->left);
    if (!root->right) deleteTree(root->right);
    delete root;
}

void inOrder(TreeNode* root, vector<long long>& results) {
    if (!root) return;
    inOrder(root->right, results);
    results.push_back(root->value);
    inOrder(root->left, results);
}

int main() {
    int n{0}, nBiggest;
    vector<long long>treeVals;
    for (int i{0};  i < 7; i++) {
        cin >> n;
        treeVals.push_back(n);
    }
    TreeNode* root = build(treeVals);
    cin >> nBiggest;
    vector<long long> inOrderRes;
    inOrder(root, inOrderRes);
    cout << inOrderRes[nBiggest - 1];
    deleteTree(root);
    return 0;
}