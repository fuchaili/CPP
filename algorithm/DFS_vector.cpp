#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> adj[],int u,vector<bool>&visited){
    visited[u]=true;
    cout<<u<<" ";
    for (int v:adj[u]){
        if(!visited[v])dfs(adj,v,visited);
    }
    
}

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool>  visited(n,false);
    for (int u = 0; u < n; u++){
        if(!visited[u]){
            dfs(adj,u,visited);
        }
    }
    
    
}