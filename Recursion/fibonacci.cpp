// Fibonacci Series
// 0 1 1 2 3 5 8 13 . . . . . . .
#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    
    //base case
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    // Recursive Reletion -> fib(n)=fib(n-1)+fib(n-2)

    int ans=fib(n-1)+fib(n-2);
    return ans;  
}
int main(){
    int n;
    cin>>n;
    cout<<n<<" th term of series is: "<<fib(n)<<endl;
    return 0;
}