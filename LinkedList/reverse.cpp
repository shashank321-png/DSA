#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
Node* reverseA(Node* head){
    vector<int> a;
    for(Node* curr=head;curr!=NULL;curr=curr->next){
        a.push_back(curr->data);
    }
    for(Node* curr=head;curr!=NULL;curr=curr->next){
        curr->data=a.back();
        a.pop_back();
    }
    return head;
}
Node* recur(Node* &pre,Node* &curr){
    if(curr==NULL){
        return pre;
    }
    Node* forward=curr->next;
    curr->next=pre;
    recur(curr,forward);
    
}
Node* reverse(Node* head){
    Node* curr=head;
    Node* pre=NULL;
    while(curr!=NULL){
        Node* n=curr->next;
        curr->next=pre;
        pre=curr;
        curr=n;
    }
    return pre;
}
void print(Node* head){
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }

}
int main(){
    Node* head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(35);
    Node* pre=NULL;
    Node* curr=head;
    print(recur(pre,curr));
}

