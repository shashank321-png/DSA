// Maximum with of Binary Tree
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
int maxWidth(Node* root){
    if(root==NULL){
        return 0;
    }
    queue<Node* > q;
    q.push(root);
    int res=0;
    while(q.empty()==false){
        int count=q.size();
        res=max(res,count);
        for(int i=0;i<count;i++){
            Node* curr=q.front();
            q.pop();
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
    return res;
}
int main(){
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->left->right=new Node(35);
    root->right->right=new Node(40);
    cout<<maxWidth(root)<<endl;
}