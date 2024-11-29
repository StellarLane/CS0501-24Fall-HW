#include <iostream>
#include <string>
#include <stack>
using namespace std;

// bool checkOrder(stack<int> stack, int n)
// {
//     for (int i{0}; i < n; i++)
//     {
//         if (stack.top() + i != n)
//             return false;
//         stack.pop();
//     }
//     return true;
// }

// int main() 
// {
//     int T, n, tmp;
//     cin >> T;
//     for (int t{0}; t < T; t++)
//     {
//         cin >> n;
//         stack<int> shortStack;
//         stack<int> longStack;
//         for (int i{0}; i < n; i++)
//         {
//             cin >> tmp;
//             if (shortStack.empty() || shortStack.top() > tmp)
//             {
//                 shortStack.push(tmp);
//             }
//             else
//             {
//                 while (!shortStack.empty())
//                 {
//                     longStack.push(shortStack.top());
//                     shortStack.pop();
//                 }
//                 shortStack.push(tmp);
//             }
//         }
//         while (!shortStack.empty())
//         {
//             longStack.push(shortStack.top());
//             shortStack.pop();
//         }
//         if (checkOrder(longStack, n))
//             cout << "Yes" << endl;
//         else
//             cout << "No" << endl;
//     }
// }

class Node 
{
    public:
        int number;
        Node *next;
        Node(int inNumber) {
            number = inNumber;
            next = NULL;
        }
};

class Stack
{
    public:
        Node *top;
        Stack() {
            top = new Node(0);
        }
        void push(int number);
        int pop();
        int peek();
        void transfer(Stack stack);
        string checkOrder();
};

void Stack::push(int number)
{
    Node *tmp = new Node(number);
    tmp->next = top->next;
    top->next = tmp;
}

int Stack::pop()
{
    if (top->next == NULL)
    {
        return 0;
    }
    Node *tmp = top->next;
    int popNum{tmp->number};
    top->next = top->next->next;
    delete tmp;
    return popNum;
}

int Stack::peek()
{
    return top->next == NULL ? 0 : top->next->number;
}

void Stack::transfer(Stack stack) 
{
    int tmp;
    while (true)
    {
        tmp = this->pop();
        if(tmp == 0) break;
        stack.push(tmp);
    }
}

string Stack::checkOrder()
{
    Node *tmp1 = top->next;
    if (tmp1 == NULL || tmp1->next == NULL)
        return "Yes";
    Node *tmp2 = top->next->next;
    while (tmp2 != NULL)
    {
        if (tmp2->number == tmp1->number - 1) 
        {
            tmp1 = tmp2;
            tmp2 = tmp2->next;
            continue;
        }
        return "No";
    }
    return "Yes";
}

int main() 
{
    int T, n, tmp;
    cin >> T;
    Stack shortStack;
    Stack longStack;
    string *res = new string[T];
    for (int t{0}; t < T; t++)
    {
        shortStack = Stack();
        longStack = Stack();
        cin >> n;
        cin >> tmp;
        shortStack.push(tmp);
        for (int i{1}; i < n; i++)
        {
            cin >> tmp;
            if (tmp > shortStack.peek())
            {
                shortStack.transfer(longStack);
            }
            shortStack.push(tmp);
        }
        shortStack.transfer(longStack);
        res[t] = longStack.checkOrder();
        while (longStack.top->next != NULL) {
            Node *tmp = longStack.top->next;
            longStack.top->next = longStack.top->next->next;
            delete tmp;
        }
        // cout << longStack.checkOrder() << endl;
    }
    for (int t{0}; t < T; t++)
    {
        cout << res[t] << endl;        
    }
    return 0;
}