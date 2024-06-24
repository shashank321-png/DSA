#include<bits/stdc++.h>
using namespace std;
void print(queue<int> &a){
    while(!a.empty()){
        cout<<a.front()<<" ";
        a.pop();
    }
}
void reverse(queue<int> &a){
    stack<int> st;
    while(!a.empty()){
        
        st.push(a.front());
        a.pop();
    }
    while(!st.empty()){
        
        a.push(st.top());
        st.pop();
    }
}
int main(){
    queue<int> a;
    a.push(3);
    a.push(5);
    a.push(8);
    a.push(1);
    a.push(6);
    a.push(7);
    reverse(a);
    print(a);
        }