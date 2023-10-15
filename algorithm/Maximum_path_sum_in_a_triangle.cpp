/**************************************************************** 
 * Description: C++ implementation of Maximum path sum in a triangle.
 * Author: Alex Li
 * Date: 2023-06-14 19:51:06
 * LastEditTime: 2023-06-14 20:51:32
****************************************************************/
#include <iostream>
using namespace std;
const int MAXN=1005;
int NT[MAXN][MAXN];  // use a array to store the Number Triangle.
int N;   // N is max level of the number triangles
int MaxSum; //  the final Maximum path sum.

void DFS(int x,int y, int Current){
   if(x==N){
       if(Current>MaxSum)
       MaxSum=Current;
       return;
   }
   DFS(x+1,y,Current+NT[x+1][y]);
   DFS(x+1,y+1,Current+NT[x+1][y+1]);
}
int main(){
    cin>>N;
    for (int i = 1; i <=N; i++){
        for (int j = 1; j <=i;j++){
            cin>>NT[i][j];
        }
    }
        MaxSum=0;
        DFS(1,1,NT[1][1]);
        cout<<MaxSum<<endl;
        return 0;
}