//
// Created by gabra on 3/23/2025.
//

#include <iostream>
using namespace std;

template <class T>
class Queue {
private:
    struct Node {
        T item;
        Node* next;
    };
    Node* front;
    Node* back;
    int length;
public:
    Queue() : front(nullptr), back(nullptr), length(0) { }

    bool isEmpty() const {
        return length == 0;
    }

    void enqueue(T it) {
        Node* newNode = new Node;
        newNode->item = it;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = back = newNode;
        }
        else {
            back->next = newNode;
            back = newNode;
        }
        length++;
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
            length--;
            // If the queue becomes empty, update back to nullptr.
            if (isEmpty())
                back = nullptr;
        }
        else {
            cout << "Queue is empty. Cannot dequeue." << endl;
        }
    }

    void getfront() const {
        if (!isEmpty())
            cout << front->item;
        else
            cout << "Queue is empty.";
    }

    void getback() const {
        if (!isEmpty())
            cout << back->item;
        else
            cout << "Queue is empty.";
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* curr = front;
        while (curr != nullptr) {
            cout << curr->item << ' ';
            curr = curr->next;
        }
        cout << endl;
    }

    void clear() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        back = nullptr;
        length = 0;
    }

    ~Queue() {
        clear();
    }
};

int main() {
    Queue<int> qu;
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.enqueue(4);
    qu.display();
    qu.dequeue();
    qu.display();

    qu.getfront();
    cout << endl;
    qu.getback();
    cout << endl;
    qu.clear();
    qu.display();

    return 0;
}
