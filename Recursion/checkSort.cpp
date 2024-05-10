// Check array is sorted or unsorted
#include<bits/stdc++.h>
using namespace std;

bool checkSorted(int a[],int n,int i){
    if(i>=n){
        return true;
    }
    if(a[i]<a[i-1]){
        return false;
    }
    checkSorted(a,n,i+1);
}
int main(){
    int a[5]={10,20,30,40,50};
    int n=5,i=1;
    bool ans=checkSorted(a,n,i);
    cout<<"ANswer : "<<ans<<endl;
}