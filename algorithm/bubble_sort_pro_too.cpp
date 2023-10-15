/**************************************************************** 
 * Description: bubble sort pro by C++
 * Author: Alex Li
 * Date: 2023-06-17 23:11:39
 * LastEditTime: 2023-06-19 17:47:17
****************************************************************/


#include <iostream>
#include <cmath>
using namespace std;
 int a[1000];
int main() {
    int j=1 ,n,k,flag;
    cin>>n; 
    do {
        cin >> a[j];
        j++;
        } while (j <=n);
    flag=n;
    /*用flag标识最后一次交换的位置，下次循环的时候，只需要循环到flag的位置，
    因为在在最后一次交换后面的元素都是已经排好序列的。*/
    while(flag>1){
        k=flag;
        flag=1;
       for (int i = 1; i <=k-1; i++){
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
             flag=i+1;
           }
       
       }
    }    
    for (int i = 1; i <=n; i++){
        cout<<a[i];
    }
    
return 0;    
}