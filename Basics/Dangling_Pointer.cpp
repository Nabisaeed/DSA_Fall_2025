#include <iostream>
using namespace std;

int * add (){

    int a=20, b=10, c;

    c=a+b;

    return &c;
}

void test1(){

    cout<<"This is test function : "<<endl;
}

int main() {

    int *p1=add();

    test1();

    cout<<*p1<<endl;

    
    
    return 0;
}