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
Node* insertK(Node* head,int t){
    Node* tmp= new Node(t);
    if(head==NULL){
        return tmp;
    }
    if(t<head->data){
        tmp->next=head;
        return head;
    }
    Node* curr=head;
    while(curr->next->data <t && curr->next!=NULL){
        curr=curr->next;
    }
    tmp->next=curr->next;
    curr->next=tmp;
    return head;
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
    print(insertK(head,22));
}