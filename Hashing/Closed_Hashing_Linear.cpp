#include <iostream>
using namespace std;

class HashTable {
    int* table;
    int size;

public:
    HashTable(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1;
    }

    void insert(int key) {
        int index = key % size;
        while (table[index] != -1) {
            index = (index + 1) % size;
        }
        table[index] = key;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << ": " << table[i] << endl;
    }
};

int main() {
    HashTable ht(7);
    ht.insert(50);
    ht.insert(700);
    ht.insert(76);
    ht.display();
}
