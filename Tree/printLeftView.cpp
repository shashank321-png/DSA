// Print Left view of binary tree
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
    Node(int k){
        data=k;
        left=right=NULL;
    }
};

void printLeftView(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node* >q;
    q.push(root);
    while(q.empty()==false){
        int count=q.size();
        for(int i=0;i<count;i++){
            Node* curr=q.front();
            q.pop();
            if(i==0){
            cout<<(curr->data)<< " ";}
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        
    }
}
int main(){
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->left->right=new Node(35);
    root->right->right=new Node(40);
    printLeftView(root);
}