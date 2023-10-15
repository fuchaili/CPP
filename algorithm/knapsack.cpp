/**************************************************************** 
 * Description: C++ implementation of Knapsack Brute force
 * Author: Alex Li
 * Date: 2023-06-20 06:27:38
 * LastEditTime: 2023-06-20 06:33:55
****************************************************************/
#include<iostream>
using namespace std;
const int N = 100;
int n, w;
int W[N], V[N];

//从第i个物品开始挑选总重小于j的部分
int solve(int i, int j){
	int result;
	if (i == n)//已经没有剩余的物品了
	    result= 0;
	else if (j < W[i]) 
		result = solve(i + 1, j);//如果i物品的重量大于背包剩余重量，就选下一个物品试试
	else	{
        //一个物品选还是不选都试一下，选最大的返回。
		result = max(solve(i + 1, j), solve(i + 1, j - W[i]) + V[i]);
	}
	return result;
}
int main()
{
	cin >> n >> w;
	for (int i = 0; i < n; i++)
		cin >> W[i]>>V[i];
		cout << solve(0, w) << endl;
	return 0;
}
