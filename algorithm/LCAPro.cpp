#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N=500;
int n,m,root,x,y,a;   //n为边数，m为查询次数，root为根结点
vector<int>e[N];
int deep[N],fa[N][10];

void dfs(int x,int d){  
    int y;
    deep[x]=d;//求每个点的深度
  
    for (int i = 0; i <e[x].size(); i++){
        y=e[x][i];
        if ((deep[y]!=0)&&(deep[y]==(deep[x]-1)))continue;//如果是这个点的父亲，就跳过
        fa[y][0]=x; //否则，把下面这个点的父亲标记成它
         dfs(y,d+1);
    }
}

int LCA(int x, int y){
    if(deep[x]<deep[y])swap(x,y);//确保x是较深的哪个
    for (int i = a; i >=0; i--){
        if (deep[fa[x][i]]>=deep[y])x=fa[x][i];//把x和y移动到同一高度。
    }
    if(x==y)return x;
    for (int i = a; i >=0; i--){   //x和y一起向上，直到有同一个父结点
        if (fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];  //x和y是兄弟
        }
    }
    return fa[x][0];    
}

int main(){
    cin>>n>>root;
    for (int i = 0; i < n; i++){
        cin>>x>>y;
    e[x].push_back(y);
    e[y].push_back(x);
    }
    dfs(root,1);
      for(int i=1;i<=n;i--){
           a=max(a,deep[n]);
      }

        for (int i = 1; i <=10 ; i++){
        for (int j = 1; j <=n; j++){
            fa[j][i]=fa[fa[j][i-1]][i-1];
        }
    }
    
        cin>>x>>y;
        cout<<LCA(x,y)<<endl;
    
    return 0;
}
