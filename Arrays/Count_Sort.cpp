#include <iostream>
using namespace std;


void CountSort(int A[], int n){

    int max=A[0];

    for(int j=1; j<n; j++){

        if(A[j]>max){

            max=A[j];
        }
    }

    int * Count= new int[max+1]{0};

    for(int i=0; i<n; i++){

        Count[A[i]]++;
    }

    int index=0; 

    for(int i=0; i<=max; i++){

        while(Count[i]>0){

            A[index++]=i;
            Count[i]--;

        }

        
    }

    delete [] Count;





}

int main() {

    int arr[]={2,1,4,5,3,2,6,7,5};

    int size= sizeof(arr)/sizeof(arr[0]);

    CountSort(arr, size);

    for(int i=0; i<size; i++){

        cout<<arr[i]<<" ";
    }

    cout<<endl;


    
    return 0;
}