#include<iostream>

using namespace std;

int binarySearch(int array[],int l,int r,int x){
    if(r>=l){
        int mid=l+(r-1)/2;
        if(array[mid]==x)return mid;
        if(array[mid]>x)return binarySearch(array,l,mid-1,x);
        return binarySearch(array,mid+1,r,x);
    }
    return -1;
}

int main(){
    int array[]={1,2,3,4,5,6,7,8,9};
    int n=10;
    int result=binarySearch(array,0,n-1,9);
    if(result==-1)cout<<"element not found\n";
    else cout<<"element found at index "<<result<<endl;
    return 0;
}