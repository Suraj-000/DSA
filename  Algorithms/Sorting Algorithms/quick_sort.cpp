#include<iostream>

using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swap(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[], int low,int high){
    int pivot=arr[high];
    int i=(low-1);
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int main(){

    int arr[]={2,7,8,6,0,9,3,33,34,23,4,1,5,11,66,89};
    int n=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    quickSort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}