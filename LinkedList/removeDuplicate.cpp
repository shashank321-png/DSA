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
Node*  removeDup(Node* head){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return NULL;
    }
    if(head->next==NULL){
        cout<<"Single Node"<<endl;
        return;
    }
    Node* curr=head;
    while(curr!=NULL && curr->next!=NULL){
        if(curr->data==curr->next->data){
            Node* tmp=curr->next;
            curr->next=curr->next->next;
            delete tmp;
        }else{
            curr=curr->next;
        }
    }
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
    head->next->next=new Node(20);
    head->next->next->next=new Node(30);
    head->next->next->next->next=new Node(30);
    head->next->next->next->next->next=new Node(30);
    print(removeDup(head));
}