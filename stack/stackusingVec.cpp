#include<bits/stdc++.h>
using namespace std;

struct mystack{
    vector<int> s;
    void push(int x){
        s.push_back(x);
    }
    int pop(){
        int res=s.back();
        s.pop_back();
        return res;
    }
    int size(){
        return s.size();
    }
    int peek(){
        return s.back();
    }
    bool isEmpty(){
        return s.empty();
    }
};
int main(){
    mystack s;
    s.push(10);
    s.push(7);
    s.push(98);
    cout<<s.peek()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
}