#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    void InsertStart(Node** head){
        int x;
        cout<<"enter a value to add at start"<<endl;
        cin>>x;
        Node* temp=new Node();
        temp->data=x;
        if (head!=NULL)temp->next=*head;
        *head=temp;
    }

    void InsertEnd(Node** head){
        int x;
        cout<<"enter a value to add at end"<<endl;
        cin>>x;
        Node* temp=new Node();
        Node* temp1;
        temp->data=x;
        if (*head==NULL)*head=temp;
        else{
            temp1=*head;
            while(temp1->next!=NULL){
                temp1=temp1->next;
            }
            temp1->next=temp;
            temp->next=NULL;
        }
    }

    void InsertN(Node** head){
        int x,y;
        cout<<"enter no and position "<<endl;
        cin>>x>>y;
        Node* temp=new Node();
        Node* temp1;
        temp->data=x;
        if (*head==NULL)*head=temp;
        else{
            temp1=*head;
            while(y--){
                temp1=temp1->next;
            }
            temp->next=temp1->next;
            temp1->next=temp;
        }
    }

    void Print(Node * head){
    Node* temp=head;
    cout<<"List: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
        }
    cout<<endl;
    }

    int front(Node* head){
        return head->data;
    }

    int back(Node* head){
        Node* temp;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        return temp->data;
    }

    void DeleteEnd(Node** head){
        Node* temp;
        temp=*head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        
        temp->next=NULL;
    }
    void DeleteFront(Node **head){
        Node* temp=*head;
        *head=temp->next;
    }

    void DeleteN(Node** head ){
        int x;
        cout<<"enter a position to delete"<<endl;
        cin>>x;
        Node* temp;
        temp=*head;
        while(x--){
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }

    void size(Node* head){
        int t=0;
        Node* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            t++;
        }
        cout<<t<<endl;
    }
    
    void reverse(Node** head){
        Node *current,*prev,*next;
        current=*head;
        prev=NULL;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        *head=prev; 
    }
    
    void reversePrint(Node* head){
        if(head==NULL){
            return;
        }
        reversePrint(head->next);
        cout<<head->data<<endl;
    }
};
Node* head;

void recursionreverse(Node* p){
        if (p->next==NULL){
            head=p;
            return;
        }
        recursionreverse(p->next);
        Node* q=p->next;
        q->next=p;
        p->next=NULL;
    }

int main(){
    head=NULL;
    int t=10;
    while(t--){head->InsertEnd(&head);}
    head->Print(head);
    // head->InsertN(&head);
    // head->DeleteEnd(&head);
    // head->DeleteFront(&head);
    // head->DeleteN(&head);
    // head->size(head);
    // head->reverse(&head);
    recursionreverse(head);
    head->Print(head);
    return 0;
}