#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerIndex(vector<int> & in){
    stack<int> s;
    s.push(-1);
    vector<int> ans(in.size());
    for(int i=in.size()-1;i>=0;i--)
    {
        int curr=in[i];
        while(s.top()!=-1 && in[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int> preSmallerIndex(vector<int> & in){
    stack<int> s;
    s.push(-1);
    vector<int> ans(in.size());
    for(int i=0;i<in.size();i++)
    {
        int curr=in[i];
        while(s.top()!=-1 && in[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

int getRectangularHeight(vector<int> & height){
    // step1 - prevSmaller
    vector<int> pre=preSmallerIndex(height);
    // step2 - nextSmaller
    vector<int> next=nextSmallerIndex(height);
    int size=height.size();
    int maxArea=INT_MIN;

    for(int i=0;i<height.size();i++){
        int len=height[i];
        if(next[i]==-1){
            next[i]=size;
        }
        int width=next[i]-pre[i]-1;
        int area=width*len;
        maxArea=max(area,maxArea);
    }
    return maxArea;
}
int main(){
    vector<int> height;
    height.push_back(2);
    height.push_back(1);
    height.push_back(5);
    height.push_back(6);
    height.push_back(2);
    height.push_back(3);
    cout<<"Ans is: "<<getRectangularHeight(height);
   
    cout<<endl;
}