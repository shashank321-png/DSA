#include<bits/stdc++.h>
using namespace std;
void useStack(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        s.push(tmp);
    }
    while(!s.empty()){
        int tmp=s.top();
        s.pop();
        q.push(tmp);
    }
}
void reverse(queue<int> &q){
    if(q.empty()){
        return;
    }
    int tmp=q.front();
    q.pop();
    reverse(q);
    q.push(tmp);
}
void kreverse(queue<int> &q,int k){
    stack<int> s;
    int n=q.size();
    int c=0;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        s.push(tmp);
        c++;
        if(c==k){
            break;
        }
    }
    while(!s.empty()){
        int tmp=s.top();
        s.pop();
        q.push(tmp);
    }
    c=0;
    while (!q.empty())
    {
        int tmp=q.front();
        q.pop();
        q.push(tmp);
        c++;
        if(c==(n-k)){
            break;
        }
    }
    
}
void slidingWindow(int a[],int n,int k){
    queue<int> q;
    for(int i=0;i<k;i++){
        if(a[i]<0){
            q.push(i);
        }
    }
    for(int i=k;i<n;i++){
        if(q.empty()){
            cout<<0<<" ";
        }else{
            cout<<a[q.front()]<<" ";
        }
        while((!q.empty()) && (i-q.front()>=k)){
            q.pop();
        }
        if(a[i]<0){
            q.push(i);
        }
    }
    if(q.empty()){
        cout<<0<<" ";
    }
    else{
        cout<<a[q.front()]<<" ";
    }
}
int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(2);
    q.push(5);
    q.push(1);
    q.push(9);
    //useStack(q);
    //reverse(q);
    //kreverse(q,3);
    int a[6]={-8,9,-2,3,4,-5};
    int n=6;
    int k=3;
    slidingWindow(a,n,k);
   /* while(!q.empty()){
        int tmp=q.front();
        q.pop();
        cout<<tmp<<" "; 
    }*/
    cout<<endl;
}