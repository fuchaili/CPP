/**************************************************************** 
 * Description:  大数加法
 * Author: Alex Li
 * Date: 2023-07-07 21:45:54
 * LastEditTime: 2023-07-07 21:49:44
****************************************************************/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char a1[101],b1[101];
int a[101],b[101],c[102];
int main(){
    int lena,lenb,lenc,i,j,x;
    scanf("%s",a1);      //输入要相加的两个数字的字符串形式 
    scanf("%s",b1);
    lena=strlen(a1);
    lenb=strlen(b1);
    //反转数组顺序，重新放入a数组，最低位从数组下标1开始
    for(i=0;i<lena;i++) a[lena-i]=a1[i]-48;  
    for(i=0;i<lenb;i++) b[lenb-i]=b1[i]-48;//同上
 
    lenc=1;
    x=0;//x是进位 
    while(lenc<=lena || lenc<=lenb){
        c[lenc]=a[lenc]+b[lenc]+x;
        x=c[lenc]/10;   //进位 
        c[lenc]%=10;     //当前位 
        lenc++;
    }
    c[lenc]=x;
    if(c[lenc]==0) lenc--;
    for(i=lenc;i>=1;i--)cout<<c[i];
return 0;
}