#include <iostream>
using namespace std;

class student{

    public:
    string name;
    int reg_no;


};



int main() {

    student *s1= new student;
    
    s1->name="Asad";
    s1->reg_no=2024541;

    cout<<s1->reg_no<<endl;
    
    return 0;
}