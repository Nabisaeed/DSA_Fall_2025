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

    int hash1(int key) {
        return key % size;
    }

    int hash2(int key) {
        return 1 + (key % (size - 1));
    }

    void insert(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int i = 0;

        while (table[(index + i * step) % size] != -1) {
            i++;
        }

        table[(index + i * step) % size] = key;
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
