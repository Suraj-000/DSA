#include<iostream>

using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void merge(int array[], int left, int mid, int right){
    int leftarraylength=mid-left+1;
    int rightarraylength=right-mid;

    int *templeftarray= new int[leftarraylength];
    int *temprightarray= new int[rightarraylength];

    for(int i=0;i<leftarraylength;i++)templeftarray[i]=array[left+i];
    for(int i=0;i<rightarraylength;i++)temprightarray[i]=array[mid+1+i];
    // printArray(templeftarray,leftarraylength);
    // printArray(temprightarray,rightarraylength);
    
    int leftarrayindex=0,rightarraytindex=0;
    int mergedarrayindex=left;
    
    while(leftarrayindex<leftarraylength && rightarraytindex<rightarraylength){
        if(templeftarray[leftarrayindex]<=temprightarray[rightarraytindex]){
            array[mergedarrayindex]=templeftarray[leftarrayindex];
            leftarrayindex++;
            mergedarrayindex++;
        }
        else{
            array[mergedarrayindex]=temprightarray[rightarraytindex];
            rightarraytindex++;
            mergedarrayindex++;
        }
    }

    while(leftarrayindex<leftarraylength){
        array[mergedarrayindex]=templeftarray[leftarrayindex];
        leftarrayindex++;
        mergedarrayindex++;
    }
    while(rightarraytindex<rightarraylength){
        array[mergedarrayindex]=temprightarray[rightarraytindex];
        rightarraytindex++;
        mergedarrayindex++;        
    }
    delete[] templeftarray;
    delete[] temprightarray;
    // printArray(array,right+1);
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main(){

    int arr[]={2,7,8,6,0,9,3,33,34,23,4,1,5,11,66,89};
    int n=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    mergeSort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}