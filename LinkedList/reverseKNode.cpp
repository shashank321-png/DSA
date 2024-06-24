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

int getLength(Node* &head){
    Node* tmp=head;
    int c=0;
    while(tmp!=NULL){
        tmp=tmp->next;
        c++;
    }
    return c;
}
Node* reverseKNode(Node* &head,int k){
    if(head==NULL){
        cout<<"EMpty LL"<<endl;
        return head;
    }
    int len=getLength(head);
   // cout<<len<<" "<<k<<endl;
    if(k>len){
        cout<<len<<" "<<"Invalid value of K"<<endl;
        return head;
    }
    Node* pre=NULL;
    Node* curr=head;
    Node* forward=curr->next;
    int count=0;
    while(count<k){
        forward=curr->next;
        curr->next=pre;
        pre=curr;
        curr=forward;
        count++;
    }
    if(forward!=NULL){
        head->next=reverseKNode(forward,k);
    }
    return pre;
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
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth=new Node(50);
    Node* sixth=new Node(60);
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    print(head);
    int k=3;
   
    reverseKNode(head,k);
    print(head);

}