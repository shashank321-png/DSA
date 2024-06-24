// Kth Smallest element 
#include<bits/stdc++.h>
using namespace std;
int getKthSmallest(int a[],int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(a[i]);
    }
    for(int i=k;i<n;i++){
        int element=a[i];
        if(element<pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    int ans=pq.top();
    return ans;
}
int getKthGratest(int a[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(a[i]);
    }
    for(int i=k;i<n;i++){
        int element=a[i];
        if(element>pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    int ans=pq.top();
    return ans;
}
int main(){
    int a[]={3,11,6,9,4,12,2,8};
    int k=3;
    int n=8;
    int ans=getKthSmallest(a,n,k);
    int ans2=getKthGratest(a,n,k);
    cout<<"Answer: "<<ans<<endl<<ans2;
}