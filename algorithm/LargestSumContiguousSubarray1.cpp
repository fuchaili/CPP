#include <iostream>
using namespace std;

int a[1000];
int maxsequence(int len){
  int maxsum = 0;
  for(int i = 0;i < len;i++){
    int newsum = 0;
    for(int j = i;j<len;j++){
      newsum+=a[j];
      if(newsum > maxsum)
        maxsum = newsum;
    }
  }
  return maxsum;
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i <n; i++)cin>>a[i];
    cout<<maxsequence(n);
  }

