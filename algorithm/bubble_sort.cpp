/****************************************************************
 * bubble sort by C++ version
 * author : ALex Li
 * date : 2023-5
 * verston: 1.5
****************************************************************/

#include <iostream>
using namespace std;
int main() {
    int a[1000] = {0};
    int i = 0,n;
    cin>>n; 
    do {
        cin >> a[i];
        i++;
        } while (i <n);
        
        for (int k = 0; k <n-1 ; ++k) {
            for (int j = 0; j <n-1-k; ++j) {
                if(a[j]>a[j+1]){
                   swap(a[j],a[j+1]);
                }
            }
        }
        
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<' ';
    }
return 0;    
}