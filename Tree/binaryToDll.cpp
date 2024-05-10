// Binary to Doubly Linked List

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int k){
        data=k;
        left=right=NULL;
    }
};
Node* binaryToDll(Node* root){
Node* prev=NULL;
    if(root== NULL){
        return root;
    }
    Node* head=binaryToDll(root->left);
    if(prev==NULL){
        head=root;
    }else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    binaryToDll(root->right);
    return head;
}
int main(){
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->left->right=new Node(35);
    root->right->right=new Node(40);
    Node *ans=binaryToDll(root);
    cout<<ans->data<<" ";
}