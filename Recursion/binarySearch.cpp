// Binary Search
#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int& a[],int& n,int s,int e,int& key){  // always pass by reference method because array takes one time memory
    if(s>e){
        return false;
    }
    int mid=(s+e)/2;
    if(a[mid]==key){
        return true;
    }else
    if(a[mid]<key){
        binarySearch(a,n,mid+1,e,key);
    }else{
        binarySearch(a,n,s,mid-1,key);
    }

}
int main(){
    int a[6]={10,50,60,30,70,90};
    int n=6;
    int s=0,e=n-1, key=1000;
    bool ans=binarySearch(a,n,s,e,key);
    if(ans){
        cout<<"Present"<<endl;
    }else{
        cout<<"Not Present"<<endl;
    }
}