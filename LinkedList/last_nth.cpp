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
Node* nthNode(Node* head,int p){
    Node* curr;
    int c=0;
    for(curr=head;curr!=NULL;curr=curr->next){
        c++;
    }
    curr=head;
    for(int i=0;i<c-p-1;i++){
        curr=curr->next;
    }
    Node* t=curr->next;
    return t;
}
void print(Node* head){
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}
int main(){
    Node* head=new Node(1);
    head->next=new Node(20);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    //head->next->next->next->next->next=new Node(0);
    cout<<nthNode(head,2)->data<<endl;
}