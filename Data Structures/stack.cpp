#include<vector>
#include<iostream> 
using namespace std;
class node{
    public:
    int data;
    node* next;

    node* Push(node* head,int x){
        node* newn=new node();
        newn->data=x;
        newn->next=NULL;
        if(head==NULL){head=newn;}
        else{
            node* temp=head;
            while(temp->next!=NULL){temp=temp->next;}
            temp->next=newn;
        }
        return head;
    }

    node* Pop(node* head){
        node* temp=head;
        if(head==NULL){return head;}
        else if(head->next==NULL){return head=NULL;}
        else{
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        return head;
        }
    }
    
    void Print(node* head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    int top(node* head){
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        return temp->data;
    }
};

int main(){
    node* stack;
    int t;
    cin>>t;
    int tt=t;
    stack=NULL;
    vector <int> v;
    int q=0;
    while(t--){int k;cin>>k;v.push_back(k);}
    long max=v[tt-1],min=v[tt-1];
    for(int i=tt-1;i>=0;i--){
        stack=stack->Push(stack,v[i]);
        long p;q++;
        if(v[i]<=min){min=v[i];}
        if(v[i-1]<min){
        p=v[i]*q;
        }
        else{
            p=min*q;
        }
        if(p>max){max=p;}
    cout<<p<<endl;
    }
    cout<<max<<endl;
    return 0;
}
