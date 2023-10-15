/**************************************************************** 
 * Description: C++ implementation of RMQ by emuerations
 * Author: Alex Li
 * Date: 2023-06-13 15:33:36
 * LastEditTime: 2023-06-13 15:42:13
****************************************************************/
#include <iostream>
#include <limits>
using namespace std;

int main(){
    int arr[]={4,9,0,1,2,5,6,3,8,7};
    int answer,left,right;
    while(cin>>left>>right) {
        answer=INT_MIN;  //initialize answer every query
        for (int i =left; i<=right; i++)answer=max(answer,arr[i]);
            cout<<answer<<endl;
    }
}
