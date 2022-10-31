#include<iostream>

using namespace std;
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertionSort(int arr[],int n){
    int key,j;
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    printArray(arr,n);
}
int main(){
    int arr[]={4,2,5,6,1,8,2,9};
    int n=8;
    printArray(arr,n);
    insertionSort(arr,n);
    return 0;
}