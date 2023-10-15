/**************************************************************** 
 * Description: C++ implementation of Maximum path sum in a triangle.
 * Author: Alex Li
 * Date: 2023-06-14 19:51:06
 * LastEditTime: 2023-06-14 22:34:38
****************************************************************/
#include <iostream>
using namespace std;
const int MAXN=1005;
int NT[MAXN][MAXN];  // use a array to store the Number Triangle.
int Sum[MAXN][MAXN];   //  store the max sum of path 
int N;   // N is max level of the number triangles

// from bottom to top
int  DFS(int x,int y){
   if(Sum[x][y]==-1){  // if Sum[][] doesn't calculate.
       if(x==N)Sum[x][y]=NT[x][y];
       else Sum[x][y]=NT[x][y]+max(DFS(x+1,y),DFS(x+1,y+1));
       
   }
  return Sum[x][y];
}
int main(){
    cin>>N;
    for (int i = 1; i <=N; i++){
        for (int j = 1; j <=i;j++){
            cin>>NT[i][j];
        }
    }

     for (int i = 1; i <=N; i++){
        for (int j = 1; j <=i;j++){
            Sum[i][j]=-1;
        }
    }
     
        DFS(1,1);
        cout<<Sum[1][1]<<endl;
        return 0;
}