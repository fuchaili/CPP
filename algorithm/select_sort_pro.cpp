/**************************************************************** 
 * Description: select sort by C++
 * Author: Alex Li
 * Date: 2023-05-31 17:22:04
 * LastEditTime: 2023-06-17 22:16:14
****************************************************************/

#include <iostream>
using namespace std;

int arr[1000];

int main (){
  int i = 0,n,min_index;;
  cin >> n;

  do{
      cin >>arr[i];
      i++;
    }while (i < n);
    
  for (int k = 0; k < n - 1; ++k){
     min_index=k;
      for (int j = k+1; j < n; ++j){
	       if (arr[min_index] >arr[j])min_index=j;
	    }
      if(min_index!=k)swap(arr[min_index],arr[k]);
  }

  for (int l = 0; l < n; ++l){
      cout << arr[l] <<' ';
    }
  return 0;
}