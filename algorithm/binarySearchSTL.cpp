#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[100]= {4,10,11,30,69,70,96,100};

    int b=binary_search(a,a+9,11);//查找成功，返回1
    cout<<b<<endl;
  int c=binary_search(a,a+9,40);//查找失败，返回0
    cout<<c<<endl;
     int d=lower_bound(a,a+9,10)-a;  // >=
     cout<<d<<endl;
     int e=lower_bound(a,a+9,67)-a;
     cout<<e<<endl;
     int f=upper_bound(a,a+9,10)-a; //>
     cout<<f<<endl;
     int g=upper_bound(a,a+9,69)-a; //>
     cout<<g<<endl;
}

