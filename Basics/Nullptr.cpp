#include <iostream>
using namespace std;

int main() {

    int a=20;

    int * p1=nullptr;

    if(p1){

        cout<<"The pointer is not null and it's value is:"<<*p1<<endl;
    }

    else{

        cout<<"The pointer is null"<<endl;
    }
    
    return 0;
}