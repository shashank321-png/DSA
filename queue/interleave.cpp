#include<bits/stdc++.h>
using namespace std;

void inter(queue<int> &q){
    int n=q.size();
    if(q.empty()){
        return;
    }
    int c=0;
    int k=n/2;
    queue<int> q2;
    // step 1: seprate both halves
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        q2.push(tmp);
        c++;
        if(c==k){
            break;
        }
    }
    
    // step 2: interleaving start krdo
    while(!q.empty() && !q2.empty()){
        int tmp=q2.front();
        q2.pop();
        q.push(tmp);
        int tmp1=q.front();
        q.pop();
        q.push(tmp1);
    }

    // step 3: handle odd element in queue
    if(n&1){
        int tmp=q.front();
        q.pop();
        q.push(tmp);
    }
}
int main(){
    queue<int> q;
    q.push(10);
    q.push(2);
    q.push(5);
    q.push(6);
    q.push(0);
    q.push(8);
    //q.push(7);
    inter(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}