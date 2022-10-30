#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node* getnewnode(){
        Node* newnode=new Node();
        int x;
        cout<<"enter the data"<<endl;
        cin>>x;
        newnode->data=x;
        newnode->next=NULL;
        newnode->prev=NULL;
        return newnode;
    }

    void insertfront(Node** head){
        Node* newn=getnewnode();
        if(*head==NULL){
            *head=newn;
            return;
        }
        Node* temp;
        temp=*head;
        temp->prev=newn;
        newn->next=temp;
        temp=newn;
        *head=temp;
    }

    void insertend(Node** head){
        Node* newn=getnewnode();
        if(*head==NULL){
            *head=newn;
            return;
        }
        Node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }

    void insertN(Node** head){
        Node* newn=getnewnode();
        if(*head==NULL){
            *head=newn;
            return;
        }
        int d;
        cout<<"enter the position"<<endl;
        cin>>d;
        Node* temp=*head;
        while(d--){
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        newn->prev=temp;
        temp->next=newn;
    }

    void deleteEnd(Node** head){
        if(*head==NULL)return;
        else{
            Node* temp=*head;
            while(temp->next->next!=NULL)temp=temp->next;
            temp->next=NULL;
        }
    }

    void deleteN(Node** head){
        if(*head==NULL)return;
        else{
            int k;
            cout<<"Enter a position to delete\n";
            cin>>k;
            Node* temp=*head;
            k=k-2;
            while(k--)temp=temp->next;
            temp->next=temp->next->next;
            temp->next->next->prev=temp;
        }
    }

    void Print(Node* head){
        Node* temp=head;
        cout<<"forward: ";
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void reversePrint(Node* head){
        Node* temp=head;
        if (temp==NULL){
            return;
        }
        cout<<"reverse: ";
        while(temp->next!=NULL){
            temp=temp->next;
        }
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }

    
};

Node* head;


int main(){
    head=NULL;
    int t=5;
    while(t--){
        // head->insertfront(&head);
        head->insertend(&head);
    }
    head->insertN(&head);
    head->Print(head);
    // head->deleteEnd(&head);
    head->deleteN(&head);
    head->Print(head);
}