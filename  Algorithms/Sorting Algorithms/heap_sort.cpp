#include<iostream>


using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void heapify(int arr[], int N, int i){
    int largest=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    if(l<N && arr[l]> arr[largest])largest=l;
    if(r<N && arr[r]>arr[largest])largest=r;
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,N,largest);
    }
}

void heapSort(int arr[],int N){
    for (int i=N/2-1;i>=0;i--)heapify(arr,N,i);
    for(int i=N-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main(){

    int arr[]={2,7,8,6,0,9,3,33,34,23,4,1,5,11,66,89};
    int n=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    heapSort(arr,n);
    printArray(arr,n);
    return 0;
}