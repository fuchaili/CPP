#include <iostream>
using namespace std;

int brute_force(const char *s, int n, const char *t,int m){
    //扫描文本串的每一位
    for(int i = 0; i<n; i++){
        bool flag = true;
        //用当前的第i位和模式串向后比较
        for(int j = 0; j<m; j++){
            if(s[i + j] == t[j]) continue;
            flag = false;
            break;
        }
        if(flag) return i;  //匹配位置，从0起始；
    }
    return -1;
}


int main(){
    char c1,c2,s[100],t[10];
    int i=0,j=0;
    while((c1=getchar())!='\n'){
        s[i]=c1;
	 i++;
	}
     while((c2=getchar())!='\n'){
        t[j]=c2;
	 j++;
	}
    
    cout<<brute_force(s,i,t,j);
    
}
