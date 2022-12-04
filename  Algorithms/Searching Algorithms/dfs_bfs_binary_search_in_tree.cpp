#include<iostream>
#include<queue>
#include<map>

using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    int level;
};
int findheight(node* root){
    if(root==NULL){
        return -1;
    }
    return max(findheight(root->left),findheight(root->right))+1;
}
node* getnewnode(int data){
    node* newn=new node();
    newn->data=data;
    newn->left=newn->right=NULL;
    return newn;
}
node* Insert(node* root,int data){
    if(root==NULL){
        root =getnewnode(data); 
    }
    else if(data<=root->data){
        root->left=Insert(root->left,data);
    }
    else if (data>=root->data){
        root->right=Insert(root->right,data);
    }
    return root;
}

bool Search(node* root, int data){
    if( root==NULL)return false;
    else if(root->data==data)return true;
    else if ( data<=root->data)return Search(root->left,data);
    else return Search(root->right,data);
}

void BFS(node* root){
    if(root==NULL)return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* current=q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL)q.push(current->left);
        if(current->right!=NULL)q.push(current->right);
        q.pop();
    }
}
// DFS 
void Preorder(node* root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(node* root){
    if(root==NULL)return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void Postorder(node* root){
    if(root==NULL)return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node* root=NULL ;
    int k=116;
    root=Insert(root,10);  
    root=Insert(root,5);
    root=Insert(root,11);
    root=Insert(root,8);
    root=Insert(root,3);
    root=Insert(root,9);
    root=Insert(root,0);
    root=Insert(root,66);
    root=Insert(root,1);
    root=Insert(root,2);
    root=Insert(root,-10);
    root=Insert(root,-4);
    root=Insert(root,-5);
    root=Insert(root,-6);

    BFS(root);
    cout<<endl;
    DFS(root);
    cout<<endl;
    cout<<Search(root,3);
    cout<<endl;
    return 0;
}  