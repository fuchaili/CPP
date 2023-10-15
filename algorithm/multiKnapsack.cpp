/**************************************************************** 
 * Description: C++ implementation of multiKnapsack 
 * Author: Alex Li
 * Date: 2023-06-20 10:53:09
 * LastEditTime: 2023-06-20 12:39:18
****************************************************************/
#include <iostream>
using namespace std;

const int MAXN=10000;//定义最大物品数量
const int MAXV=10000;//定义最大背包容量
int N; //物品数量
int V; //背包容量
int Weight[MAXN];  //存储每件物品的重量
int Value[MAXV];   //存储每件物品的价值
int dp[MAXV];      //滚动数组


//滚动数组解决01背包问题
void knapsack(int n){
    for(int i=0;i<=V;i++)dp[i]=0;
    for (int i = 1; i <=n; i++){
        for(int j=V; j>=Weight[i];j--)
           dp[j]=max(dp[j-Weight[i]]+Value[i],dp[j]);
    }
}

int main(){
    //实际物品的重量、价值和数量
    int realWeight[MAXN],realValue[MAXV],realNumber[MAXN];
    int k=0; //k是储存物品展开后的标号
    cin>>N>>V; //输入原始物品数量和背包容量。
    //输入N个物品的重量、价值和数量
    for(int i=1;i<=N;i++)cin>>realWeight[i]>>realValue[i]>>realNumber[i];
    
    /*把物品数量按二进制展开成多个物品
    比如A物品有20个，每个物品价值是3元，展开成如下：
    物品   数量   价值
    A1     1      3
    A2     2      6
    A3     4     12
    A4     8     24
    A5     5     15
    */
    
    for (int i =1; i <=N; i++){
        for (int j =1; j <=realNumber[i]; j<<=1){
            k++;
            Weight[k]=realWeight[i]*j;
            Value[k]=realValue[i]*j;
            realNumber[i]-=j;
        }
        if(realNumber[i]!=0){
        k++;
        Weight[k]=realWeight[i]*realNumber[i];
        Value[k]=realValue[i]*realNumber[i];
        }    
    }
    //经过二进制展开后，物品数量为k，对应每个物品的重量Weight[i]、价值Value[i]
    knapsack(k);
    cout<<dp[V];
}