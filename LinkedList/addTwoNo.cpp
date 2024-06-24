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
Node* addTwoNo(Node* &head1,Node* &head2){
    // reverse both LL
    head1=reverse(head1);
    head2=reverse(head2);

    //add both linked list;
    int carry=0;
    Node* addHead=NULL;
    Node* addTail=NULL;
    while(head1!=NULL && head2!=NULL){
        int sum=carry+head1->data+head2->data;
        int digit=sum%10;
        carry=sum/10;
        Node* newNode=new Node(digit);
        if(addHead==NULL){
            addHead=newNode;
            addTail=newNode;

        }else{
            addTail->next=newNode;
            addTail=newNode;
        }
        head1=head1->next;
        head2=head2->next;

    }
    while(head1!=NULL){
        int sum=carry+head1->data;
        int digit=sum%10;
        carry=sum/10;
        Node* newNode=new Node(digit);
        addTail->next=newNode;
        addTail=newNode;
        head1=head1->next;
    }
    while(head2!=NULL){
        int sum=carry+head2->data;
        int digit=sum%10;
        carry=sum/10;
        Node* newNode=new Node(digit);
        addTail->next=newNode;
        addTail=newNode;
        head2=head2->next;
    }
    while(carry!=0){
        int sum=carry;
        int digit=sum%10;
        carry=sum/10;
        Node* newNode=new Node(digit);
        addTail->next=newNode;
        addTail=newNode;
    }

    //reverse ans
    addHead=reverse(addHead);
    return addHead;
}
void print(Node* &head){
    Node* tmp=head;
    while(tmp!=NULL){
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
}
int main(){
    Node* head1=new Node(9);
    head1->next=new Node(5);

    Node* head2=new Node(6);
    head2->next=new Node(4);
    head2->next->next=new Node(3);

   Node* ans= addTwoNo(head1,head2);
   print(ans);
}