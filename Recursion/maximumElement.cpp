// Maximum Element 
#include<bits/stdc++.h>
using namespace std;

void printMaximum(int a[],int n,int i,int& maxi){
    if(i>=n){
        return;
    }
    if(a[i]>maxi){
        maxi=a[i];
    }
    return printMaximum(a,n,i+1,maxi);
}
int main(){
    int a[8]={10,20,30,5,66,45,32,1};
    int n=8;
    int maxi=INT_MIN;
    int i=0;
    printMaximum(a,n,i,maxi);
    cout<<maxi<<endl;
}