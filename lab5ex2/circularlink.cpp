#include "circularlink.h"

// queue starts empty
Queue::Queue() {
    rear = nullptr;
    count = 0;
}

// destructor to free all nodes
Queue::~Queue() {
    while (!empty()) {
        dequeue();
    }
}

// add to back of queue
void Queue::enqueue(int e) {
    Node* newNode = new Node(e);

    // if queue is empty, new node points to itself
    if (empty()) {
        rear = newNode;
        rear->next = rear;
    }
    else {
        // new node goes after rear and points to front
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;  // move rear forward
    }

    count++;
}

// remove from front of queue
int Queue::dequeue() {
    if (empty()) {
        //can use /n instead of endl
        cout << "Queue underflow" << endl;
        return -1;
    }

    Node* frontNode = rear->next;
    int val = frontNode->data;

    // if only one node exists
    if (rear == frontNode) {
        rear = nullptr; 
    }
    else {
        // skip over old front
        rear->next = frontNode->next;
    }

    delete frontNode; //free memory
    count--;

    return val;
}

// return front element without removing it
int Queue::front() {
    if (empty()) {
        return -1;
    }

    return rear->next->data;
}

// return number of elements
int Queue::size() {
    return count;
}

// check if queue empty
bool Queue::empty() {
    return (rear == nullptr);
}

// linked list queue is basically never full unless memory runs out
bool Queue::full() {
    return false;
}

// display queue from front to rear
void Queue::queue_display() {
    if (empty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    Node* curr = rear->next; // start at front

    cout << "Queue (front -> rear): ";
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != rear->next);

    cout << endl;
}
