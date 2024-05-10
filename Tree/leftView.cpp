// Left View of Tree
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
// recursive approach
void recursive(Node* root,int level, vector<int>& v){
   if(root==NULL)return;
   if(level==v.size()){
       v.push_back(root->data);
   }
   recursive(root->left,level+1,v);
   recursive(root->right,level+1,v);
}

// iterative approach
void iterartive(Node* root,vector<int>& ans;){
    if(!root)return;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* curr=q.front();
            q.pop();
            if(i==1){
                ans.push_back(curr->data);
            }
            if(curr->left!=NULL)curr=curr->left;
            if(curr->right!=NULL)curr=curr->right
        }
    }
}
vector<int> leftView(Node *root)
{
  vector<int> v;
  recursive(root,0,v);
  return v;
}
int main(){
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->left->right=new Node(35);
    root->right->right=new Node(40);
    vector<int> v=leftView(root);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}