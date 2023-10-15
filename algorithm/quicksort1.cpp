/****************************************************************
C++ implementation of quickSort 
date::2023-3-14 
author: Alex Li 
version:1.5
****************************************************************/
#include <iostream>
using namespace std;
int arr[100];

void quickSort(int arr[], int l, int r){
    if (l >= r) return;

    int i = l, j = r, x = arr[(l + r) >> 1];
    while (i < j){
        while (arr[i] < x)i++;
        while (arr[j] > x)j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    quickSort(arr, l, j), quickSort(arr, j + 1, r);
}

int main(){
   int n;
   cout<<"please input a number for array size: ";
   cin>>n;
   cout<<"please input "<<n<<" elements of array: ";
   for (int i = 0; i < n; i++)cin>>arr[i];
   quickSort(arr,0,n-1);
    for (int i = 0; i <n ; i++){
        cout<<arr[i]<<' ';
    }
    
}