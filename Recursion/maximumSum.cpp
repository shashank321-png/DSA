// Maximum sum of non-adjacent elements
#include<bits/stdc++.h>
using namespace std;

void solve(int a[],int i,int sum,int& maxi,int n){
    if(i>=n){
        maxi=max(maxi,sum);
        return;
    }
    // include
    solve(a,i+2,sum+a[i],maxi,n);

    // exclude
    solve(a,i+1,sum,maxi,n);
}
int main(){
    int a[4]={2,1,4,9};
    int sum=0,i=0,n=4;
    int maxi=INT_MIN;
    solve(a,i,sum,maxi,n);
    cout<<"Answer is: "<<maxi<<endl;
}