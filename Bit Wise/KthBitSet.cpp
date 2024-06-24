#include<bits/stdc++.h>
using namespace std;

// By Left Shift
void KthBitSet(int n,int k){
    if(n&(1<<(k-1))!=0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}


//By Right Shift
void KthBitSetR(int n,int k){
    if((n>>(k-1)&1)==1){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;

    }
}

int main(){
    KthBitSet(5,3);
    KthBitSetR(13,3);
}