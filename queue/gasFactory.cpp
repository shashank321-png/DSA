#include<bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost){

    // kitna pertrol kmm padh gya
    int deficit=0;

    //kitna petrol bacha hai
    int balance=0;

    //circuit kha se start krr rhe ho
    int start=0;

    for(int i=0;i<gas.size();i++){
        balance+=gas[i]-cost[i];
        if(balance<0){
            deficit+=balance;
            start=i+1;
            balance=0;
        }
    } 
    if(deficit+balance<0){
        return start;
    }else{
        return -1;
    }
}
int main(){
    vector<int> gas={}
}