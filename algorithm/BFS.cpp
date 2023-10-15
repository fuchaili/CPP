#include <iostream>
#include <queue>
using namespace std;
const int MAX=100;
bool visited[MAX]={false};
int graph[MAX][MAX]={0};
int n,m;  //n is the number of nodes, m is the number of edges

void BFS(int start){
     queue<int> q;
     visited[start]=1;
     q.push(start);

     while(!q.empty()){
        int curr=q.front();
        cout<<curr<<' ';
        q.pop();

        for (int i = 0; i < n; i++){
            if(graph[curr][i]==1 && visited[i]==0){
                visited[i]=1;
                q.push(i);
            }
        }
        

        }
     }

int main(){
    cin >>n>>m;
    for (int  i = 0; i <m; i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]=graph[v][u]=1;
    }
    BFS(0);  //start DFS from node 0
    return 0;
}