#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> in;
    in.push_back(2);
    in.push_back(1);
    in.push_back(4);
    in.push_back(3);
    stack<int> s;
    s.push(-1);
    vector<int> ans(in.size());
    for(int i=0;i<in.size();i++)
    {
        int curr=in[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }
    for(int i=0;i<in.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}