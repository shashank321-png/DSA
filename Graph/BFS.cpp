// Breadth First Search
#include<bits/stdc++.h>
using namespace std;

// For Connected Graph
void bfsSearch(vector<int> adj[],int v,int s){
    bool visited[v+1];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    queue<int> q;
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

// For No Source given and graph may be disconnected
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

void bfsDiss(vector<int> adj[],int v){
    bool visited[v+1];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            bfs(adj,i,visited);
        }
    }
}
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
    int v=13;
    vector<int> adj[v];
    adjc(adj,0,1);
    adjc(adj,0,2);
    adjc(adj,1,0);
    adjc(adj,1,2);
    adjc(adj,1,3);
    adjc(adj,2,0);
    adjc(adj,2,1);
    adjc(adj,2,3);
    adjc(adj,2,4);
    adjc(adj,3,1);
    adjc(adj,3,2);
    adjc(adj,3,4);
    adjc(adj,4,2);
    adjc(adj,4,3);
    bfsSearch(adjc,4,0);
    
}