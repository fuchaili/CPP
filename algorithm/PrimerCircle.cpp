/**************************************************************** 
 * Description: 
 * Author: Alex Li
 * Date: 2023-07-27 18:36:00
 * LastEditTime: 2023-07-27 18:36:04
****************************************************************/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
bool  b[21]={0};
int total=0,a[21]={0};
void search(int);
void print();
bool isPrimeNumber(int,int);
int n;
int main(){
    cout<<"please input a number: ";
    cin>>n;
    search(1);
    cout<<"total method = "<<total<<endl;   
}

void search(int t){
    int i;
    for ( i = 1; i <=n; i++){
        if(a[1]>1) break;
        if(isPrimeNumber(a[t-1],i) && (!b[i])){
        a[t]=i;
        b[i]=1;
        if(t==n ){
            if(isPrimeNumber(a[n],a[1]))
            print();
            }
        else search(t+1);
        b[i]=0;
        
        }
    }
}
    void print(){
        total++;
        cout<<"<"<<total<<">";
        for (int j =1; j<= n; j++){
            cout<<a[j]<<" ";
        }
        cout<<endl;
    }

    bool isPrimeNumber(int x,int y){
        int k=2,i=x+y;
        while(k<=sqrt(i)&&i%k!=0)k++;
        if(k>sqrt(i))return 1;
        else return 0;
    }