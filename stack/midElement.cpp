#include<bits/stdc++.h>
using namespace std;

void midEle(stack<int> &s,int &len){
    if(s.size()==len/2+1){
        cout<<"Middle element is :"<<s.top()<<endl;
        return;
    }
    int tmp=s.top();
    s.pop();
    midEle(s,len);
    s.push(tmp);
}
int main(){
   stack<int> s;
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   s.push(5);
   //s.push(6);
   //s.push(7);
   int n=s.size();
    midEle(s,n);

    cout<<endl;
}