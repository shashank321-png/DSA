// Delete Node from BST
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
int maxVal(Node* root){
    Node* curr=root;
    if(curr==NULL){
        return -1;
    }
    while(curr->right!=NULL){
        curr=curr->right;
    }
    return curr->data;
}

Node* deleteNodeBst(Node* root,int target){
    if(root==NULL){
        return NULL;
    }
    if(root->data==target){
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }
        else
        if(root->left==NULL && root->right!=NULL){
            Node* tmp=root->right;
            return tmp;
        }else if(root->left!=NULL && root->right==NULL){
            Node* tmp=root->left;
            return tmp;
        }else{
            int predes=maxVal(root->left);
            root->data=predes;
            root->left=deleteNodeBst(root->left,predes);
            return root;
        }
    }else if(root->data<target){
        root->right=deleteNodeBst(root->right,target);
    }else{
        root->left=deleteNodeBst(root->left,target);
    }
    return root;
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
int main(){
    Node* root=NULL;
    cout<<"Enter data"<<endl;
    takeInput(root);
    levelOrderTraversal2(root);

    cout<<endl;
    root=deleteNodeBst(root,10);
    levelOrderTraversal2(root);
}
