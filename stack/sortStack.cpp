#include<bits/stdc++.h>
using namespace std;

void insertSorted(stack<int> &s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }
    if(s.top()>=target){
        s.push(target);
        return;
    }
    int topEle=s.top();
    s.pop();
    insertSorted(s,target);
    s.push(topEle);
}
void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int topElement=s.top();
    s.pop();
    sortStack(s);
    insertSorted(s,topElement);
}
int main(){
    stack<int> s;
    s.push(11);
    s.push(1);
    s.push(5);
    s.push(80);
    s.push(2);
    s.push(3);
    sortStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}