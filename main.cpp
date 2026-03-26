#include <iostream>
#include <cstring>
#include "singlelink.h"

using namespace std;


// 1a
void pushPopSequence() {
    Stack s;

    // given sequence
    //letter = push, if * pop on stack
    char input[] = "EAS*Y*QUE***ST***IO*N***";

    char output[100];
    int idx = 0;

    // loop through each character
    for (int i = 0; input[i] != '\0'; i++) {

        // if * then pop
        if (input[i] == '*') {
            output[idx++] = s.pop();
        }
        else {
            // otherwise push letter
            s.push(input[i]);
        }
    }

    output[idx] = '\0';

    cout << "\n1a Output Sequence: " << output << endl;
}


// helper for 1b
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}


// 1b
void balancedParentheses() {
    Stack s;

    char input[100];

    cout << "\nEnter parentheses string: ";
    cin >> input;

    for (int i = 0; input[i] != '\0'; i++) {

        char c = input[i];

        // if opening bracket, push it
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else {
            // if closing bracket, check stack
            if (s.empty() || !isMatching(s.top(), c)) {
                cout << "Not Balanced" << endl;
                return;
            }

            s.pop(); // match found, remove it
        }
    }

    // if stack empty, everything matched
    if (s.empty())
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
}


// 1c
void railroad() {

    // using chars here because the stack stores char
    char arr[] = {'2', '1', '3'};
    int n = 3;

    Stack siding;
    char next = '1';   // next car we want in order

    cout << "\nRailroad Simulation:" << endl;

    for (int i = 0; i < n; i++) {

        char car = arr[i];

        // if this is the next car we need, send it straight out
        if (car == next) {
            cout << "Car " << car << " goes directly to output" << endl;
            next++;

            // after sending one out, check if top of siding can come out too
            while (!siding.empty() && siding.top() == next) {
                cout << "Car " << siding.top() << " moves from siding to output" << endl;
                siding.pop();
                next++;
            }
        }
        else {
            // otherwise park it in the siding stack
            cout << "Car " << car << " pushed to siding" << endl;
            siding.push(car);
        }
    }

    // if anything is left in the siding, move it out
    while (!siding.empty()) {
        cout << "Car " << siding.top() << " moves from siding to output" << endl;
        siding.pop();
    }
}


int main() {

    cout << "Exercise 1a" << endl;
    pushPopSequence();

    cout << "\nExercise 1b" << endl;
    balancedParentheses();

    cout << "\nExercise 1c" << endl;
    railroad();

    return 0;
}
