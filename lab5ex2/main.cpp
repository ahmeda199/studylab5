#include <iostream>
#include "circularlink.h"

using namespace std;

//solves the Josephus problem using the queue
void josephusProblem() {
    Queue q;
    int n, step;

    cout << "Enter number of people: ";
    cin >> n;

    cout << "Enter n-th value to kill: ";
    cin >> step;

    // put people into queue as 1, 2, 3, to n
    for (int i = 1; i <= n; i++) {
        q.enqueue(i);
    }

    cout << "\nPeople killed in order:" << endl;

    // keep going until everyone in queue dead
    while (!q.empty()) {
    //this kills the person at nth value
//rotates queue back step -1 and kills person at front 
     //step -1 to get to next nth value
        //use i=1 to show step-1

        //rotate
        for (int i = 1; i < step; i++) {
            int person = q.dequeue();
            q.enqueue(person);
        }

        // the next person is removed
        cout << q.dequeue();

        if (!q.empty()) {
            cout << ", ";
        }
    }

    cout << endl;
}

int main() {
    josephusProblem();
    return 0;
}
