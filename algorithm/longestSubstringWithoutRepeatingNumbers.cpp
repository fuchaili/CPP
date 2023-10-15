#include <iostream>
using namespace std;

int arr[100];

int check(int arr[], int l, int r){
    for (int i = l+1; i <=r ; i++)
        for (int j = l; j < i; j++)
            if (arr[i] == arr[j])
                return 1;
    return 0;
}

int main(){
    int n,res=0;
     cin>>n;
    for (int i = 0; i <n; i++)cin>>arr[i];
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            if (check(arr,j, i) == 0)//检查 i 和 j 之间是否有重复的数字
                res = max(res, i - j + 1);
   cout<<res;
}