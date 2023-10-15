/**************************************************************** 
 * Description: C++ implementation of 0-1 KnapSack
 * Author: Alex Li
 * Date: 2022-04-23 15:40:21
 * LastEditTime: 2023-06-20 10:43:48
****************************************************************/
#include <iostream>
using namespace std;

int dp[35][205];  ////记录统计数据
int weight[35];  //存储各商品的重量
int value[35];  //存储各商品的价值
int choose[35];

//回溯一下，看看哪些商品被用到了。
void flashBack(int m,int n){
    int i=n,j=m;
    int k=0;
    while (i!=0){
        if(dp[i][j]==dp[i-1][j])
        i--;
        else{
           choose[k]=i;
           j=j-weight[i];
           k++;
           i--;
        }
    }
}
int main(){
    int m,n;  //n为商品个数，m为背包容量(重量)
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>weight[i]>>value[i];   //l输入每个商品的 重量和价值 
    }
    for (int i = 1; i <=n; i++){    //逐个遍历每个商品
        for (int j = 1; j <=m; j++){  //求出从 1 到 m 各个载重对应的最大收益
            if(j<weight[i])        //如果i商品的重量大于背包的容量，哪就不装该商品
                dp[i][j]=dp[i-1][j]; //当i等于0时，dp[0][i]都在数组创建时，赋值为零。 
            else   //比较不装入该商品和装入该商品，哪种情况获得的收益更大，记录最大收益值
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]); 
                //dp[i-1][j]是不装入i商品的价值
                //d[i-1][j-weight[i]]是指减掉i商品的重量后，剩余的背包容量能装商品的价值
                //d[i-1][j-weight[i]]+value[i]加上i商品后的背包价值
        }
    }
    cout<<"max value in knapsack is: "<<dp[n][m]<<endl;  //输出结果
    //回溯被商品
    flashBack(m,n);
    //输出被选择的商品
    cout<<"which article is choosed: ";
    for (int i = 0; i <n; i++){
        if(choose[i]==0)break;
        else cout<<choose[i]<<' ';
    }
    
    cout<<endl;
    //输出dp表看变化
    cout<<"print dp array: "<<endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j<=m ; j++){
            if(dp[i][j]/10==0)cout<<' ';
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
    
}
