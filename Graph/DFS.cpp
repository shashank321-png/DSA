// Deapth first Search
#include<bits/stdc++.h>
using namespace std;

void dfsRec(vector<int> adj[],int s,bool visited[]){
    visited[s]=true;
    cout<<s<<" ";
    for(int i:adj[s]){
        if(visited[i]==false){
            dfsRec(adj,i,visited);
        }
    }
}
void DFS(vector<int> adj[],int s,int v){
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    DFS(adj,s,visited);
}