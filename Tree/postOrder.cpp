// PostOrder Traversal of Tree


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

// Recursive Approach
void postOrder(struct Node* root){
    if(root==NULL){
        return ;
    }
        postOrder(root->left);
        postOrder(root->right);
        cout<<(root->data)<<" ";
    
}

//Irerative Approach

void postOrderIte(Node* root){
    if(root==NULL){
        return;
    }
    stack<Node* >s1,s2;
    s.push(root);
    Node* curr;
    while(!s1.empty()){
        curr=s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left){
            s1.push(curr->left);
        }
        if(curr->right){
            s1.push(curr->right);
        }
    }
    while(!s2.empty()){
        curr=s2.top();
        s2.pop();
        cout<<(curr->data)<<" ";
    }
}
int main(){
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->left->right=new Node(35);
    root->right->right=new Node(40);
    postOrder(root);
}