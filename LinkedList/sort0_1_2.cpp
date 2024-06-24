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
void sortZeroOneTwo(Node* &head){
    int zero=0,one=0,two=0;
    Node* tmp=head;
    while(tmp!=NULL)
    {
        if(tmp->data==0){
            zero++;
            
        }
        if(tmp->data==1){
            one++;

        }
        if(tmp->data==2){
            two++;

        }
        tmp=tmp->next;
    }
    tmp=head;
    while(zero--)
    {
        tmp->data=0;
        tmp=tmp->next;
    }
    while(one--)
    {
        tmp->data=1;
        tmp=tmp->next;
    }
    while(two--)
    {
        tmp->data=2;
        tmp=tmp->next;
    }
}

// without replacement

Node*  sortWitoutRep(Node* &head){
    Node* zeroHead=new Node(-1);
    Node* zeroTail=zeroHead;
    
    Node* oneHead=new Node(-1);
    Node* oneTail=oneHead;

    Node* twoHead=new Node(-1);
    Node* twoTail=twoHead;
    
    Node* curr=head;
    while(curr!=NULL){
        if(curr->data==0){
            Node* tmp=curr;
            curr=curr->next;
            tmp->next=NULL;
            zeroTail->next=tmp;
            zeroTail=tmp;
        }
        if(curr->data==1){
            Node* tmp=curr;
            curr=curr->next;
            tmp->next=NULL;
            oneTail->next=tmp;
            oneTail=tmp;
        }
        if(curr->data==2){
            Node* tmp=curr;
            curr=curr->next;
            tmp->next=NULL;
            twoTail->next=tmp;
            twoTail=tmp;
        }        
    }
    Node* tmp=oneHead;
    oneHead=oneHead->next;
    tmp->next=NULL;
    delete tmp;
    tmp=twoHead;
    twoHead=twoHead->next;
    tmp->next=NULL;
    delete tmp;
    if(oneHead!=NULL){
        zeroTail->next=oneHead;
        if(twoHead!=NULL){
            oneTail->next=twoHead;
        }
    }else{
        if(twoHead!=NULL){
            zeroTail->next=twoHead;
        }
    }
    tmp=zeroHead;
    zeroHead=zeroHead->next;
    tmp->next=NULL;
    delete tmp;
    return zeroHead;

}
void print(Node* head){
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}
int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(0);
    head->next->next->next=new Node(0);
    head->next->next->next->next=new Node(2);
    head->next->next->next->next->next=new Node(1);
    ////print(head);
    //sortZeroOneTwo(head);
    //cout<<endl;
    head=sortWitoutRep(head);
    print(head);
}
