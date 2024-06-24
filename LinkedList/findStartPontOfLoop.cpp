
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

Node* findPoint(Node* head){
   if(head==NULL){
    cout<<"LL is empty"<<endl;
    return NULL;
   }
   Node* fast=head;
   Node* slow=head;
   while(fast!=NULL){
    fast=fast->next;
    if(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    if(slow==fast){
       slow=head;
       break;
   }
   }
   while (fast!=slow)
   {
        fast=fast->next;
        slow=slow->next;
   }
   return slow;
   
}
Node* removeLoop(Node* head){
   if(head==NULL){
    cout<<"LL is empty"<<endl;
    return NULL;
   }
   Node* fast=head;
   Node* slow=head;
   while(fast!=NULL){
    fast=fast->next;
    if(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    if(slow==fast){
       slow=head;
       break;
   }
   }
   Node* prev=fast;
   while (fast!=slow)
   {
        prev=fast;
        fast=fast->next;
        slow=slow->next;
   }
   prev->next=NULL; 
   return slow;
   
}
void print(Node* &head){
    Node* tmp=head;
    while(tmp!=NULL){
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
}
int main(){
Node* head=new Node(10);
Node* t1=new Node(20);
Node* t2=new Node(30);
Node* t3=new Node(40);
Node* t4=new Node(50);
Node* t5=new Node(70);
Node* t6=new Node(80);
Node* t7=new Node(60);
Node* t8=new Node(90);

head->next=t1;
t1->next=t2;
t2->next=t3;
t3->next=t4;
t4->next=t5;
t5->next=t6;
t6->next=t7;
t7->next=t8;

t8->next=t4;

//t3->next=t1;
removeLoop(head);
print(head);
}