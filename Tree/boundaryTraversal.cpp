// Boundary Traversal of Tree
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
 bool isLeaf(Node* root){
    return ((!root->left) && (!root->right));
 }

 void addLeftNode(Node* root,vector<int>& ans){
    Node* curr=root->left;
    while(curr){
        if(!isLeaf(curr)){
            ans.push_back(curr->data);
        }
        if(curr->left){curr=curr->left;}
        else{
            curr=curr->right;
        }
    }
 }
 void addRightNode(Node* root,vector<int>& ans){
    Node* curr=root->right;
    vector<int > tmp;
    while(curr){
        if(!isLeaf(curr)){
            tmp.push_back(curr->data);
        }
        if(curr->right){
            curr=curr->right;
        }else{
            curr=curr->left;
        }
    }
    for(int i=tmp.size()-1;i>=0;i--){
        ans.push_back(tmp[i]);
    }
 }
 //use preorder traversal
 void addLeaf(Node* root,vector<int>& ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left) addLeaf(root->left,ans);
    if(root->right) addLeaf(root->right,ans);

 }
vector<int> boundaryTraverse(Node* root){
    vector<int> ans;
    if(!root)return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    addLeftNode(root,ans);
    addLeaf(root,ans);
    addRightNode(root,ans);
    return ans;
}
int main(){
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->left->right=new Node(35);
    root->right->right=new Node(40);
    vector<int> ans=boundaryTraverse(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}