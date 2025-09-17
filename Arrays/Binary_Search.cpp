#include <iostream>
using namespace std;

int BinarySearch(int A[], int n, int target, int left, int right){

    while(left<=right){

        int mid=(left+right)/2;

        if(A[mid]==target){

            return mid;
        }

        if(A[mid]>target){

            right=mid-1;
        }

        if(A[mid]<target){

            left=mid+1;
        }
    }

    return -1;
}

int main() {

    int arr[]={12,34,56,67,89,100,120},num;

    cout<<"Enter the value to search "<<endl;

    cin>>num;



    int index=BinarySearch(arr,7, num, 0, 6);


    if(index>=0){

        cout<<"The value is found at position "<<index+1<<endl;


    }

    else{

        cout<<"Sorry the value is not found"<<endl;
    }


    
    return 0;
}