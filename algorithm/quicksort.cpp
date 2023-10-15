/**************************************************************
C++ implementation of quickSort 
date::2023-3-14
author: ALex Li 
version: 1.0
***************************************************************/

#include <iostream>
using namespace std;
int arr[100];
void quickSort(int array[],int left,int right)
{	int i,j;
	if(left<right){
		i=left;j=right;
		int temp=array[left];
		do{	
			while(array[j]>temp && i<j)
				j--;
			if(i<j){
                array[i]=array[j];
				i++;
			}
            while(array[i]<temp && i<j)
			    i++;
			if(i<j){
                array[j]=array[i];
				j--;
			}
		}while(i<j);
		array[i]=temp;
		
		quickSort(array,left,i-1);
		quickSort(array,i+1,right);
	}
}
int main(){
   int n;
   cout<<"please input a number for array size: ";
   cin>>n;
   cout<<"please input "<<n<<" elements of array: ";
   for (int i = 0; i < n; i++)
   {
       cin>>arr[i];
   }
    quickSort(arr,0,n-1);
    for (int i = 0; i <n ; i++)
    {
        cout<<arr[i]<<' ';
    }
    
}