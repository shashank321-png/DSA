#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
    int data;
    Node* next;
    Node(){
      this->data=0;
      this->next=NULL;
    }
    Node(int data){
      this->data=data;
      this->next=NULL;
    }
};

void insertAtHead(Node* &head,Node* &tail,int data){
  if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
  }else{
    Node* newNode=new Node(data);
    newNode->next=head;
    head=newNode;
  }
}
void insertAtEnd(Node* &head,Node* &tail,int data){
  if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
  }else{
    Node* newNode=new Node(data);
    tail->next=newNode;
    tail=newNode;
  }
}
int len(Node* &head){
  Node* tmp=head;
  int c=0;
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
  }else
  if(pos==1){
    insertAtHead(head,tail,data);
  }else if(pos==n){
    insertAtEnd(head,tail,data);
  }else{
    Node* newNode=new Node(data);
    Node* pre=head;
    int i=1;
    while(i<pos-1){
      pre=pre->next;
      i++;
    }
    Node* curr=pre->next;
    newNode->next=curr;
    pre->next=newNode;
  }
}
void deleteNode(Node* &head,Node* &tail,int pos){
  int n=len(head);
  if(pos==1){
    Node* pre=head;
    head=head->next;
    pre->next=NULL;
    delete(pre);
  }else if(pos==n){
     Node* pre=head;
    int i=1;
    while(i<pos-1){
      pre=pre->next;
      i++;
    }
    pre->next=NULL;
    Node* tmp=tail;
    tail=pre;
    delete(tmp);
  }else{
    Node* pre=head;
    int i=1;
    while(i<pos-1){
      pre=pre->next;
      i++;
    }
    Node* curr=pre->next;
    pre->next=curr->next;
    delete(curr);
  }
}
void print(Node* head){
  Node* tmp=head;
  while(tmp!=0){
    cout<<tmp->data<<" ";
    tmp=tmp->next;
  }
}
int main(){
  Node* head=NULL;
  Node* tail=NULL;
  insertAtHead(head,tail,15);
  insertAtHead(head,tail,12);
  insertAtHead(head,tail,1);
  insertAtHead(head,tail,19);
  insertAtEnd(head,tail,100);
  insertAtPos(head,tail,55,3);
  deleteNode(head,tail,6);
  cout<<head->data<<" "<<tail->data<<endl;
  print(head);
}