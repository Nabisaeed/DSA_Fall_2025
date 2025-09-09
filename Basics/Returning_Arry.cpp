#include <iostream>
using namespace std;

int* returnarr(){

    int *arr= new int[5];

    for(int i=0;i<5;i++){

        arr[i]=i+2;
    }

    return arr;
}
void test(){

    cout<<"This is test function"<<endl; //
}

int main() {

    int *p1=returnarr();

    test();
    cout<<*p1<<endl;
    
    return 0;
}