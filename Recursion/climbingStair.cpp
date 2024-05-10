// climbing stairs

#include<bits/stdc++.h>
using namespace std;

int climbingStair(int n){

    //Base case There is only 1 way to reach 0th stair
    if(n==0 || n==1){
        return 1;
    } 

    return climbingStair(n-1)+climbingStair(n-2);
}
int main(){
    int n;
    cout<<"Enter no. of Stairs : ";
    cin>>n;
    cout<<"The no. of ways to climb stairs: "<<climbingStair(n)<<endl;
}