#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    bool is;
    Node(int d){
        data=d;
        next=NULL;
        is=false;
    }
};
struct Node1{
    int data;
    Node1* next;
    Node1(int d){
        data=d;
        next=NULL;
    }
};
bool cycle(Node* head){
    Node* curr=head;
    while(curr!=NULL && curr->next!=NULL){
        curr->is=true;
        if(curr->next!=NULL && is){
            return true;
        }
        curr=curr->next;
    }
    return false;
}
Node1* cycleA(Node1* head){
    Node1* tmp=new Node1;
    Node1* curr=head;
    while(curr!=NULL){
        if(curr->next==NULL)return false;
        if(curr->next==tmp)return true;
        Node1* curr_next=curr->next;
        curr->next=tmp;
        curr=curr_next
    }
return false;
}