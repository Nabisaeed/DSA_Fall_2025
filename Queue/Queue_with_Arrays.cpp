#include <iostream>
using namespace std;

#define MAX 10

class Queue {
private:
    int data[MAX], front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool IsEmpty() {
        return (front == -1 || front > rear);
    }

    bool IsFull() {
        return rear == MAX - 1;
    }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "The Queue is full" << endl;
            return;
        }

        if (front == -1) front = 0;

        data[++rear] = value;
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "The Queue is empty" << endl;
            return;
        }

        cout << "Dequeued: " << data[front] << endl;
        front++;

       
        if (front > rear) {
            front = rear = -1;
        }
    }

    void Display() {
        if (IsEmpty()) {
            cout << "The Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    Queue q1;

    q1.Enqueue(10);
    q1.Enqueue(20);
    q1.Enqueue(30);
    q1.Enqueue(40);

    q1.Display();

    q1.Dequeue();
    q1.Dequeue();

    q1.Display();

    return 0;
}
