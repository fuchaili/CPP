/**************************************************************** 
 * Description:  CrossRiver  过河问题
 * Author: Alex Li
 * Date: 2023-07-02 20:43:56
 * LastEditTime: 2023-07-02 21:14:29
****************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int n,t[10001],sum;

int main(){    
     
        sum = 0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>t[i];
        sort(t+1,t+n);
        while(n > 3){
            sum += min( t[1]+2*t[2]+t[n] , 2*t[1] + t[n-1] + t[n]);
            n -= 2;
        }
        if(n == 3)sum += t[3] + t[1] +t[2];
        if(n == 2)sum +=  t[2];
        cout<<sum;
    
    return 0;
}