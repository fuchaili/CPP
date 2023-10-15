/**************************************************************** 
 * Description: C++ implementation of sparse table
 * Author: Alex Li
 * Date: 2023-06-12 19:05:32
 * LastEditTime: 2023-06-12 19:59:53
****************************************************************/
#include <iostream>
using namespace std;

//dp[i][j]  从i开始，长度为2^j的区间max
int main(){
    int   arr[]={3,7,9,6,8,2,0,4,1,5};
    int ans[10][10];
    for (int i = 0; i <10; i++){
        for (int j = i; j <10;j++){
            if(i==j)ans[i][j]=arr[i];
            else ans[i][j]=max(ans[i][j-1],arr[j]);
        }
    }
    int left,right;
    while(cin>>left>>right){
        cout<<ans[left][right]<<endl;
    }
    return 0;
}
//O(n^2+m) n是元素个数，m是查寻次数