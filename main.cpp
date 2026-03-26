#include <iostream>
#include <string>
#include "singlelink.h"

using namespace std;


// 1a
void pushPopSequence() {
    Stack s;

    // given sequence
    //letter = push, if * pop on stack
    string input = "EAS*Y*QUE***ST***IO*N***";

    string output = "";

    // loop through each character
    for (int i = 0; i < input.length(); i++) {

        // if * then pop
        if (input[i] == '*') {
            output += s.pop();
        }
        else {
            // otherwise push letter
            s.push(input[i]);
        }
    }

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

    string input;

    cout << "\nEnter parentheses string: ";
    cin >> input;

    for (int i = 0; i < input.length(); i++) {

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

int main() {

    cout << "Exercise 1a" << endl;
    pushPopSequence();

    cout << "\nExercise 1b" << endl;
    balancedParentheses();

    return 0;
}
