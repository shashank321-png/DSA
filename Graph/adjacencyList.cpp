// Adjacency List
#include<bits/stdc++.h>
using namespace std;
void adjc(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print(vector<int> adj[],int v){
    for(int i=0;i<v;i++){
        for(int x:adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int v=4;
    vector<int> adj[v];
    adjc(adj,0,1);
    adjc(adj,0,2);
    adjc(adj,1,2);
    adjc(adj,1,3);
    print(adj,v);
}