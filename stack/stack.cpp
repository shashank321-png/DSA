#include<iostream>
using namespace std;

class stack{
    public:
        int *arr;
        int top;
        int size;
        stack(int size){
            arr=new int[size];
            this->size=size;
            top=-1;
        }
        void push(int data){
            if(size-top>1){
                top++;
                arr[top]=data;
            }else{
                cout<<"stack is full"<<endl;
            }
        }
        void pop(){
            if(top==-1){
                cout<<"Stack is empty"<<endl;
            }else{
                top--;
            }
        }
        int getTop(){
            if(top==-1){
                 cout<<"Stack is empty"<<endl;
            }else{
                return arr[top];
            }
        }
        int getSize(){
            return top+1;
        }
        bool isEmpty(){
            if(top==-1){
                return true;
            }else{
                return false;
            }
        }
};
int main(){
    stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    st.pop();
    cout<<st.getSize()<<endl;
    cout<<st.getTop()<<endl;
}