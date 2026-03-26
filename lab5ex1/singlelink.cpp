#include "singlelink.h"

// constructor initializes empty stack
Stack::Stack() {
    topNode = NULL;
    count = 0;
}

// destructor frees memory so no leaks happen
Stack::~Stack() {
    while (!empty()) {
        pop(); // just keep popping everything
    }
}

// push = add to top (head of linked list)
void Stack::push(char e) {
    Node* newNode = new Node(e);

    // new node points to old top
    newNode->next = topNode;

    // update top
    topNode = newNode;

    count++;
}

// pop = remove from top
char Stack::pop() {
    if (empty()) {
        cout << "Stack underflow" << endl;
        return '\0';
    }

    Node* temp = topNode;
    char val = temp->data;

    // move top down
    topNode = topNode->next;

    delete temp; // free memory
    count--;

    return val;
}

// just return top value
char Stack::top() {
    if (empty()) return '\0';
    return topNode->data;
}

// number of elements
int Stack::size() {
    return count;
}

// check if empty
bool Stack::empty() {
    return (topNode == NULL);
}

// linked list never really gets "full"
bool Stack::full() {
    return false;
}

// print stack from top to bottom
void Stack::stack_display() {
    Node* curr = topNode;

    cout << "Stack (top -> bottom): ";
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
