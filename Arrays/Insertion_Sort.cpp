#include <iostream>
using namespace std;

void Insertion_Sort(int A[], int n){

    for(int i=1; i<n; i++){

        int key=A[i];

        int j=i-1;

        while(j>=0 && A[j]>key){

            A[j+1]=A[j];


            j--;


        }

        A[j+1]=key;


    }
}

int main() {

    int arr[]={125,34,120,7,3};

    Insertion_Sort(arr, 5);

    for(int i=0; i<5; i++){

        cout<<arr[i]<<"  ";


    }
cout<<endl;


    
    return 0;
}