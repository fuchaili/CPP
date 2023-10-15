/**************************************************************** 
 * Description: select sort by C++
 * Author: Alex Li
 * Date: 2023-05-31 17:22:04
 * LastEditTime: 2023-06-17 22:09:40
****************************************************************/

#include <iostream>
using namespace std;

int a[1000];

int main (){
  int i = 0, n;
  cin >> n;

  do{
      cin >> a[i];
      i++;
    }while (i < n);
    
  for (int k = 0; k < n - 1; ++k){
      for (int j = k; j < n - 1; ++j){
	       if (a[k] > a[j + 1])swap(a[k],a[j+1]);
	    }
  }
  for (int l = 0; l < n; ++l){
      cout << a[l] <<' ';
    }
  return 0;
}