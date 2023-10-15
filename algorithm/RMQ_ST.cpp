/**************************************************************** 
 * Description: C++ implementation of RMQ by ST
 * Author: Alex Li
 * Date: 2023-06-13 19:20:56
 * LastEditTime: 2023-06-13 19:37:51
****************************************************************/

#include <iostream>
#include<cmath>
using namespace std;
int F[10][4];

void createST(int *a,int n){
    for(int i=0;i<n;i++)F[i][0]=a[i];
    int k=log2(n);
    for(int j=1;j<=k;j++){
        for(int i=0;i<=n-(1<<j);i++)
            F[i][j]=max(F[i][j-1],F[i+(1<<(j-1))][j-1]);
    }
}

int queryST(int l,int r){
    int k=log2(r-l+1);
    return max(F[l][k],F[r-(1<<k)+1][k]);
}

int main(){
    int arr[10]={3,7,1,6,8,2,0,4,5,9};
    createST(arr,10);
    int l,r;
    cin>>l>>r;
    cout<<queryST(l,r);
}