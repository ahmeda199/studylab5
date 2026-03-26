#ifndef SINGLELINK_H
#define SINGLELINK_H

#include <iostream>
using namespace std;

// basic node for singly linked list
struct Node {
    char data;
    Node* next;

    Node(char d) {
        data = d;
        next = NULL;
    }
};

class Stack {
private:
    Node* topNode;   // points to top of stack
    int count;       // keeps track of number of elements

public:
    Stack();
    ~Stack();

    void push(char e);
    char pop();
    char top();
    int size();
    bool empty();
    bool full(); 
    void stack_display();
};

#endif
