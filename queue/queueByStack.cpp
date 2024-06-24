#include<bits/stdc++.h>
using namespace std;
class Queue{
    public:
    stack<int> s1,s2;
    void push(int x){
        s1.push(x);
    }
    int pop(){
        int pop=-1;
        if(!s2.empty()){
            pop=s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            pop=s2.top();
        }
        s2.pop();
        return pop;
    }
    int peek(){
        int front=-1;
         if(!s2.empty()){
            front=s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            front=s2.top();
        }
        return front;
    }
};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(9);
    cout<<q.peek()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
}