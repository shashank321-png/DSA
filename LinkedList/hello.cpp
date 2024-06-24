#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* pre;
    Node(int d){
        data=d;
        next=NULL;
        pre=NULL;
    }
};
Node* insert(Node* head,int d){
    Node* tmp=new Node(d);
    if(head->next==NULL){
        return tmp;
    }
    tmp->next=head;
   
    return tmp;
}
Node* insertE(Node* head,int d)
{
    Node* tmp=new Node(d);
    if(head==NULL){
        return tmp;
    }
    Node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=tmp;
    tmp->pre=curr;
    return head;
}
Node* reverse(Node* head){
    if(head==NULL || head->next==NULL)return head;
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL){
        prev=curr->pre;
        curr->pre=curr->next;
        curr->next=prev;
        curr=curr->pre;
    }
    return prev->pre;
}
Node* del(Node* head){
    if(head==NULL)return NULL;
    else
    if(head->next==NULL)return head;
    else{
    Node* curr=head;
    head=head->next;
    head->pre=NULL;
   
    delete(curr);
    return head;
    }
}
Node* dell(Node* head){
    if(head==NULL)return NULL;
    else
    if(head->next==NULL) return head;
    else
    {
        Node* tmp=head;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->pre->next=NULL;
        delete(tmp);
        return head;
    }
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
    Node* t1=new Node(15);
    Node* t2=new Node(45);
    head->next=t1;
    t1->pre=head;
    t1->next=t2;
    t2->pre=t1;
    print(head);
    cout<<endl;
    //reverse(head);
    //print(reverse(head));
    print(dell(head));

}