/**************************************************************** 
 * Description: bubble sort by C++
 * Author: Alex Li
 * Date: 2023-06-17 23:11:39
 * LastEditTime: 2023-06-17 23:22:19
****************************************************************/


#include <iostream>
using namespace std;
 int a[1000];
int main() {
    bool swapped;
    int i = 0,n;
    cin>>n; 
    do {
        cin >> a[i];
        i++;
        } while (i <n);
        
        for (int k = 0; k <n-1 ; ++k) {
            swapped=false;
            for (int j = 0; j <n-1-k; ++j) {
                if(a[j]>a[j+1]){
                   swap(a[j],a[j+1]);
                   swapped=true;
                }
            }
            if(swapped==false)break;
            //如果没有发生过交换，中断循环，说明数组已经是有序数组
            //if no two elements were swapped,  then break.
        }
        
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<' ';
    }
return 0;    
}