#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int x) : value(x) {}
};

class LinkedList {
public:
    Node* head;
    Node* cur;
    LinkedList() : head(new Node(NULL)), cur(head) {}
    void append(int x);
    void search(int x, int& ans);
    void switchToFront();
    void deleteLL();
};

void LinkedList::append(int x) {
    cur->next = new Node(x);
    cur = cur->next;
}

void LinkedList::switchToFront() {
    Node* tmp = cur->next;
    cur->next = cur->next->next;
    tmp->next = head->next;
    head->next = tmp;
}

void LinkedList::search(int x, int &ans) {
    cur = head;
    while (cur->next) {
        ans++;
        if (cur->next->value == x) {
            switchToFront();
            break;
        }
        cur = cur->next;
    }
}

void LinkedList::deleteLL() {
    cur = head->next;
    while (cur) {
        delete cur;
    }
    delete head;
}

int main() {
    int n, m, tmp;
    int ans{0};
    cin >> n;
    LinkedList ll = LinkedList();
    for (int i{0}; i < n; i++) {
        cin >> tmp;
        ll.append(tmp);
    }
    cin >> m;
    for (int i{0}; i < m; i++) {
        cin >> tmp;
        ll.search(tmp, ans);
    }
    cout << ans;
    return 0;
}