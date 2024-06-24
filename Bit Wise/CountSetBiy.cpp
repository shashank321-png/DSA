#include<bits/stdc++.h>
using namespace std;


// Naive Approach  T.C. =Theta(n)
int count(int n){
    int res=0;

    while(n>0){
        if(n%2!=0){     // if((n&1)==1)
            res++;
        }
        n/=2;          // n=n>>1;
    }
    return res;

}

// Brian Kerningam's Algorithm  - This Algorithm takes time Theta(no. of set bits)
int countA(int n){
    int res=0;
    while(n>0){
        n=(n&(n-1));
        res++;
    }
    return res;
}

int main(){
    cout<<count(5)<<endl;
    cout<<countA(40)<<endl;
}