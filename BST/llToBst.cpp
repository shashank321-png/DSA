// Create Linked List To Dll
Node* solve(Node*& head,int n){
    if(n<=0 || root==NULL){
        return NULL;
    }
    Node* leftTree=solve(head,n/2);
    Node* root=head;
    root->left=leftTree;
    head=head->right;
    root->right=solve(head,n/2-1);
    return root;
}