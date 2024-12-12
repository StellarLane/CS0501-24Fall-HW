#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
        string content;
        Node *next;
        Node(string contents) {
            content = contents;
        }
};

class Stack {
    public:
        Node *top;
        Stack() {
            top = new Node("headNode");
        }
        void push(string contents) {
            Node *newNode = new Node(contents);
            newNode->next = top->next;
            top->next = newNode;
        }
        string pop() {
            if (isEmpty()) {
                return "";
            }
            Node *popNode = top->next;
            top->next = popNode->next;
            string popContent = popNode->content;
            delete popNode;
            return popContent;
        }
        bool isEmpty() {
            return top->next == NULL;
        }
        ~Stack() {
            while(!isEmpty()) {
                pop();
            }
            delete top;
        }
};

int toInt(string str) {
    int result = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '-') {
            continue;
        }
        result = result * 10 + str[i] - '0';
    }
    return str[0] == '-' ? -result : result;
}


int main() {
    Stack numStack = Stack();
    string input;
    cin >> input;
    string tmp;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '+') {
            int num1 = toInt(numStack.pop());
            int num2 = toInt(numStack.pop());
            numStack.push(to_string(num1 + num2));
            continue;
        }
        if (input[i] == '-') {
            int num1 = toInt(numStack.pop());
            int num2 = toInt(numStack.pop());
            numStack.push(to_string(num2 - num1));
            continue;
        }
        if (input[i] == '*') {
            int num1 = toInt(numStack.pop());
            int num2 = toInt(numStack.pop());
            numStack.push(to_string(num1 * num2));
            continue;
        }
        if (input[i] == '/') {
            int num1 = toInt(numStack.pop());
            int num2 = toInt(numStack.pop());
            numStack.push(to_string(num2 / num1));
            continue;
        }
        if (input[i] == '.') {
            numStack.push(tmp);
            tmp = "";
            continue;
        }
        tmp += input[i];
        if (input[i] == '@') {
            cout << numStack.pop() << endl;
            break;
        }
    }
    return 0;
}