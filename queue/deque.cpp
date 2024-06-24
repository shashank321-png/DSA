#include<bits/stdc++.h>
using namespace std;

class deque{
    public:
    int size;
    int *arr;
    int front;
    int rear;
    deque(int size){
        this->size=size;
        front=-1;
        rear=-1;
        arr=new int[size];
    }   
    void pushRear(int data){
        if(front==0 && rear==size-1){
            cout<<"Queue is full"<<endl;
        }else if(front ==-1){
            front=rear=0;
            arr[rear]=data;
        }else if(rear=size-1 && front!=0 ){
            rear=0;
            arr[rear]=data;
        }else {
            rear++;
            arr[rear]=data;
        }
    }
    void pushFront(int data){
        if(front==0 && rear==size-1){
            cout<<"Queue is full"<<endl;
            return;
        }else if(front ==-1){
            front=rear=0;
            arr[front]=data;
        }else if(rear!=size-1 && front==0 ){
            front=size-1;
            arr[front]=data;
        }else {
            front--;
            arr[front]=data;
        }
    }
    void popFront(){
         if(front==-1){
            cout<<"Queue is empty"<<endl;
        }else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }else if(front==size-1){
            front=0;
        }else{
            front++;
        }
    }
    void popRear(){
         if(front==-1){
            cout<<"Queue is empty"<<endl;
        }else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }else if(rear==0){
            rear=size-1;
        }else{
            rear--;
        }
    }
    
};
int main(){

}