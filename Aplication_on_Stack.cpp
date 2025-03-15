//
// Created by gabra on 3/16/2025.
//
#include <iostream>
using namespace std;

template <class T>
class stack
{
private:
    struct Node{
        T item;
        Node* next;
    };
    Node* Top = NULL;
public:

    bool isEmpty()
    {
        return Top == NULL;
    }
    void push(T it)
    {
        Node* new_one = new Node;     // new one to make a new box (node) to carry new item and pointer to previous node to still connected
        new_one -> item = it;
        new_one -> next = Top;
        Top = new_one;              // Top pointer now points to place of last added Node which have (item and pointer to previous Node)
    }

    void pop()
    {
        if (isEmpty())
            cout <<"Already empty\n";
        else
        {
            Node *temp = Top;     // to really delete the Node (item) which we need to be deleted (Avoid memory leak)
            Top = Top->next;
            delete temp;
        }

    }

    T top()  {
        return Top->item;
    }
    void print()
    {
        Node* to_print = Top;
        while (to_print != NULL)
        {
            cout << to_print->item <<' ';
            to_print = to_print->next;
        }
        cout << endl;
    }



};

int main()
{

    string line;
    cin >> line;
    int length = line.size();
    stack<char> arr;

    for (int i = 0; i < length; i++)
    {
        if (line[i] == '(') {
            arr.push('(');
        }
        else if (line[i] == '{') {
            arr.push('{');
        }
        else if (line[i] == ')')
        {
            if (arr.isEmpty() || arr.top() != '(')
            {
                cout << "Not Completed! \n";
                return 0;
            }
            else
                arr.pop();
        }
        else if (line[i] == '}')
        {
            if (arr.isEmpty() || arr.top() != '{')
            {
                cout << "Not Completed! (Bad)\n";
                return 0;
            }
            else
                arr.pop();
        }

    }

    cout << "Completed (Good)" << endl;
    return 0;
}