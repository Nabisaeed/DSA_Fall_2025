#include <iostream>
using namespace std;

int main() {

    int arr[100]= {100,34,50,12}, temp, n;

    for(int i=0;i<n; i++){

        for(int j=i+1; j<n; j++){

            if(arr[i]>arr[j]){

                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }


        }


    }
for(int i=0; i<4; i++){  

    cout<<arr[i]<<"  ";
}

cout<<endl;

    
    return 0;
}