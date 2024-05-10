// Inorder Traversal of Tree

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int k){
        data=k;
        left=NULL;
        right=NULL;
    }
};
// Recursive Approach
void inOrder(struct Node* root){
    if(root==NULL){
        return ;
    }
        inOrder(root->left);
        cout<<(root->data)<<" ";
        inOrder(root->right);
    
}
// Iterative Approach
vector<int> inorderTraversal(Node* root){
    vector<int> inorder;
    stack<Node* > s;
    while(true){
        if(root!=NULL){
            s.push(root);
            root=root->left;
        }else{
            if(s.empty()) break;
            root=s.top();
            inorder.push_back(root->data);
            s.pop();
            root=root->right;
        }
    }
    return inorder;
}
int main(){
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->left->right=new Node(35);
    root->right->right=new Node(40);
    //inOrder(root);
      vector < int > inorder;
     inorder = inorderTraversal(root);
 
    cout << "The inOrder Traversal is : ";
    for (int i = 0; i < inorder.size(); i++) {
    cout << inorder[i] << " ";
    }
}