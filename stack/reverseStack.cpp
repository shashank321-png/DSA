#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s,int target){
       if(s.empty()){
       s.push(target);
       return ;
    }
    int targetElement=s.top();
    s.pop();
    //recursive call
    insertAtBottom(s,target);
    //bactrack
    s.push(targetElement);
}
void reverseStack(stack<int> &s){
    //base case
    if(s.empty()){
        cout<<"Stack is empty"<<endl;
    }
    int target=s.top();
    s.pop();

    //reverse remaining stack
    reverseStack(s);
    insertAtBottom(s,target);
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    reverseStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}