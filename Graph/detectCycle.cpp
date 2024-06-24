// Detect Cycle is Present in Undirected Graph or not
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int>* adj;
    bool isCyclicUntil(int v,bool visited[],int parent);
    public:
    Graph(int v);
    void addEdge(int v,int w);
    bool isCyclic();
};
 Graph::Graph(int v){
    this->v=v;
    adj=new list<int>[v];
}
void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}
bool Graph::isCyclicUntil(int v,bool visited[],int parent){
    visited[v]=true;
    list<int> ::iterator i;
    for( i=adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i]){
            if(isCyclicUntil(*i,visited,v)==true){
                return true;
            }
        }else if(*i!=parent){
            return true;
        }
    }
    return false;
}
bool Graph:: isCyclic(){
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(isCyclicUntil(i,visited,-1)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    Graph b(5);
    b.addEdge(1,0);
    b.addEdge(0,2);
    b.addEdge(2,1);
    b.addEdge(0,3);
    b.addEdge(3,4);
    bool is=b.isCyclic();
    if(is){
    cout<<"Graph is Cyclic"<<endl;
    }else{
    cout<<" Graph is not Cyclic"<<endl;
    }
}