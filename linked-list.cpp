//
// Created by gabra on 3/27/2025.
//

#include <iostream>
using namespace std;

template <class T>
class linked_list{
private:
    struct Node{
        T item;
        Node* next;
    };
    Node* first;
    Node* last;
    int length;

public:
    linked_list(){
        first = last = nullptr;
        length = 0;
    }

    bool isEmpty()
    {
        return first == nullptr;
    }
    void insertLast(T element)
    {
        Node* new_node = new Node;
        new_node->item = element;
        if (isEmpty()){
            first = last = new_node;
        }
        else{
            new_node->next = nullptr;
            last->next = new_node;
            last = new_node;
        }
        length++;
    }

    void insertFirst(T element)
    {
        Node* new_node = new Node;
        new_node->item = element;
        new_node->next = nullptr;
        if (isEmpty()){
            first = new_node;
            last = new_node;
        }

        else{
            new_node -> next = first;
            first = new_node;
        }
        length++;
    }

    T front (){ // here and in back
        if (isEmpty()) {
            cerr << "List is Empty!\n";
            return -1;
        }
        return first->item;
    }

    T back(){
        if (isEmpty()) {
            cerr << "List is Empty!\n";
            return -1;
        }
            return last-> item;
    }

    Node* begin(){
        return first;
    }

    Node* end(){
        return last;
    }

    int size(){
        return length;
    }

    void erase(T element) {
        if (isEmpty()){
            cout << "List is already Empty!!\n";
            return;
        }

        if (first->item == element) {
            Node* temp = first;
            first = first->next;

            if (first == nullptr) {
                last = nullptr;
            }

            delete temp;
            length--;
            return;
        }

        Node* current = first;
        while (current->next != nullptr) {
            if (current->next->item == element) {
                Node* deleteIt = current->next;
                current->next = current->next->next;

                if (deleteIt == last) {
                    last = current;
                }
                delete deleteIt;
                length--;
                return;  // Remove this return if you wish to delete all occurrences.
            }
            current = current->next;
        }

        // If we get here, the element was not found.
        cout << "Item doesn't belong to List!!\n";
    }


    int find(T element) {
        if (isEmpty()) {
            return -1;
        } else {
            Node* curr = first;
            int index = 0;
            while (curr != nullptr) {
                if (curr->item == element)
                    return index;
                curr = curr->next;
                index++;
            }
            return -1;
        }
    }

    void display(){
        if (isEmpty()){
            cout << "List doesn't has any items!!\n";
            return;
        }

        Node* curr = first;
        while (curr != nullptr){
            cout << curr->item << ' ';
            curr = curr->next;
        }
        cout << endl;
    }


    void clear(){
        while (first != nullptr) {
            Node* temp = first;
            first = first->next;
            delete temp;
        }
        length = 0;
        first = last = nullptr;
    }

~linked_list(){
    delete first;
    delete last;
    }
};

int main()
{
    linked_list<int> li;
    li.insertFirst(1);
    li.insertFirst(2);
    li.insertFirst(3);
    li.insertFirst(4);
    li.insertLast(7);

    li.display();
    cout << li.find(3) << endl;
    cout << "##########################\n";

    cout << li.front() << endl;
    cout << li.back() << endl;
    cout << li.size() << endl;
    cout << "##########################\n";

    cout << li.begin() << endl;
    cout << li.end() << endl;
    cout << "##########################\n";

    li.erase(444);
    li.erase(2);
    li.display();
    cout << li.size() << endl;
    cout << "##########################\n";

    li.clear();
    cout << li.front() << endl;
    li.display();
    cout << li.size() << endl;
    cout << "##########################\n";

    linked_list<int> li2(li);
    li2.display();
}