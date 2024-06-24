// Floyd cycle detection
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

bool detec(Node* head){
   if(head==NULL){
    cout<<"LL is empty"<<endl;
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
        return true;
    }
   }
   return false;
}
int main(){
Node* head=new Node(10);
Node* t1=new Node(20);
Node* t2=new Node(30);
Node* t3=new Node(40);
Node* t4=new Node(40);
Node* t5=new Node(40);

head->next=t1;
t1->next=t2;
t2->next=t3;
t3->next=t4;
t4->next=t5;
t5->next=t3;

//t3->next=t1;
cout<<"Loop is present or not: "<<detec(head)<<endl;
}