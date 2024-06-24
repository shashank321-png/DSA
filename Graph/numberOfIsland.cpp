// Number of Island on graph
#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int> adj[],int s,bool visited[]){
   
    queue<int> q;
    visited[s]=true;
    q.push(s);
    while(q.empty()==true){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int i:adj[u]){
            if(visited[i]==false){
                visited[i]=true;
                q.push(i);
            }
        }

    }
}

int bfsDiss(vector<int> adj[],int v){
    bool visited[v+1];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    int count=0;
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            bfs(adj,i,visited);
            count++;
        }
    }
    return count;
}