// Lowest Common Anscestor

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
    }else{
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
Node* lowestCommonAncestor(Node* root,int p,int q){
    if(root==NULL)return;
    if(p<root->data && q<root->data){
        return lowestCommonAncestor(root->left,p,q);
    }
    if(p>root->data && q>root->data){
        return lowestCommonAncestor(root->right,p,q);
    }
    return root;
}
int main(){
    Node* root=NULL;
    takeInput(root);
    Node* curr=lowestCommonAncestor(root,p,q);
    cout<<curr->data<<endl;
    
}