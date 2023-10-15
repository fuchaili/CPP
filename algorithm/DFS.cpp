#include <iostream>
using namespace std;
const int MAX=100;
bool visited[MAX]={false};
int adj[MAX][MAX]={0};

int n,m;  //n is the number of nodes, m is the number of edges

void dfs(int u){
    visited[u]=true;
    cout<<u<<" ";

    for (int v = 0; v < n; v++){
        if(adj[u][v] && !visited[v])
        dfs(v);
    }
}

int main(){
    cin >>n>>m;
    for (int  i = 0; i <m; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=adj[v][u]=1;
    }
    dfs(0);  //start DFS from node 0
    return 0;
}