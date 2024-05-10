// Top view of binary Tree
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
 vector<int> topView(Node* root){
    vector<int> ans;
    if(root==NULL)return ans;
    map<int,int> m;
    queue<pair<Node* ,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        Node* curr=it.first;
        int line=it.second;
       if(m.find(line)==m.end()) m[line]=curr->data;
        if(curr->left!=NULL){
            q.push({curr->left,line-1});

        }
        if(curr->right!=NULL){
            q.push({curr->right,line+1});
        }

    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
 }
 int main(){
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->left->right=new Node(35);
    root->right->right=new Node(40);
    vector<int> ans=topView(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
 }