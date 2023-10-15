#include <string>
#include <iostream>
using namespace std;
const int MaxLen=110;
int main(){
    char a1[MaxLen],c1[MaxLen];
    int a[MaxLen],c[MaxLen],lena,x=0,lenc,b;
    memset(a,0, sizeof(a));
    memset(c,0, sizeof(c));
    cin>>a1>>b;

    lena=strlen(a1);
    for (int i = 0; i <lena; ++i) a[i]=a1[i]-'0';
    for (int i=0; i <lena ; ++i) {
        c[i]=(x*10+a[i])/b;
        x=(x*10+a[i])%b;
    }

    for (int k =0; k <lena ; ++k) {
        if(c[k]!=0){
            for (int j =k ; j< lena; j++){
                cout<<c[j];
            }
        break;
        }
    }
cout<<" ";
cout<<x;
}