#include<bits/stdc++.h>
using namespace std;

void solve(int a[],int n,int k){
    deque<int> dq;
    // process first window of size k
    for(int i=0;i<k;i++){
        if(a[i]<0){
            dq.push_back(i);
        }
    }

    // process remaining windows
    for(int i=k;i<n;i++){

        // answer dedo purani window ka
        if(dq.empty()){
            cout<<0<<" ";
        }else{
            cout<<a[dq.front()]<<" ";
        }

        // out of window element ko remove
        while((!dq.empty())&& (i-dq.front()>=k)){
            dq.pop_front();
        }

        // check current element for insertion
        if(a[i]<0){
            dq.push_back(i);
        }

    }

    // answer print kro for last window
      if(dq.empty()){
            cout<<0<<" ";
        }else{
            cout<<a[dq.front()]<<" ";
        }
}
int main(){
    int a[]={12,-1,-7,8,-15,30,16,18};
    int n=8;
    int k=3;
    solve(a,n,k);
}