/**************************************************************** 
 * Description: C++ implementation  
 * How to find Shortest Paths from Source to all Vertices using Dijkstra’s Algorithm
 * Author: Alex Li
 * Date: 2023-07-05 21:00:29
 * LastEditTime: 2023-07-20 21:17:38
****************************************************************/

#include <iostream>
using namespace std;
const int MAXV = 100;
int n, i , j, v;
int w[MAXV][MAXV]; // 邻接矩阵，记录边长
int pre[MAXV]; //每个结点的前驱
int dist[MAXV];  //存储0点到其它结点的最短路径长度
int used[MAXV]; // 记录结点是否已确定最短距离（0：未确定；1：已确定）

//输出结点最短路径
void Path(int u){
    if(u==-1)return;
    Path(pre[u]);
    cout<<u<<" ";
}
int main() {
    cin >> n;  //n为结点数
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> w[i][j]; //录入边长
    dist[0] = 0;  //0点到自身的距离为0
     //初始化所有结点距离
    for (i = 1; i < n; i++)dist[i] = -1; 
    //初始化所有结点的前驱
    for (int i = 0; i <n; i++)pre[i]=-1;
    //初始化所有结点为未扩展状态
    for (i = 0; i < n; i++)used[i] = 0;
    
    while (true) {
        v=-1 ;

//v刚开始赋的是-1，意思是还没找到距离最近的点，在循环里满足判断条件的i结点，也就是dist最短的结点
//会赋给v（因为v==-1是在||左边的，当||左边为真时右边不参与运算，不会越界）
//当所有结点都已经used[i]=1,则v=-1,while循环结束。        
        for (i = 0; i < n; i++)
            if (used[i] != 1 && dist[i] != -1 && (v == -1 || dist[i]<dist[v] ))
            v=i;

//如果没有找到哪个结点还没被访问，或者没有距离的，说明所有结果都已经找好最短路径，v==-1，结束循环。
        if(v == -1)
            break;
        used[v]=1;

//寻找所有v结点的相邻结点，如果没有距离，或者从v点连接距离较短，更新路径和路径前驱
        for (i = 0; i < n; i++)
            if (w[v][i] != -1 && (dist[i] == -1 || dist[v]+w[v][i]<dist[i] )){
                dist[i] = dist[v] + w[v][i];
                pre[i]=v;
            }
                
        //依次更新每个点所到相邻的点路径值
    }

//打印每个结点的最短路径的值和经过的结点
    for (i = 0; i < n; i++){
        cout << "node["<<i<<"]distance is "<<dist[i] <<" and the path is ";
         Path(i);
        cout<< endl;
    }
    return 0;
}
