//Search element present or not
//Search element present or not
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

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBst(root,data);
        cin>>data;
    }  
}

bool checkPresent(Node* root,int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return  true;

    }
    if(target>root->data){
        return checkPresent(root->right,target);
    }else{
        return checkPresent(root->left,target);
    }
}
int main(){
    Node* root=NULL;
    cout<<"Enter Data"<<endl;
    takeInput(root);
    
    bool is=checkPresent(root,15);
    cout<<"Present or not: "<<is<<endl;
}