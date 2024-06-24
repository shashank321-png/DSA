#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
        int *arr;
        int size;
        int front;
        int rear;
        Queue(int size){
            this->size=size;
            arr=new int[size];
            front=-1;
            rear=-1;
        }
        void push(int data){
            if(front==0 && rear==size-1){
                cout<<"Queue is full"<<endl;
            }else if(front ==rear){
                front =0;
                rear=0;
                arr[rear]=data;
            }else if(rear==size-1 && front!=0){
                rear=0;
                arr[rear]=data;
            }else{
                rear++;
                arr[rear]=data;
            }
        }
        void pop(){
            if(front==-1){
                cout<<"Queue is empty"<<endl;
            }else if(front==rear){
                arr[front]=-1;
                front=rear=-1;
            }else if(front==size-1){
                front=0;
            }else{
                front++;
            }
        }
};