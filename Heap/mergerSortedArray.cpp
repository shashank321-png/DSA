// Merge K sorted arrays
#include<bits/stdc++.h>
using namespace std;

class info{
    public:
    int data;
    int row;
    int col;
    info(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
};
class compare{
    public:
    bool operator()(info* a,info* b){
        return a->data>b->data;
    }
};
vector<int> solve(int a[][4],int k,int n){
    priority_queue<info* ,vector<info*>,compare> minHeap;
    for(int i=0;i<k;i++){
        info* tmp=new info(a[i][0],i,0);
        minHeap.push(tmp);
    }
    vector<int> ans;
    while(!minHeap.empty()){
        info* tmp=minHeap.top();
        int topELe=tmp->data;
        int topCol=tmp->col;
        int topRow=tmp->row;
        minHeap.pop();

        ans.push_back(topELe);
        if(topCol+1<n){
            info* tmp=new info(a[topRow][topCol+1],topRow,topCol+1);
            minHeap.push(tmp);
        }
    }
    return ans;
}
int main(){
    int a[][4]={{2,4,6,8},{1,3,5,7},{0,9,10,11}};
    int n=4,k=3;
    vector<int> ans=solve(a,k,n);
    for(auto i:ans){
        cout<<i<<" ";
    }
}