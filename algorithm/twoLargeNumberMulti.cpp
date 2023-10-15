#include <string>
#include <iostream>
using namespace std;
const int MAXN=1000;
int A[MAXN],B[MAXN],Ans[MAXN],Len_A,Len_B,Len_Ans;
void Read(int *A,int &Len){
    string cur;
    cin>>cur;
    Len=cur.length();
    for (int i = 0; i < Len; ++i) {
        A[i]=cur[i]-48;
        }
    reverse(A,A+Len);
}
int main() {
        Read(A,Len_A);
        Read(B,Len_B);
        Len_Ans=Len_A+Len_B-1;
    for (int i = 0; i <Len_A ; ++i) {
        for (int j = 0; j <Len_B ; ++j) {
            Ans[i+j]+=A[i]*B[j];
        }
    }
    for (int i = 0; i <Len_Ans ; ++i) {
        if(Ans[i]>9)Ans[i+1]+=Ans[i]/10,Ans[i]%=10;
    }
    while (Ans[Len_Ans])Len_Ans++;
    for (int k = Len_Ans-1; k >=0 ; --k)  cout<<Ans[k];
    return 0;
}