// Diameter of Tree
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
int height(Node* root,int &mini){
    if(root==NULL)return 0;
    int lh=height(root->left,mini);
    int rh=height(root->right,mini);
    mini=max(mini,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfTree(Node* root){
    int mini=0;
    height(root,mini);
    return mini;
}
int main(){
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->left->right=new Node(35);
    root->right->right=new Node(40);
    cout<<diameterOfTree(root)<<endl;   
}