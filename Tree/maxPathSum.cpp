// Maximum Path sum of Tree
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

int solve(Node* root,int &res){
    if(root==NULL)return 0;
    int l=solve(root->left,res);
    int r=solve(root->right,res);
    int temp=max(max(l,r)+root->data,root->data);
    int ans=max(temp,l+r+root->data);
    res=max(res,ans);
    return temp;
}
int maxPathSum(Node* root){
    int res=INT_MIN;
    solve(root,res);
    return res;
}
int main(){
  struct Node * root =new Node(2);
  root -> left =new Node(1);
  root -> right =new   Node(3);
  root -> left -> left = new Node(3);
  root -> left -> right =new  Node(7);
  root -> left -> right->left =new  Node(9);
    cout<<maxPathSum(root)<<endl; 
}
