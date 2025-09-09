#include <iostream>
using namespace std;

int main() {

    int a=20;

    int *p1;

    p1=&a;

    // cout<<&a<<endl;

    *p1=100;

    cout<<*p1<<endl;

    int &b=a;
    
    return 0;
}