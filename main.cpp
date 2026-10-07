// COMSC 210 | Lab 21 | Yeji Kim

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MIN_LS = 5, MAX_LS = 20;
const int SIZE = 15;

class Goat {
    private: int age;
    string name;
    string color;

    //15 element names array
    string names[SIZE] = {
        "Billy",
        "Nanny",
        "Gruff",
        "Bucky",
        "Daisy",
        "Molly",
        "Ginger",
        "Coco",
        "Luna",
        "Bella",
        "Max",
        "Charlie",
        "Rocky",
        "Shadow",
        "Smokey"
    };

    //15 element colors array
    string colors[SIZE] = {
        "White",
        "Black",
        "Brown",
        "Gray",
        "Spotted",
        "Golden",
        "Cream",
        "Red",
        "Blue",
        "Green",
        "Yellow",
        "Purple",
        "Pink",
        "Silver",
        "Bronze"
    };

    public:
        // default constructor
        Goat() {
            age = rand() % 20 + 1;
            name = names[rand() % SIZE];
            color = colors[rand() % SIZE];
        }

    // parameterized constructor
    Goat(int a, string n, string c) {
        age = a;
        name = n;
        color = c;
    }

    void print() const {
        cout << name << " (" << color << ", " << age << ")" << endl;
    }
};

class DoublyLinkedList {
    private: struct Node {
        Goat data;
        Node * prev;
        Node * next;

        Node(Goat val, Node * p = nullptr, Node * n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };

    Node * head;
    Node * tail;

    public:
        // constructor
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
        }

    void push_back(Goat value) {
        Node * newNode = new Node(value);

        if (!tail)
            head = tail = newNode;
        else {
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat value) {
        Node * newNode = new Node(value);

        if (!head)
            head = tail = newNode;
        else {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }

    void print() {
        Node * current = head;

        if (!current) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Forward: " << endl;

        while (current) {
            current -> data.print();
            current = current -> next;
        }

        cout << endl;
    }

    void print_reverse() {
        Node * current = tail;

        if (!current) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Backward: " << endl;

        while (current) {
            current -> data.print();
            current = current -> prev;
        }

        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node * temp = head;
            head = head -> next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    srand(time(0));

    DoublyLinkedList list;

    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;

    for (int i = 0; i < size; ++i) {
        Goat goat;
        list.push_back(goat);
    }

    list.print();

    list.print_reverse();

    return 0;
}