// Inorder Traversal of Tree

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int k){
        data=k;
        left=NULL;
        right=NULL;
    }
};
int height( Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        return max(height(root->left),height(root->right))+1;
    }
    
}
int main(){
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->left->left->left=new Node(51);
    root->left->right=new Node(35);
    root->right->right=new Node(40);
    int ans=height(root);
    cout<<"Height of Tree: "<<ans<<endl;
}