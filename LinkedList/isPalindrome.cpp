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

Node* reverse(Node* &head){
    Node* pre=NULL;
    Node* curr=head;
    Node* forward=curr->next;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=pre;
        pre=curr;
        curr=forward;
    }
    return pre;
}
bool isPalindrome(Node* &head){
    if(head==NULL){
        return false;
    }
    if(head->next==NULL){
        return true;
    }
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    Node* reverseNode=reverse(slow->next);
    slow->next=reverseNode;
    Node* tmp1=head;
    Node* tmp2=reverseNode;
    while(tmp2!=NULL){
        if(tmp1->data!=tmp2->data){
            return false;
            break;
        }
        tmp1=tmp1->next;
        tmp2=tmp2->next;
    }
    return true;
}
int main(){
Node* head=new Node(10);
Node* t1=new Node(20);
Node* t2=new Node(30);
Node* t3=new Node(40);
Node* t4=new Node(20);
Node* t5=new Node(10);


head->next=t1;
t1->next=t2;
t2->next=t3;
t3->next=t4;
t4->next=t5;
bool is=isPalindrome(head);
if(is){
    cout<<"LL is Palindrome"<<endl;
}else{
    cout<<"LL is not a palindrome"<<endl;
}

}