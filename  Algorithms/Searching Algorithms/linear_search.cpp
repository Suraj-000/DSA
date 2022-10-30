#include<iostream>

using namespace std;

void search(int array[],int size,int x){
    int i,t=0;
    for( i=0;i<size;i++){
        if(array[i]==x){
            cout<<"found\n";
            t=1;
            }
    }
    if(t==0)cout<<"not found\n";
}

int main(){
    int array[]={1,4,2,3,5,6,5,7,8,9};
    int size=10;
    search(array,size,10);
    search(array,size,8);
    return 0;

}