//Detect Cycle in directed Graph
// Deapth first Search
#include<bits/stdc++.h>
using namespace std;

void dfsRec(vector<int> adj[],int s,bool visited[],bool recSt[]){
    visited[s]=true;
    recSt[s]=true;
    
    for(int i:adj[s]){
        if(visited[i]==false && dfsRec(adj,i,visited,recSt)){
            return true;
        }else if(recSt[i]==true){
            return true;
        }
    }
    recSt[s]=false;
    return false;
}
void DFS(vector<int> adj[],int v){
    bool visited[v];
    bool recSt[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
        recSt[i]=false;
    }
   for(int i=0;i<v;i++){
    if(visited[i]==false){
        if(dfsRec(adj,i,visited,recSt)==true){
            return true;
        }
    }
   }
   return false;
}