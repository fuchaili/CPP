/**************************************************************** 
 * Description: LCA implementation with binary lifting
 * Author: Alex Li
 * Date: 2023-06-12 08:36:14
 * LastEditTime: 2023-06-12 17:13:33
****************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


const int MAX_SIZE=10001,MAX_DEPTH=16; //MAX_DEPTH> log2(MAX_SIZE)

vector<int>  graph[MAX_SIZE]; //vector store tree.

int depth[MAX_SIZE]; //the depth of the node

int fathers[MAX_SIZE][MAX_DEPTH]; //[i][j] store the 2^j of the fathers for i node .

bool visited[MAX_SIZE]; //node is visited

int N;// actually the number

//dfs to assign depths and fathers in the tree for every node
void DFS(int node, int father){
    visited[node]=true;
    depth[node]=depth[father]+1;
    fathers[node][0]=father;
    for(int i=1;i<MAX_DEPTH;i++)
    fathers[node][i]=fathers[fathers[node][i-1]][i-1];
    int cnt=graph[node].size();
    for (int i = 0; i <cnt; i++){
        if(!visited[graph[node][i]])
            DFS(graph[node][i],node);
    }
}

int LCA(int a, int b){

    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int l=ceil(log2(MAX_DEPTH));
    for (int i = l; i >= 0; i --) {
        if (depth[a]-(1<<i) >= depth[b]) {
            a = fathers[a][i];
        }
    }
    
    if (a == b) return a;

    for (int i = MAX_DEPTH - 1; i >= 0; i --) {
        if (fathers[a][i] != 0 && fathers[a][i] != fathers[b][i]) {
            a = fathers[a][i];
            b = fathers[b][i];
        }
    }

    
    return fathers[a][0];
}
int main(){
    cout<<"please input the number of edges：";
    cin>>N;
    int a,b;
    for(int i=1;i<=N;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    DFS(1,0); // 1 node is root, and the fathers is 0

    int u,v;
    cout<<"please input two node which you want to know LCA: ";
    cin>>u>>v;
    cout<<"the LCA of "<<u<<" and "<<v<<" is "<<LCA(u,v);

}


