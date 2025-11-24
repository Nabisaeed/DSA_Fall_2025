#include <iostream>
using namespace std;

void divide(int arr[], int left, int right){

    int mid=left+ (right-left)/2;


    int n1=mid-left+1;
    int n2=right-mid;


    int L[n1];
    int R[n2];


    for(int i=0; i<n1; i++){

        L[i]=arr[i];
    }

      for(int j=0; j<n2; j++){

        R[j]=arr[mid+1+j];
    }


    cout<<"The left sub array is :";

    for(int i=0; i<n1; i++){

        cout<<L[i]<<" ";
    }

    cout<<endl;

        cout<<"The right sub array is :";

    for(int i=0; i<n2; i++){

        cout<<R[i]<<" ";
    }
    cout<<endl;
    




}

int main() {


    int arr[]={12,3,5,6,2};

    int size=sizeof(arr)/sizeof(arr[0]);


    divide(arr, 0, size-1);


    
    return 0;
}