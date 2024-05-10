#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left,*right;
    Node(int k){
        val=k;
        left=NULL;
        right=NULL;
    }
};
  vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        queue<Node* >q;
        q.push(root);
        int level=1;
        while(q.empty()==false){
            int n=q.size();
            vector<int> v(n);
           
                for(int i=0;i<n;i++){
                    Node* curr=q.front();
                    q.pop();
                 
                   if(level%2==0){
                     v[n-i-1]=curr->val;
                   }else{
                    v[i]=curr->val;
                   }
                  
                    if(curr->left!=NULL){
                        q.push(curr->left);
                    }
                    if(curr->right!=NULL){
                        q.push(curr->right);
                    }
                }
       
            level++;
            ans.push_back(v);
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
    vector<vector<int>> ans=zigzagLevelOrder(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    }