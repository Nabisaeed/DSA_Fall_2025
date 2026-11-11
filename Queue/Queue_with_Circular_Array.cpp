
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
        return (front == -1);
    }

    bool IsFull() {
        return ((rear + 1) % MAX == front);
    }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "The Queue is full" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % MAX;
        data[rear] = value;
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "The Queue is empty" << endl;
            return;
        }

        cout << "Dequeued: " << data[front] << endl;

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX;
        }
    }

    void Display() {
        if (IsEmpty()) {
            cout << "The Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";

        int i = front;

        while (true) {
            cout << data[i] << " ";

            if (i == rear) {
                break;
            }

            i = (i + 1) % MAX;
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
