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
int length(Node* head){
    if(head==NULL)return 0;
    if(head->next==NULL)return 1;
    int p=0;
    Node* curr=head;
    while(curr!=NULL){
        curr=curr->next;
        p++;
    }
    return p;
}
Node* reverseKGrp(Node* head,int k){
    Node* curr=head,*pre=NULL,*n=NULL;
    int c=0;
    while(curr!=NULL && c<k){
        n=curr->next;
        curr->next=pre;
        pre=curr;
        curr=n;
        c++;
    }
    if(n!=NULL && length(n)>=k){
        head->next=reverseKGrp(head,k);
    }else{
        head=head->next;
    }
    return pre;
}
Node* reverseK(Node* head,int k){
    Node* curr=head,*pre=NULL,*n=NULL;
    int c=0;
    while(curr!=NULL && c<k){
        n=curr->next;
        curr->next=pre;
        pre=curr;
        curr=n;
        c++;
    }
    if(n!=NULL){
        Node* res_node=reverseK(n,k);
        head->next=res_node;
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
    Node* head=new Node(12);
    head->next=new Node(14);
    head->next->next=new Node(19);
    head->next->next->next=new Node(20);
    head->next->next->next->next=new Node(60);
    head->next->next->next->next->next=new Node(65);
    print(reverseK(head,2));
}
