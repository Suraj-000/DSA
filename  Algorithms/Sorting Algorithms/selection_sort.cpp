#include<iostream>

using namespace std;

void swap(int *xp,int *yp){
    int temp=*xp;
    *xp=*yp;
    *yp=temp;
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int arr[],int n){

    int i,j,min_idx;
    for(i=0;i<n-1;i++){
        min_idx=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx])min_idx=j;
        }
        if(min_idx!=i)swap(&arr[min_idx],&arr[i]);
    }


    printArray(arr,n);
}


int main(){

    int arr[]={2,7,8,4,5,6,0,9,3,1,33};
    int n=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    selectionSort(arr,n);
    return 0;
}