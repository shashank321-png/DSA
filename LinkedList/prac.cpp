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
/*Node* insert(Node* head,int d){
    Node* tmp=new Node(d);
    if(head==NULL){
        tmp->next=tmp;
    }else{
    Node* curr=head;
    while(curr->next!=head){
        curr=curr->next;
    }
    curr->next=tmp;
    tmp->next=head;
  
    }
    return tmp;
}
Node* insertA(Node* head,int d){
    Node* tmp=new Node(d);
    if(head==NULL){
        tmp->next=tmp;
        return tmp;
    }else{
        tmp->next=head->next;
        head->next=tmp;
        int t=head->data;
        head->data=tmp->data;
        tmp->data=t;
        return head;
    }
}
Node* insertend(Node* head,int d){
    Node* tmp=new Node(d);
    Node* curr=head;
    while(curr->next!=head){
        curr=curr->next;
    }
    curr->next=tmp;
    tmp->next=head;
    return head;
}
Node* del(Node* head,int x){
    Node* curr=head;
    if(x==1){
       head->data=head->next->data;
       head->next=head->next->next;
       delete head->next;
        return head;
    }else{
        for(int i=0;i<x-2;i++){
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;

    }
}*/
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
   
    cout<<head->data<<" ";
    for(Node* p=head->next;p!=head;p=p->next){
        cout<<p->data<<" ";
    }
    cout<<endl;
}
void printf(Node* head){
    Node* p=head;
    if(head==NULL)return;
    do{
        cout<<p->data;
        p=p->next;
    }while(p!=head);
}
int main(){
    Node* head=new Node(10);
   head->next=new Node(15);
   head->next->next=new Node(78);
   //head->next->next->next=head;
    cout<<head->next->next->next->data<<endl;
    //print(insertK(head, 12));
    }