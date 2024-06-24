// Shortest Path in an Unweighted Graph
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> adj[],int s,int v){
    vector<int> dist(v,0);
    dist[s]=0;
    queue<int> q;
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i:adj[u]){
            if(visited[i]==false){
                dist[i]=dist[u]+1;
                visited[i]=true;
                q.push(i);
            }
        }
    }
    return dist;
}