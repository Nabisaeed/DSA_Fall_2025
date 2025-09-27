#include <iostream>
using namespace std;

// Simple class to represent a student with a name and registration number
class student {
public:
    string name;
    int reg_no;
};

int main() {
    // Dynamically allocate memory for a student object
    student* s1 = new student;

    // Initialize the student’s attributes
    s1->name = "Asad";
    s1->reg_no = 2024541;

    // Output the registration number to the console
    cout << s1->reg_no << endl;

    return 0;
}
