#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* pre;
        Node* next;
        Node(){
            this->data=0;
            this->pre=NULL;
            this->next=NULL;
        }
        Node(int data){
            this->data=data;
            this->pre=NULL;
            this->next=NULL;
        }

};
void insertAtHead(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    else{
        Node* newNode=new Node(data);
        newNode->next=head;
        head->pre=newNode;
        head=newNode; 
    }
}
void insertAtTail(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    else{
        Node* newNode=new Node(data);
        tail->next=newNode;
        newNode->pre=tail;
        tail=newNode;
    }
}
int len(Node* &head){
    int c=0;
    Node* tmp=head;
    while(tmp!=NULL){
        c++;
        tmp=tmp->next;
    }
    return c;
}
void insertAtPos(Node* &head,Node* &tail,int data,int pos){
    int n=len(head);
     if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }else if(pos==1){
        insertAtHead(head,tail,data);
    }else if(pos>n){
        insertAtTail(head,tail,data);
    }else{
        int i=1;
        Node* pre=head;
        while(i<pos-1){
            pre=pre->next;
            i++;
        }
        Node* curr=pre->next;
        Node* newNode=new Node(data);
        newNode->next=curr;
        curr->pre=newNode;
        pre->next=newNode;
        newNode->pre=pre;
    }
}
void deleteNode(Node* &head,Node* &tail,int pos){
    int n=len(head);
    if(pos==1){
        Node* tmp=head;
        head=head->next;
        tmp->next=NULL;
        delete(tmp);
    }else if(pos==n){
        Node* tmp=tail;
        tail=tail->pre;
        tail->next=NULL;
        delete(tmp);
    }else{
        int i=1;
        Node* tmp=head;
        while(i<pos-1){
            tmp=tmp->next;
            i++;
        }
        Node* curr=tmp->next;
        tmp->next=curr->next;
        curr->next->pre=tmp;
        delete(curr);
    }
}
Node*  reverse(Node* &pre,Node* &curr){
    if(curr==NULL){
        return pre;
    }
    Node* forward=curr->next;
    curr->next=pre;
    return reverse(curr,forward);
}
void reverse(Node* &head){
    Node* pre=NULL;
    Node* curr=head;
    while(curr!=NULL){
        Node* tmp=curr->next;
        curr->next=pre;
        pre=curr;
        curr=tmp;
    }
    head=pre;
}
void print(Node* &head){
    Node* tmp=head;
    while(tmp!=NULL){
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertAtHead(head,tail,11);
    insertAtHead(head,tail,14);
    insertAtHead(head,tail,1);
    insertAtHead(head,tail,100);
   // insertAtTail(head,tail,1099);
    //insertAtTail(head,tail,1099);
    //insertAtPos(head,tail,1097,5);
    //deleteNode(head,tail,3);
   /* Node* pre=NULL;
    Node* curr=head;
    head=reverse(pre,curr);*/
    reverse(head);
    print(head);
}