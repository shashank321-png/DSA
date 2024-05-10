// Print Nodes at distance k
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
void printKDist(Node* root,int k){
    if(root==0){
        return ;
    }
    if(k==0){
        cout<<(root->data)<<" ";
    }else{
        printKDist(root->left,k-1);
        printKDist(root->right,k-1);
    }
}
int main(){
     struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->left->right=new Node(35);
    root->right->right=new Node(40);
    printKDist(root,2);
}