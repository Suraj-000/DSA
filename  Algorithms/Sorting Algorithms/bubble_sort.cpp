#include<iostream>

using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[],int n){
    int i,j;
    for (i=0;i<n-1;i++){
        for (j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int t;
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    printArray(arr,n);
}

int main(){

    int arr[]={2,7,8,4,5,6,0,9,3,1,33};
    int n=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    bubbleSort(arr,n);
    return 0;
}