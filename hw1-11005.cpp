#include <iostream>
using namespace std;

class Node
{
    public:
        int num;
        Node *next;
        Node(int number)
        {
            num = number;
        }
};

class LinkedList 
{
    public:
        Node *head;
        LinkedList()
        {
            head = NULL;
        }
        bool check(int number)
        {
            if (head == NULL)
            {
                head = new Node(number);
                return false;
            }
            Node *tmp = head;
            while (true)
            {
                if (tmp->num == number)
                {
                    return true;
                }
                if (tmp->next == NULL)
                {
                    tmp->next = new Node(number);
                    return false;
                }
                tmp = tmp->next;
            }
        }
};

int main() {
    int totalSudoku;
    cin >> totalSudoku;
    string *result = new string[totalSudoku];
    int currentSudoku[81];
    bool flag;
    LinkedList checking = LinkedList();
    for (int i = 0; i < totalSudoku; i++)
    {
        for (int j = 0; j < 81; j++)
        {
            cin >> currentSudoku[j];
        }
        flag = false;

        // 检查每行
        for (int row = 0; row < 9; row++)
        {
            checking = LinkedList();
            for (int col = 0; col < 9; col++)
            {
                if (checking.check(currentSudoku[row * 9 + col]))
                {
                    *result = "Wrong\n";
                    result++;
                    flag = true;
                }
                if (flag)
                {
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        if (flag)
        {
            continue;
        }

        //检查每列
        for (int col = 0; col < 9; col++)
        {
            checking = LinkedList();
            for (int row = 0; row < 9; row++)
            {
                if (checking.check(currentSudoku[row * 9 + col]))
                {
                    *result = "Wrong\n";
                    result++;
                    flag = true;
                }
                if (flag)
                {
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        if (flag)
        {
            continue;
        }

        //检查每个九宫格
        for (int num = 0; num < 9; num++)
        {
            checking = LinkedList();
            int startIndex = (num / 3) * 27 + (num % 3) * 3;
            for (int subIndex = 0; subIndex < 9; subIndex++)
            {
                if (checking.check(currentSudoku[startIndex + (subIndex / 3 * 9 + subIndex % 3)]))
                {
                    *result = "Wrong\n";
                    result++;
                    flag = true;
                }
                if (flag)
                {
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        if (flag)
        {
            continue;
        }

        *result = "Right\n";
        result++;
    }

    result -= totalSudoku;
    for (int i = 0; i < totalSudoku; i++)
    {
        cout << *result;
        result++;
    }
}