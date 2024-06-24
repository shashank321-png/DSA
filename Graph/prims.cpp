// Prims Algorithm
#include<bits/stdc++.h>
using namespace std;

int prims(int graph[][],int v){
    int key[v],res=0;
    bool mSet;
    for(int i=0;i<v;i++){
        key[i]=INT_MAX;
        mSet[i]=false;
    }
    for(int i=0;i<v;i++){
        int u=-1;
        for(int j=0;j<v;j++){
            if(!mSet[j] && (u==-1 || key[i]<key<[u])){
                u=i;
            }
        }
        mSet[u]=true;
        res+=key[u];
        for(int k=0;k<v;k++){
            if(graph[u][k]!=0 && !mSet[k]){
                key[k]=min(key[u],graph[u][k]);
            }
        }
    }
    return res;
}
int main(){
    int vertices=5;
     int g[vertices][vertices] = {{0, 0, 3, 0, 0},    
                                {0, 0, 10, 4, 0},    
                                {3, 10, 0, 2, 6},    
                                {0, 4, 2, 0, 1},    
                                {0, 0, 6, 1, 0},    
                                };   
    int ans=prims(g,vertices);
    cout<<ans<<endl;    
}