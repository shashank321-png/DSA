// Check Binary Tree is balanced or not
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int k){
        data=k;
        left=NULL;
        right=NULL;
    }
};
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        return max(height(root->left) ,height(root->right));
    }
}
bool isBalanced(Node* root){
    if(root==NULL){
        return true;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return (abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
}

//Efficient Solution 
int balanced(Node* root){
    if(root==NULL){
        return 0;
    }
    int lh=balanced(root->left);
    if(lh==-1){
        return -1;
    }
    int rh=balanced(root->right);
    if(rh==-1){
        return -1;
    }
    if(abs(lh-rh)>1){
        return -1;
    }else{
        return (max(lh,rh)+1);
    }
}
int main(){
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->left->right=new Node(35);
    root->right->right=new Node(40);
    bool ans=isBalanced(root);
    
    cout<<ans<<endl;
    cout<<balanced(root)<<endl;
}