#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Node {
public:
    int value;
    int depth{0};
    Node* parent{NULL};
    int available;
    Node(int x) : value(x) {
        available = x == -1 ? 0 : 2;
    }
};

void build(vector<Node*>& preorder) {
    for (int i = 1; i < preorder.size(); i++) {
        Node* current = preorder[i];
        for (int j = i - 1; j >= 0; j--) {
            Node* tmp = preorder[j];
            if (tmp->available > 0) {
                tmp->available--;
                current->parent = tmp;
                current->depth = tmp->depth+1;
                break;
            }
        }
    }
}

int isCousin(vector<Node*>& preorder, int a, int b) {
    Node* nodeA, *nodeB;
    for (int i = 0; i < preorder.size(); i++) {
        if (preorder[i]->value == a) {
            nodeA = preorder[i];
            break;
        }
    }
    for (int i = 0; i < preorder.size(); i++) {
        if (preorder[i]->value == b) {
            nodeB = preorder[i];
            break;
        }
    }
    if (nodeA->parent != nodeB->parent && nodeA->depth == nodeB->depth) {
        return 1;
    } else {
        return 0;
    }
}

void deleteVec(vector<Node*>& preorder) {
    for (int j = preorder.size() - 1; j >= 0; j--) {
        delete(preorder[j]);
    }
}

int main() {
    int n;
    int a, b;
    string line;
    vector<int> pair;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        pair.push_back(a);
        pair.push_back(b);
    }
    cin.ignore();
    getline(cin, line);
    vector<Node*> preorder;
    stringstream ss(line);
    int value;
    while (ss >> value) {
        preorder.push_back(new Node(value));
    }
    build(preorder);
    for (int i = 0; i < n; i++) {
        cout << isCousin(preorder, pair[2 * i], pair[2 * i + 1]) << endl;
    }
    deleteVec(preorder);
    return 0;
}