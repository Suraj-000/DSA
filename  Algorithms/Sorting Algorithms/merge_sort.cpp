#include<iostream>

using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void merge(int array[],int const left ,int const mid , int const right){

}

void mergeSort(int array[],int const begin,int const end){
    if (begin>=end)return;
    auto mid=begin+(end-begin)/2;
    mergeSort(array,begin,mid);
    mergeSort(array,mid+1,end);
    merge(array,begin,mid,end);

}

int main(){

    int arr[]={2,7,8,4,5,6,0,9,3,1,33};
    int n=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    mergeSort(arr,0,n-1);
    return 0;
}