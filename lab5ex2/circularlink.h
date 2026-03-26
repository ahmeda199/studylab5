#ifndef CIRCULARLINK_H
#define CIRCULARLINK_H

#include <iostream>
using namespace std;

// each node stores one value and points to the next node
struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Queue { //circular list isnt directly defined
private: //we know its circular bc of how pointers connected in .cpp file
    Node* rear;   // rear points to the last node
    int count;    // keeps track of how many items are in the queue

public:
    Queue();
    ~Queue();

    void enqueue(int e);
    int dequeue();
    int front();
    int size();
    bool empty();
    bool full();
    void queue_display();
};

#endif
