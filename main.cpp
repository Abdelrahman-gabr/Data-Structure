// Stack Implementation Using Linked list concept
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

    stack<int> arr;
    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.push(4);
    arr.print();
    arr.pop();
    arr.push(5);
    arr.print();
    return 0;
}
