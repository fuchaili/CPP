#include <iostream>
using namespace std;

int a[1000];
int maxsequence(int len){

  int maxsum = a[0];
  int maxnew = a[0];
  for(int i = 1;i < len;i++){
    if(maxnew <= 0)
      maxnew = a[i];
    else
      maxnew += a[i];

    if(maxnew > maxsum)
      maxsum = maxnew;
  }
  return maxsum;
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i <n; i++)cin>>a[i];
    cout<<maxsequence(n);
    

}

