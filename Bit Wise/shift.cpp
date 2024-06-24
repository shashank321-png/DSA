#include<bits/stdc++.h>
using namespace std;
int main(){
    int x=3;

    //Left Shift
    cout<<(x<<1)<<endl;
    cout<<(x<<2)<<endl;
    int y=4;
    cout<<x*pow(2,y)<<endl;

    //Right Shift
    x=33;
    cout<<(x>>1)<<endl;
    cout<<(x>>2)<<endl;
    cout<<floor(x/pow(2,y))<<endl;

    // Bitwise Not - in this all zeroes become 1 and vice versa
    unsigned z=1;
    cout<<(~z)<<endl;
    z=5;
    cout<<(~z)<<endl;
}