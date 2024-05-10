#include<bits/stdc++.h>
using namespace std;

class  Stack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;
     
    Stack(int size){
        arr=new int[size];
        top1=-1;
        top2=size;
        this->size=size;
    }
    void push1(int data){
        if(top2-top1==1){
            cout<<"OVERFLOW"<<endl;
        }else{
            top1++;
            arr[top1]=data;
        }
    }
    void push2(int data){
        if(top2-top1==1){
            cout<<"OVERFLOW"<<endl;
        }else{
            top2--;
            arr[top2]=data;
        }
    }
    void pop1(){
        if(top1==-1){
            cout<<"UNDERFLOW"<<endl;
        }else{
            top1--;
        }
    }
    void pop2(){
        if(top2==size){
            cout<<"UNDERFLOW"<<endl;
        }else{
            top2++;
        }
    }
void print(){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

};
int main(){
    Stack st(6);

    st.push1(10);
    st.print();
    st.push1(20);
    st.print();
    st.push1(30);
    st.print();
    st.push1(40);
    st.print();

    st.push2(500);
    st.print();
    st.push2(700);
    st.print();
    st.push2(900);
    st.print();



}