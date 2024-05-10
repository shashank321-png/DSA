// Preorder Traversal of tree
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

//Recursive Approach
void preOrder(struct Node* root){
    if(root==NULL){
        return ;
    }
        cout<<(root->data)<<" ";
        preOrder(root->left);
        preOrder(root->right);
    
}

//Iterative Approach

void preOrderIte(Node* root){
    if(root==NULL){
        return ;
    }
    stack<Node* > s;
    s.push(root);
    while(s.empty()==false){
        Node* curr=s.top();
        cout<<(curr->data)<<" ";
        s.pop();
        if(curr->right){
            s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
        }
    }
}
int main(){
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->right->right=new Node(40);
    //preOrder(root);
    preOrderIte(root);
}