// Print Digit in a number 
#include<bits/stdc++.h>
using namespace std;

void printDigit(int& n){
    if(n==0){
        return;
    }
    int digit=n%10;
    int newDigit=n/10;
    printDigit(newDigit);
    cout<<digit<<" ";
}
int main(){
    int n=647;
    
   
    printDigit(n);
}