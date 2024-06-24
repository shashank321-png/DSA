// Check Binary search Tree is valid or not
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
bool solve(Node* root,long long int lb,long long int ub){
    if(root==NULL)return true;
    if(root->data>lb && root->data<ub){
        bool leftAns=solve(root->left,lb,root->data);
        bool rightAns=solve(root->left,root->data,ub);
        return leftAns && rightAns;
    }else{
        return false;
    }
}
bool valiBst(Node* root){
    long long int lb=-4294967296;
    long long int ub=4294967296;
    bool ans=solve(root,lb,ub);
    return ans;
}
int main(){
    Node* root=NULL;
    takeInput(root);
    bool ans=validBst(root);
    
}