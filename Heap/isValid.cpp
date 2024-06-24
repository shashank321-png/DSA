// Given complete binary tree is valid or not
#include<bits/stdc++.h>
using namespace std;

pair<bool,int> solve(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,INT_MIN);
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p=make_pair(true,root->data);
        return p;
    }
    pair<bool,int> leftAns=solve(root->left);
    pair<bool,int> rightAns=solve(root->right);
    if(leftAns.first==true && rightAns.first==true && leftAns.second<root->data && rightAns.second<root->data){
        return make_pair(true,root->data);
    }else{
        return make_pair(false,-1);
    }

}