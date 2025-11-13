#include <iostream>
using namespace std;

void Selection_Sort(int arr[], int size){


    for(int i=0; i<size-1; i++){

        int min=i;


        for(int j=i+1; j<size; j++){

            if(arr[j]<arr[min]){
                min=j;

            }
        }
        int temp= arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }

}

int main() {


    int arr[]={12,45,7,78,3};


    Selection_Sort(arr, 5);

    for(int i=0; i<5; i++){

        cout<<arr[i]<<" ";
    }
   

    return 0;
}