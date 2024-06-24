// Bst from Preorder


#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insertIntoBst(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(root->data>data){
        root->left=insertIntoBst(root->left,data);
    }else{
        root->right=insertIntoBst(root->right,data);
    }
    return root;
}
void takeInput(Node* root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBst(root,data);
        cin>>data;
    }
}
void levelOrderTraversal2(Node* root){
    if(root==NULL){
        return ;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        Node* curr=q.front();
        q.pop();
        if(curr==NULL){
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<(curr->data)<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}
Node* bstUsingPreorder(vector<int> v){
    int i=0;
    return build(v,t,INT_MAX);
}
Node* build(vector<int> v,int& i,int bound){
    if(i==v.size() || v[i]>bound){
        return NULL;
    }
    Node* root=new Node(v[i]);
    root->left=build(v,i,root->val);
    root->right=build(v,i,bound);
    return root;
}
int main(){
    vector<int> v={1,2,3,4,5,6,7,8,9};
   
    Node* root=bstUsingPreorder(v);
    levelOrderTraversal2(root);
}