#include <iostream>
using namespace std;

// Define the maximum capacity of the stack
#define MAX 5

// A stack implemented using a static array
class Stack {

    int data[MAX];   // Fixed-size array to store elements
    int top;         // Index of the top element in the stack

public:

    // Constructor initializes the stack as empty
    Stack() {
        top = -1; // -1 indicates no elements are in the stack
    }

    // Checks whether the stack has reached its maximum capacity
    bool IsFull() {
        if (top == MAX - 1)
            return true;  // Stack overflow condition
        return false;
    }

    // Checks whether the stack is empty
    bool IsEmpty() {
        if (top == -1)
            return true;  // Stack underflow condition
        return false;
    }

    // Push operation: adds a new element on top of the stack
    void push(int value) {
        if (IsFull()) {
            cout << "The stack is full (Overflow condition)" << endl;
            return;
        }

        // Pre-increment ensures top moves to next position before assignment
        data[++top] = value;
        cout << "Pushed: " << value << endl;
    }

    // Display all elements from top to bottom
    void display() {
        if (IsEmpty()) {
            cout << "There are no elements (Stack is empty)" << endl;
            return;
        }

        cout << "\nCurrent Stack elements (Top → Bottom):" << endl;

        // Print elements in reverse order since top is at higher index
        for (int i = top; i >= 0; i--) {
            cout << data[i] << endl;
        }
    }

    // Pop operation: removes the topmost element
    void pop() {
        if (IsEmpty()) {
            cout << "Cannot pop — Stack is empty (Underflow condition)" << endl;
            return;
        }

        cout << "The popped element is: " << data[top] << endl;
        top--; // Decrement top to remove element logically
    }

    // Peek operation: shows the element at the top without removing it
    void peek() {
        if (IsEmpty()) {
            cout << "No elements to peek (Stack is empty)" << endl;
            return;
        }

        cout << "The last (top) element is: " << data[top] << endl;
    }
};

// Driver function to demonstrate stack operations
int main() {
    Stack s;

    // Sequential stack operations
    s.push(100);
    s.push(200);
    s.push(300);
    s.push(400);
    s.push(500);

    s.pop();  // Removes 500
    s.pop();  // Removes 400

    s.peek(); // Shows curre
}