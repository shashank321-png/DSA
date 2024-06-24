#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q,int k){
   // step 1 : queue ke first k elements ko stack me dalo
   stack<int> s;
   int c=0;
   int n=q.size();
   if(k==0 && k>n){
    return;
   }
   while(!q.empty()){
    int tmp=q.front();
    q.pop();
    s.push(tmp);
    c++;
    if(c==k){
        break;
    }
   }

   //step 2 : queue me vapas dlo
   while(!s.empty()){
    int tmp=s.top();
    s.pop();
    q.push(tmp);
   } 

   //step 3 : push n-k element from q front to back
   c=0; 
   while(!q.empty() && n-k!=0){
    int tmp=q.front();
    q.pop();
    q.push(tmp);
    c++;
    if(c==n-k){
        break;
    }
   }
}
int main(){
queue<int> q;
q.push(3);
q.push(6);
q.push(9);
q.push(12);
q.push(15);


reverse(q,3);
while(!q.empty()){
   cout<<q.front()<<" ";
   q.pop();
}
cout<<endl;
}