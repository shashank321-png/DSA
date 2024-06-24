#include<bits/stdc++.h>
using namespace std;


// Naive approach 
bool check(int n){
    if(n==0){
        return false;
    }

    while(n!=1){
        if(n%2!=0){
            return false;
        }
        n/=2;
    }
    return true;
}

// Efficient approach

bool checkA(int n){
    if(n==0){
        return false;
    }
    return ((n&(n-1))==0);
}
int main(){
    cout<<check(8)<<endl;
    cout<<checkA(6)<<endl;
}