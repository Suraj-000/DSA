#include<iostream>

using namespace std;

struct HashNode{
    int key;
    int value;
};

const int capacity=20;
int size=0;

struct HashNode* arr[capacity];
struct HashNode* dummy;

void insert(int key,int v){

    struct HashNode* temp=new HashNode();
    temp->key=key;
    temp->value=v;

    int hashIndex=key%capacity;

    while(arr[hashIndex]!=NULL 
            && arr[hashIndex]->key!=key
            && arr[hashIndex]->key!=-1
    ){
        hashIndex++;
        hashIndex%=capacity;
    }

    if( arr[hashIndex]==NULL || arr[hashIndex]->key==-1)size++;

    arr[hashIndex]=temp;
}

int delete_ (int key)
{
    int hashIndex = key % capacity;
    while (arr[hashIndex] != NULL) {
        if (arr[hashIndex]->key == key) {
            arr[hashIndex] = dummy;
            size--;
            return 1;
        }
        hashIndex++;
        hashIndex %= capacity;
    }
    return 0;
}

int find(int key){
    int hashIndex=(key%capacity);
    int counter=0;

    while(arr[hashIndex]!= NULL){

        int counter = 0;
        if (counter++ >capacity)break;

        if(arr[hashIndex]->key==key)return arr[hashIndex]->value;

        hashIndex++;
        hashIndex%=capacity;
    }
    return -1;
}

int main(){
    for (int i = 0;i< capacity; i++ )arr[i] = NULL;
    dummy=new HashNode();
    dummy->key=-1;
    dummy->value=-1;
    insert(1, 5);
    insert(2, 15);
    insert(3, 20);
    insert(4, 7);

    if (find(4) != -1)cout<<"Value of Key 4 = "<< find(4)<<endl;
    else cout<<"Key 4 does not exists\n";
    if (delete_(4))cout<<"Node value of key 4 is deleted successfully\n";
    else cout<<"Key does not exists\n";
    if (find(4) != -1)cout<<"Value of Key 4 = "<< find(4)<<endl;
    else cout<<"Key 4 does not exists\n";

    return 0;
}