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

    int Dequeue() {
        if (IsEmpty()) {
            cout << "The Queue is empty" << endl;
            return -1;
        }

        return data[front++];

       
        // if (front > rear) {
        //     front = rear = -1;
        // }
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

    int fact(int n){

        if(n<0){

            return -1;
        }


        Queue q1;

        for(int i=1; i<=n; i++){

            q1.Enqueue(i);
        }

        int result=1;

        while(!q1.IsEmpty()){

            result=result*q1.Dequeue();
        }

        return result;
    }


};

int main() {
    Queue q1;

    q1.Enqueue(10);
    q1.Enqueue(20);
    q1.Enqueue(30);
    q1.Enqueue(40);

   cout<< q1.fact(5)<<endl;

    // q1.Display();

    // q1.Dequeue();
    // q1.Dequeue();

    // q1.Display();

    return 0;
}
