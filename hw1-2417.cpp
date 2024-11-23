#include <iostream>
using namespace std;

class Node {
  private:
    long numThis;
    int count;
  public:
    Node *next;
    Node(long number);
    void increase();
    long getNum();
    int getCount();
};

Node::Node(long number) {
  numThis = number;
  count = 1;
  next = NULL;
}

void Node::increase() {
  count++;
}

long Node::getNum() {
  return numThis;
}

int Node::getCount() {
  return count;
}

class LinkedList {
  public:
    Node *head;
    LinkedList();
    void check(long num);
    long findBiggest();
};

LinkedList::LinkedList() {
  head = NULL;
}

void LinkedList::check(long num) {
  if (head == NULL) {
    Node *tmpNode = new Node(num);
    head = tmpNode;
    return;
  }
  Node *tmp = head;
  while (true) {
    if (num == tmp->getNum()) {
      tmp->increase();
      return;
    }
    if (tmp->next == NULL) {
      break;
    }
    tmp = tmp->next;
  }
  tmp->next = new Node(num);
}

long LinkedList::findBiggest() {
  int count = head->getCount();
  Node *tmp = head;
  while (tmp->next)
  {
    if (tmp->getCount() > count) {
      count = tmp->getCount();
    }
    tmp = tmp->next;
  }
  return count;
}

int main() {
  int totalLen;
  cin >> totalLen;
  LinkedList numberList = LinkedList();
  long* input = new long[totalLen];
  for (int i = 0; i < totalLen; i++)
  {
    cin >> *input;
    input++;
  }
  for (int i = 0; i < totalLen; i++) {
    input--;
    numberList.check(*input);
  }
    cout << (numberList.findBiggest()) << endl;
  return 0;
}