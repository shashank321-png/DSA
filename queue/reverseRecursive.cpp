#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q){
    //Base case
    if(q.empty())
        return;
    // step- 1 : pop first element
    int tmp=q.front();
    q.pop();

    //step- 2 : reverse remaining element
    reverse(q);

    //step- 3 : push first element
    q.push(tmp);
}

int main(){
    queue<int> q;
    q.push(7);
    q.push(2);
    q.push(4);
    q.push(1);
    q.push(7);
    q.push(0);
    q.push(5);
    reverse(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}