// Topological Sorting or Khan's Algorithm
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int>* adj;
    public:
        Graph(int v);
        void addE(int u,int v);
        void topologicalSort();
};
Graph::Graph(int v){
    this->v=v;
    adj=new list<int>[v];
}
void Graph::addE(int u,int v){
    adj[u].push_back(v);
}
void Graph::topologicalSort(){
    vector<int> inorder(v,0);
    for(int i=0;i<v;i++){
        list<int>::iterator it;
        for(it=adj[i].begin();it!=adj[i].end();it++){
            inorder[*it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(inorder[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ans.push_back(u);
        list<int>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++){
            if(--inorder[*it]==0){
                q.push(*it);
            }     }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
     Graph g(6);
    g.addE(5, 2);
    g.addE(5, 0);
    g.addE(4, 0);
    g.addE(4, 1);
    g.addE(2, 3);
    g.addE(3, 1);
 
    g.topologicalSort();
 
    return 0;
}
