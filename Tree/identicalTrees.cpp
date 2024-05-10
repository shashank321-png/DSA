// Two Trees are Identical
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
bool isSameTree(Node* p,Node* q){
    if(p==NULL ||q==NULL)return (p==q);

    return ((p->data ==q->data) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
}
int main(){
  struct Node * root1 = new Node(1);
  root1 -> left = new Node(2);
  root1 -> right = new Node(3);
  root1 -> right -> left = new Node(4);
  //root1 -> right -> right = new Node(5);

  struct Node * root2 = new Node(1);
  root2 -> left = new Node(2);
  root2 -> right = new Node(3);
  root2 -> right -> left = new Node(4);

  if (isSameTree(root1, root2))
    cout << "Two Trees are identical";
  else cout << "Two trees are non-identical";

  return 0;
}