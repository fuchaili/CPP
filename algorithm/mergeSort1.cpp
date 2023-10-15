// 用C++实现归并算法，Merge sort in C++
// author:Li,fuchai
// time:2022-7-27

#include <iostream>
using namespace std;

int arr[100]; //定义主数组
void mergeSort(int arr[], int l, int r)
{
    if (l >= r) return;
    int temp[100];
    int mid = l + r >> 1;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (arr[i] <= arr[j]) temp[k ++ ] = arr[i ++ ];
        else temp[k ++ ] = arr[j ++ ];

    while (i <= mid) temp[k ++ ] = arr[i ++ ];
    while (j <= r) temp[k ++ ] = arr[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) arr[i] = temp[j];
}

int main() {
  int size;
  cout<<"please input number for array size: ";
  cin>>size;
  cout<<"please input "<<size<<" elements of array:";
  for (int i = 0; i <size; i++)cin>>arr[i];
  mergeSort(arr, 0, size - 1);
  cout << "Sorted array: \n";
   for (int i = 0; i < size; i++)cout << arr[i] << " ";
  cout << endl;
  return 0;
}