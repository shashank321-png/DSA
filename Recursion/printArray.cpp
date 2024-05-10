// Print Array

#include<bits/stdc++.h>
using namespace std;

void print(int a[],int n,int i){
    if(i>=n){
        return; 
    }
    cout<<a[i]<<" ";
    return print(a,n,i+1);
}

int main(){
    int a[5]={10,20,30,40,50};
    int n=5,i=0;
    print(a,n,i);
    cout<<endl;
}