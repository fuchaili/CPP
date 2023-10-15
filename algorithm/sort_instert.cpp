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
            for (int j = k+1; j >0; --j) {
                if(a[j]<a[j-1])swap(a[j],a[j-1]);
                else break;
            }    
        }    
            
    for (int l = 0; l <n ; ++l) {
        cout<<a[l]<<" ";
    }
}