#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

class Trail {
public:
    int start;
    int end;
    Trail(int s, int e) : start(s), end(e) {}
};

class Node {
public:
    int value;
    int child{0};
    Node* left{nullptr};
    Node* right{nullptr};
    Node (int x) : value{x} {}
};

Node* build(const vector<int>& values) {
    queue<Node*> treeQueue;
    if (values.empty()) return NULL;
    Node* root = new Node(values[0]);
    treeQueue.push(root);
    for (int i{1}; i < values.size(); i++) {
        Node* tmp = new Node(values[i]);
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

void preOrder(Node* root, vector<int>& thisTreeReachble) {
    if (!root) return;
    thisTreeReachble.push_back(root->value);
    preOrder(root->left, thisTreeReachble);
    preOrder(root->right, thisTreeReachble);
}

Node* getDestNode(int dest, vector<Node*>& allRoot) {
    for (Node* root : allRoot) {
        if (!root) continue;
        stack<Node*> nodeStack;
        nodeStack.push(root);
        while(!nodeStack.empty()) {
            Node* tmp = nodeStack.top();
            nodeStack.pop();
            if (tmp->value == dest) return tmp;
            if (tmp->left) nodeStack.push(tmp->left);
            if (tmp->right) nodeStack.push(tmp->right);
        }
    }
    return nullptr;
}

Node* findTrailDest(int val, vector<Trail*>& allTrail, vector<Node*>& allRoot) {
    for (Trail* trail : allTrail) {
        if (val == trail->start) {
            int dest{trail->end};
            allTrail.erase(std::remove(allTrail.begin(), allTrail.end(), trail), allTrail.end());
            return getDestNode(dest, allRoot);
        }
    }
    return nullptr;
}

string findReachable(const vector<int>& reachable, int query) {
    for (int num : reachable) {
        if (query == num) return "Yes";
    }
    return "No";
}

void deleteTree(Node* root) {
    if(root->left) deleteTree(root->left);
    if(root->right) deleteTree(root->right);
    delete root;
}

int main() {
    int treeNum, trialNum, queryNum;
    vector<Node*> allRoot;
    vector<Trail*> allTrail;
    vector<int> reachable;
    cin >> treeNum;
    for (int i{0}; i < treeNum; i++) {
        int k;
        cin >> k;
        vector<int> thisTreeVal;
        int thisVal;
        for (int nodeNum{0}; nodeNum < static_cast<int>(pow(2, k) - 1); nodeNum++) {
            cin >> thisVal;
            thisTreeVal.push_back(thisVal);
        }
        allRoot.push_back(build(thisTreeVal));
    }
    cin >> trialNum;
    for (int i{0}; i < trialNum; i++) {
        int start, end;
        cin >> start >> end;
        allTrail.push_back(new Trail(start, end));
    }
    stack<Node*> reachableTreeStack;
    reachableTreeStack.push(allRoot[0]);
    vector<int> thisTreeReachable;
    while(!reachableTreeStack.empty()) {
        Node* tmp = reachableTreeStack.top();
        reachableTreeStack.pop();
        thisTreeReachable.clear();
        preOrder(tmp, thisTreeReachable);
        for (int value : thisTreeReachable) {
            Node* destNode{findTrailDest(value, allTrail, allRoot)};
            if (destNode) reachableTreeStack.push(destNode);
        }
        reachable.insert(reachable.end(), thisTreeReachable.begin(), thisTreeReachable.end());
    }
    cin >> queryNum;
    for (int i{0}; i < queryNum; i++) {
        int query;
        cin >> query;
        cout << findReachable(reachable, query) << endl;
    }
    for (Node* root : allRoot) {
        deleteTree(root);
    }
    for (Trail* trail : allTrail) {
        delete trail;
    }
    return 0;
}