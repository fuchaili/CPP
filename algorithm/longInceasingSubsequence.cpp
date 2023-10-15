#include <iostream>
using namespace std;

const int Max=1000;
int A[Max],F[Max],N,ans;
int main(){
    cin>>N;
    for (int i =1; i <=N; i++)cin>>A[i];
    
    F[1]=1;
    ans=1;
    for (int i =2; i <=N; i++){
        F[i]=1;
        for (int j = 1; j <=i-1; j++){
            if(A[j]<=A[i]&&F[j]+1>F[i])F[i]=F[j]+1;
        }
        if(F[i]>ans)ans=F[i];
    }
    cout<<ans<<endl;   
}