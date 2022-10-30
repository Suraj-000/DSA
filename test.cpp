#include<iostream>
#include<queue>
#include<map>


using namespace std;

struct node{
    int data;
    node* right;
    node* left;
    int level;
};

node* getnewnode(int data){
    node* newn=new node();
    newn->data=data;
    newn->left=newn->right=NULL;
    return newn;
}
node* Insert(node* root,int data){
    if(root==NULL){
        root=getnewnode(data);
    }
    else if(data<=root->data){
        root->left=Insert(root->left,data);
    }
    else root->right=Insert(root->right,data);
    return root;
}

int findheight(node* root){
    if(root==NULL)return -1;
    cout<<root->data<<endl;
    return max(findheight(root->left),findheight(root->right))+1;
}

int min(node* root){
    node* temp=root;
    while(temp->left!=NULL)temp=temp->left;
    return temp-data;
}
int max(node* root){
    node* temp=root;
    while(temp->right!=NULL)temp=temp->right;
    return temp->data;
}

bool Search(node* root,int data){
    if(root==NULL)return false;
    else if(root->data==data)return true;
    else if(data<=root->data)return Search(root->left,data);
    else return Search(root->right,data);
}

void LevelOrder(node* root){
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

node* Delete(node* root,int data){
if(root==NULL)return root;
    else if(data<root->data)root->left=Delete(root->left,data);
    else if (data>root->data)root->right=Delete(root->right,data);
    else{

        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }
        else if(root->left==NULL){
            node* temp=root;
            root=root->right;
            delete temp;
        }
          else if (root->right==NULL){
            node* temp=root;
            root=root->left;
            delete temp;
        }
        else {
            node* temp=FindMin(root->right);
            root->data=temp->data;
            root->right=Delete()
        }
    }
}

int main(){
    node* root=NULL ;
    int k=116;
    root=Insert(root,10);  
    root=Insert(root,5);
    root=Insert(root,11);
    root=Insert(root,8);
    // root=Insert(root,3);
    // root=Insert(root,9);
    // root=Insert(root,0);
    // root=Insert(root,66);
    // root=Insert(root,1);
    // root=Insert(root,2);
    // root=Insert(root,-10);
    // root=Insert(root,-4);
    // root=Insert(root,-5);
    // root=Insert(root,-6);
    k=findheight(root);
    // int p;cin>>p;
    // if(Search(root,p)==true){cout<<"found"<<endl;}
    // else {cout<<"not found"<<endl;}
    // cout<<min(root)<<endl;
    // cout<<max(root)<<endl;
    // int w=findheight(root);
    // cout<<w<<endl;
    // LevelOrder(root);
    // cout<<endl;
    // Preorder(root);
    // cout<<endl;
    // Inorder(root);
    // cout<<endl;
    // Postorder(root);
    // cout<<endl;
    // cout<<IsSubtreeLesser(root,66)<<endl;
    // cout<<IsSubtreeGreater(root,-11)<<endl;
    // cout<<IsBinarySearchTree(root);
    // cout<<IsBSTRange(root)<<endl;
    // cout<<INT_MAX<<endl;
    // cout<<endl;
    // root=Delete(root,10);
    // LevelOrder(root);
    // node* temp=Getpredecessor(root,10 );
    // cout<<temp->data;
    // node* temp=Getsuccessor(root,10 );
    // cout<<temp->data;
    // topView(root); 
    // node* temp=LowestCommonAncestor(root,-6,66);
    // cout<<temp->data;
    cout<<endl;
    return 0;
}  