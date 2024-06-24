#include<bits/stdc++.h>
using namespace std;

class QueueStack{

public:
    queue<int> q1;
    queue<int> q2;
    //Function to push an element into stack using two queues.
void push(int x)
{
      while(!q1.empty()){
          int tmp=q1.front();
          q1.pop();
          q2.push(tmp);
      }
      q1.push(x);
      while(!q2.empty()){
          int tmp=q2.front();
          q2.pop();
          q1.push(tmp);
      }
      
}

//Function to pop an element from stack using two queues. 
int pop()
{
    while(!q1.empty()){
      int tmp=q1.front();
      q1.pop();
      return tmp;
        
    }
    return -1;
}


};
int main(){
    QueueStack q;
    q.push(1);
    q.push(4);
    q.push(2);
    q.push(7);
    q.push(19);
    q.push(20);
    q.pop();
    q.pop();
    q.push(31);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        cout<<front<<" ";
    }
}