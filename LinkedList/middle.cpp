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
void  middle(Node* head){
    Node* curr;
    int c=0;
   for(curr=head;curr!=NULL;curr=curr->next){
    c++;
   }
   curr=head;
    for(int i=0;i<c/2;i++){
       curr=curr->next;
    }
    cout<<curr->data<<endl;
}
void middleA(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;
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
    middleA(head);
}