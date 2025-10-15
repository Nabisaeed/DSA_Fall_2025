#include <iostream>
#include <string>
using namespace std;


class Stack {
private:
    int arr[100];   
    int top;

public:
    Stack() { top = -1; }

    void push(int value) {
        if (top > 99) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return (top == -1);
    }
};


int evaluatePostfix(string exp) {
    Stack s; 

    for (char c : exp) {
        if (c >= '0' && c <= '9') {
            s.push(c - '0'); 
        }
        else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                default: cout << "Invalid operator: " << c << endl;
            }
        }
    }

    return s.pop(); 
}


int main() {
    string expr = "342*+"; 
    cout << "Postfix Expression: " << expr << endl;
    cout << "Result: " << evaluatePostfix(expr) << endl;
    return 0;
}
