// Maximum in Binary Tree
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
int maximum(Node* root){
    if(root==NULL){
        return INT_MIN;
    }else{
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
}
int main(){
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(22);
    root->left->left=new Node(81);
    root->left->right=new Node(35);
    root->right->right=new Node(40);
    cout<<maximum(root)<<endl;
}