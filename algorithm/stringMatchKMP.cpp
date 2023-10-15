#include <iostream>

using namespace std;

const int N = 100010, M = 10010; //N为主串长度，M模式串长度

int n, m;
int nex[M]; //next[]数组，避免和头文件next冲突
char s[N], p[M];  //s为主串， p为模式串

int main(){
    cin >> n >> (s+1)>> m >>(p+1);  //下标从1开始,n是s主串实际长度，m是p模式串实际长度

    //求next[]数组
    for(int i = 2, j = 0; i <= m; i++){
        while(j && p[i] != p[j+1]) j = nex[j];
        if(p[i] == p[j+1]) j++;
        nex[i] = j;
    }
    //匹配操作
    for(int i = 1, j = 0; i <= n; i++)
    {
        while(j && s[i] != p[j+1]) j = nex[j];
        if(s[i] == p[j+1]) j++;
        if(j == m)  //满足匹配条件，打印开头下标, 从0开始
        {
            //匹配完成后的具体操作
            //如：输出以0开始的匹配子串的首字母下标
            printf("%d ", i - m); //(若从1开始，加1)
            j = nex[j];            //再次继续匹配
        }
    }

    return 0;
}

