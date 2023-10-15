/**************************************************************** 
 * Description: C++ implementation of 0-1 KnapSack pro 
 * Author: Alex Li
 * Date: 2022-04-23 15:40:21
 * LastEditTime: 2023-06-19 21:51:19
****************************************************************/
#include <iostream>
using namespace std;

const int MAXN=10000;  //物品最大数量
const int MAXV=10000;  //背包最大容量
int N;  //储存物品的实际个数
int V;  //背包实际的容量
int dp[MAXN];  ////滚动数组记录统计数据
int weight[MAXN];  //存储各商品的重量
int value[MAXN];  //存储各商品的价值
int main(){
    cin>>N>>V; //输入物品个数和背包容量 
    //l输入每个商品的 重量和价值 
    for(int i=1;i<=N;i++)cin>>weight[i]>>value[i];  
       
    //边界初始化，全局数组默认值也是0，所以为段代码不写也不影响结果。
    for (int i = 0; i <=V; i++)dp[i]=0;    
    
    for (int i = 1; i <=N; i++){    //逐个遍历每个商品
        for (int j = V; j >=weight[i]; j--){//如果i物品容量大于背包容量，for循环就停止，该物品装不进行。
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]); 
            //从背包大数值开始，反向生成动态数组
         }
    }
    cout<<dp[V]<<endl;  //输出结果
    
}
