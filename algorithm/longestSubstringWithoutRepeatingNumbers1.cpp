#include <iostream>
using namespace std;
const int N = 100010;
int a[N], s[N];
int main() {
    int n, ans = 0; 
    cin >> n;
    for (int i = 0; i < n; i++){
      cin >> a[i]; 
     
    }
    for (int i = 0, j = 0; i < n; i++) {
       s[a[i]]++;  //读入并统计数量
        while (s[a[i]] > 1) {
           s[a[j]]--;
           j++;
        }
        // while (s[a[i]] > 1) s[a[j++]]--;等同于上面三行代码
           
        ans = max(ans, i - j + 1);
    }
    cout << ans;
    return 0;
}
