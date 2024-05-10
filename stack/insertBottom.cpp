#include<bits/stdc++.h>
using namespace std;

/*void solve(stack<int> &s,int target){
    if(s.empty()){
       s.push(target);
       return;
    }
    int targetElement=s.top();
    s.pop();
    //recursive call
    solve(s,target);
    //bactrack
    s.push(targetElement);
}*/
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
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
     if(s.empty()){
        cout<<"Stack is Empty"<<endl;
        return 0;
    }
    int target=s.top();
    s.pop();
    insertAtBottom(s,target);
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
}