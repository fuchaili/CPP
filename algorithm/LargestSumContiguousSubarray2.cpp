#include <iostream>
using namespace std;

int a[1000];
int maxSubarray(int h, int m)
{
    if (h > m)
        return -1;
    if (h == m)
        return max(a[h], 0);
    int j = (h + m) >> 1;
    int wh = 0, wm = 0;
    int wht = 0, wmt = 0;
    for (int i = j; i >= h; i--) {
        wht += a[i];
        wh = max(wh, wht);
    }
    for (int i = j + 1; i <= m; i++) {
        wmt += a[i];
        wm = max(wm, wmt);
    }
    return max(max(maxSubarray(h, j), maxSubarray(j + 1, m)), wh + wm);
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i <n; i++)cin>>a[i];
    cout<<maxSubarray(0,n-1);
}

