// Contruct BinarySearch Tree using Inorder

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
Node* bstUsingInorder(int a[],int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=s+(e-s)/2;
    int element=a[mid];
    Node* root= new Node(element);
    root->left=bstUsingInorder(a,s,mid-1);
    root->right=bstUsingInorder(a,mid+1,e);
    return root;
}
int main(){
    int a[9]={1,2,3,4,5,6,7,8,9};
    int s=0,e=8;
    Node* root=bstUsingInorder(a,s,e);
    levelOrderTraversal2(root);
}