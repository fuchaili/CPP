#include <cstdio>
#include <algorithm>
using namespace std;

int a[100]={0},v[100]={0};
int main(){
    int n,r,sum=0;
    scanf("%d%d",&n,&r);
    for (int i = 0; i <n; i++)
            scanf("%d",&a[i]);
    
    sort(a,a+n);
    for (int i = 0; i < n; i++)
    {
        sort(v,v+r);
        sum+=v[0]+a[i];
        v[0]+=a[i];
    }
    printf("%d",sum);
}