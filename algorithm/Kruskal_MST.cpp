/**************************************************************** 
 * Description:  C++ code to implement Kruskal's algorithm
 * Author: Alex Li
 * Date: 2023-05-17 09:53:47
 * LastEditTime: 2023-07-20 23:48:37
****************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1000;;

//用来记录结点集合，避免出现环
int parent[N];
     // n is the number of vetices, m is the number of edge.
int ans,n,m;

struct Edge{  //storage the weight of edge
    int head; 
    int tail;
    int weight;
}edge[N];

bool cmp(Edge a, Edge b){
    return a.weight<b.weight;
}

void Kruscal(){
    sort(edge,edge+m,cmp);  // sort the edge;
    for (int i =1; i <=n; i++)parent[i]=i; //initial parent[]
    for (int i = 0; i <m; i++){
        int pos1=edge[i].head;
        int pos2=edge[i].tail;
        if(parent[pos1]!=parent[pos2]){
            ans+=edge[i].weight;
            int maxx=max(parent[pos1],parent[pos2]);
            int minn=min(parent[pos1],parent[pos2]);
            //把已选结点集合中的大编号都统一到小编号里
            for (int j = 1; j <=n ; j++){
                if(parent[j]==maxx)parent[j]=minn;
            }
            
        }
    }   
}


int main(){
    cin>>n>>m;
    for (int i = 0; i <m; i++){//input the  of edge
        int u,v,w;   //w is the weight with u and v vetise.
        cin>>u>>v>>w;  // input the information about edge
    edge[i].head=u;
    edge[i].tail=v;
    edge[i].weight=w; // storage to struct
    }
    Kruscal();
    cout<<ans;
    
}
