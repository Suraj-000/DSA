// code by Suraj


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
int min(node* root){
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}
int max(node* root){
    node* temp=root;
    while(temp->right!=NULL)temp=temp->right;
    return temp->data;
}
bool Search(node* root, int data){
    if( root==NULL)return false;
    else if(root->data==data)return true;
    else if ( data<=root->data)return Search(root->left,data);
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
bool IsSubtreeLesser(node* root, int value){
    if(root==NULL)return true;
    if(root->data<=value && IsSubtreeLesser(root->left,value) && IsSubtreeLesser(root->right,value))return true;
    else return false;
}
bool IsSubtreeGreater(node* root, int value){
    if(root==NULL)return true;
    if(root->data>=value && IsSubtreeGreater(root->right,value)&& IsSubtreeGreater(root->left,value))return true;
    else return false;
}
bool IsBinarySearchTree(node* root){
    if ( root ==NULL)return true;
    if(IsSubtreeLesser(root->left,root->data)&& IsSubtreeGreater(root->right,root->data) && IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right))return true;
    else return false;
}
bool IsBstUtil(node* root, int minValue,int maxValue){
    if(root ==NULL)return true;
    if(root->data>minValue && root->data<maxValue && IsBstUtil(root->left,minValue,root->data) && IsBstUtil(root->right,root->data,maxValue))return true;
    else return false;
}
bool IsBSTRange(node* root){
    return IsBstUtil(root,INT_MIN,INT_MAX);
}
node* FindMin(node* root){
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
node* FindMax(node* root){
    node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
node* Delete(node* root, int data){
    if(root==NULL)return root;
    else if(data<root->data)root->left=Delete(root->left,data);
    else if (data>root->data)root->right=Delete(root->right,data);
    else {
        //case 1: no child
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }
        //case 2: one child
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
        // case 3: 2 child
        else {
            node* temp=FindMin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }

    return root;
}
node* Find(node* root,int data){
    if(root==NULL)return NULL;
    else if(root->data==data)return root;
    else if (data<root->data) return Find(root->left,data);
    else return Find (root->right,data);
}
node* Getsuccessor(node* root, int data){
    node* current=Find(root,data);
    if(current==NULL)return NULL;
    //case 1:-node has right subtree
    if(current->right!=NULL){
        return FindMin(current->right);
    }
    //Case 2:- no right subtree
    else {
        node* successor=NULL;
        node* ancestor=root;
        while(ancestor!=current){
            if(current->data<ancestor->data){
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else ancestor=ancestor->right;
        }
        return successor;
    }   
}
node* Getpredecessor(node* root, int data){
    node* current=Find(root,data);
    if(current==NULL)return NULL;
    if(current->left!=NULL){
        return FindMax(current->left);
    }
    else{
        node* predecessor=NULL;
        node* ancestor=root;
        while(ancestor!=current){
            if(current->data<ancestor->data){
                ancestor=ancestor->left;
            }
            else {
                predecessor=ancestor;
                ancestor =ancestor->right;
            }
        }
        return predecessor;
    }
}

void topView(node* root){
    if ( root ==NULL)return;
    queue<node*> q;
    map<int,int> m;
    int level=0;
    root->level=level;
    q.push(root);
    while(q.size()){
        level=root->level;
        if(m.count(level)==0){
            m[level]=root->data;
        }
        if(root->left){
            root->left->level=level-1;
            q.push(root->left);
        }
        if(root->right){
            root->right->level=level+1;
            q.push(root->right);
        }
        q.pop();
        root=q.front();
    }
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->second << " ";
}
}


node *LowestCommonAncestor(node *root, int v1,int v2) {
    if(root->data < v1 && root->data < v2){
        return LowestCommonAncestor(root->right,v1,v2);
    }
    if(root->data > v1 && root->data > v2){
        return LowestCommonAncestor(root->left,v1,v2);
    }
    return root;
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
    Inorder(root);
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