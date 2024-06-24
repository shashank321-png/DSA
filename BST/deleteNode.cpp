// Delete Node from BST
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
     Node *left,*right;
     Node(int data){
         this->data=data;
         this->left=NULL;
         this->right=NULL;
     }
};
Node* insertIntoBst(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(root->data>data){
        root->left=insertIntoBst(root->left,data);
    }else
    {
        root->right=insertIntoBst(root->right,data);
    }
    return root;
    
}
void takeInput(Node* root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBst(root,data);
        cin>>data;
    }
}
int maxVal(Node* root){
    Node* curr=root;
    if(root==NULL){
        return -1;
    }
    while(root!=NULL){
        curr=curr->right;
    }
    return curr->data;
}
void inorder(Node* root,vector<int> &v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
Node* deleteNodeBst(Node* root,int target){
    if(root==NULL){
        return NULL;
    }
    if(root->data==target){
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }
        else
        if(root->left==NULL && root->right!=NULL){
            Node* tmp=root->right;
            return tmp;
        }else if(root->left!=NULL && root->right==NULL){
            Node* tmp=root->left;
            return tmp;
        }else{
            int predes=maxVal(root);
            root->data=predes;
            root->left=deleteNodeBst(root->left,predes);
            return root;
        }
    }else if(root->data>target){
        root->left=deleteNodeBst(root->left,target);
    }else{
        root->right=deleteNodeBst(root->right,target);
    }
    return root;
}
int main(){
    Node* root=NULL;
    takeInput(root);
    vector<int> v;
    inorder(root,v);
    for(int i=0;i<v.size();i++){
        cout<<
    }
    cout<<endl;
    root=deleteNodeBst(root,10);
}