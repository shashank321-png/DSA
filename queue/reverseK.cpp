#include<bits/stdc++.h>
using namespace std;
 
void reverseK(queue<int> &q,int k){
    stack<int> st;
    int c=0;
    int n=q.size();
    if(n==0 || n>k){
        return;
    }
    while (!q.empty())
    {
        int tmp=q.front();
        q.pop();
        st.push(tmp);
        c++;
        if(c==k)
            break;
    }
    while(!st.empty()){
        int tmp=st.top();
        st.pop();
        q.push(tmp);
    }
    c=0;
    while(!q.empty() && n-k!=0){
        int tmp=q.front();
        q.pop();
        q.push(tmp);
        c++;
        if(c==n-k){
            break;
        }
    }
}
void print(queue<int> &q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
int main(){
    queue<int> q;
    q.push(10);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(14);
    q.push(5);
    q.push(9);
    reverseK(q,7);
    print(q);

}