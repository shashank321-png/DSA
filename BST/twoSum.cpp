// Two Sum of Bst

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
void solve(Node* root,vector<int>& v){
    if(root==NULL)return;
    solve(root->left,v);
    v.push_back(root->data);
    solve(root->right,v);
}
bool twoSum(Node* root,int k){
    vector<int> v;
    solve(root,v);
    int s=0,e=v.size()-1;
    while(s<e){
        int sum=v[s]+v[e];
        if(sum==k){
            return true;
        }
        if(sum>k)
            e--;
        else
            s++;
    }
    return false;
}
int main(){
    Node* root=NULL;
    cout<<"Enter data"<<endl;
    takeInput(root);
    bool ans=twoSum(root,k);
    cout<<ans<<endl;

    cout<<endl;
    root=deleteNodeBst(root,10);
    levelOrderTraversal2(root);
}
