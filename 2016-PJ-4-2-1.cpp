#include <iostream>
using namespace std;
void sort(int a[],int l,int r){
    int i=l,j=r,x=a[(l+r)/2],y;
    while(i<=j){
        while(a[i]<x)i++; 
        while(a[j]>x)j--;
        if(i<=j){
            y=a[i];
            a[i]=a[j];
            a[j]=y;
            i++;
            j--;
        }
    }
    if(i<r)sort(a,i,r);
    if(l<j)sort(a,l,j);
}
int main(){
    int n,b[100];
    cin>>n;
    for (int i = 1; i <=n; i++){
        cin>>b[i];
    }
    sort(b,1,n);
    for (int i = 1; i <=n ; i++){
        cout<<b[i]<<' ';
    }
    
    return 0;
}