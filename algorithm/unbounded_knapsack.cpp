/**************************************************************** 
 * Description: C++ implementation of unbounded knapsack
 * Author: Alex Li
 * Date: 2023-06-20 16:43:44
 * LastEditTime: 2023-06-20 21:22:28
****************************************************************/
#include <iostream>
using namespace std;

const int MAXN=1000;
const int MAXV=100;
int dp[MAXN][MAXV];
int value[MAXV];
int weight[MAXN];

int main(){
    int n,m,ik[MAXN][MAXV];
   
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>weight[i]>>value[i];
    
    for(int i=1;i<=n;i++){
        for (int j = 0; j <=m; j++){
            //k是指i商品被用的件数,当k为0时，也就代表不选i商品，相当于初始化dp[i][j]
            for (int k = 0; k*weight[i]<=j; k++){
                dp[i][j]=max(dp[i][j],dp[i-1][j-k*weight[i]]+k*value[i]);
            }
        }
    }
    cout<<dp[n][m];

    return 0;    
}