// Binary Search Tree to DLL

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
void takeInput(Node*& root){
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

void binaryToDll(Node* root,Node* head){

    if(root==NULL){
        return NULL;
    }
    binaryToDll(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    binaryToDll(root->left,head);
}
void print(Node* head){
    Node* curr=root;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->right;
    }
}
int main(){
    Node* root=NULL;
    cout<<"Enter data"<<endl;
    takeInput(root);
    levelOrderTraversal2(root);
    Node* head=NULL;
binaryToDll(root,head);
print(head);
}
