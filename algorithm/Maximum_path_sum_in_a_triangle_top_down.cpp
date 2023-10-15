/**************************************************************** 
 * Description: C++ implementation of Maximum path sum in a triangle.
 * Author: Alex Li
 * Date: 2023-06-14 19:51:06
 * LastEditTime: 2023-06-14 22:38:23
****************************************************************/
#include <iostream>
using namespace std;
const int MAXN=1005;
int NT[MAXN][MAXN];  // use a array to store the Number Triangle.
int Sum[MAXN][MAXN];   //  store the max sum of path 
int N;   // N is max level of the number triangles

//from top to bottom
int main(){
    cin>>N;
    for (int i = 1; i <=N; i++){
        for (int j = 1; j <=i;j++){
            cin>>NT[i][j];
        }
    }
Sum[1][1]=NT[1][1];
    for (int i = 2; i <=N; i++){
        for (int j = 1; j <= i; j++)
        Sum[i][j]=max(Sum[i-1][j-1],Sum[i-1][j])+NT[i][j];
        }
    int ans=0;

    for(int j=1;j<=N;j++)
         ans=max(ans,Sum[N][j]);
    cout<<ans<<endl;
        return 0;
}