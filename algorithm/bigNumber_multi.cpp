/**************************************************************** 
 * Description: 大数乘法
 * Author: Alex Li
 * Date: 2023-07-08 17:32:17
 * LastEditTime: 2023-07-08 17:33:39
****************************************************************/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char a1[101],b1[101];
int a[101],b[101],c[10001];
int main(){
    int lena,lenb,lenc,i,j,x;
    scanf("%s",a1);
    scanf("%s",b1);
    lena=strlen(a1); 
    lenb=strlen(b1);
    for(i=0;i<=lena;i++)a[lena-i]=a1[i]-48;
    for(i=0;i<=lenb;i++)b[lenb-i]=b1[i]-48;
    for(i=1;i<=lena;i++){
        x=0;
        for(j=1;j<=lenb;j++){
            c[i+j-1]=a[i]*b[j]+x+c[i+j-1];
            x=c[i+j-1]/10;
            c[i+j-1] %=10;
        }
        c[i+lenb]=x;
    }
    lenc=lena+lenb;
    while(c[lenc]==0 && lenc>1) lenc --;
    for(i=lenc;i>=1;i--) cout <<c[i];
    cout <<endl;
 return 0;
}