/****************************************************************
 * C++  Lowest Common Ancestor
 * author : ALex Li
 * date: 2023-6-2
 * version: 1.5
 ****************************************************************/
#include <iostream>
#include <vector>
using namespace std;
const int maxn=1000;
int n,m,r,a,b;//n为边个数，r为根结点,a和b为具体结点，
int fa[maxn]; //fa数组是父结点编号。
bool vis[maxn];  //记录祖先结点
vector<int> g[maxn];  //用一个动态数组表示图的邻接表关系

void dfs(int u){
    int j=g[u].size();
    for (int i = 0; i < j; i++){
        int v=g[u][i];
        if(v==fa[u])continue;   //如果是父结点，就忽略后面语句，继续循环
         fa[v]=u;       //记录v结点的父结点是u
         dfs(v);        //递归，深度搜索
    }
    
}
int LCA(int x,int y){
       memset(vis,0,sizeof(vis));//给vis数组清零
       while(x){
        vis[x]=true;
        x=fa[x];
       }
       while(!vis[y])y=fa[y];
       return y;       
}
int main(){
    scanf("%d%d",&n,&r);
    for (int i = 1;i <=n; i++){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
   
    dfs(r);  //r为根结点
    scanf("%d%d",&a,&b);
    printf("%d\n",LCA(a,b));
    
    return 0;
    
} 