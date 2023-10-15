/**************************************************************** 
 * Description: 用C++实现归并算法，Merge sort in C++
 * Author: Alex Li
 * Date: 2022-02-10 19:55:32
 * LastEditTime: 2023-07-14 20:37:44
****************************************************************/

#include <iostream>
using namespace std;

int arr[100]; //定义主数组
// 合并两个子数组Left_arr和Right_arr到主数组里，
void merge(int arr[], int left, int middle, int right) {
  
  int left_sub = middle - left + 1;
  int right_sub = right - middle;
// 创建两个子数组Left_array和right_array，数组大小分别是left_sub,right_sub;
  int left_array[left_sub], right_array[right_sub];
//把arr数组分以middle为边界，别给到左子数组left_sub和右子数组left_right
  for (int i = 0; i < left_sub; i++)left_array[i] = arr[left + i];
  for (int j = 0; j < right_sub; j++)right_array[j] = arr[middle +1 + j];
  //维护子数组和主数组的当前索引
  int left_index=0, right_index=0, merged_index=left;
  // 在Left和Right数组中挑选最大的元素放入到主数组中,
  while (left_index < left_sub && right_index < right_sub) {
    if (left_array[left_index] <= right_array[right_index]) {
      arr[merged_index] = left_array[left_index];
      left_index++;
    } else {
      arr[merged_index] = right_array[right_index];
      right_index++;
    }
    merged_index++;
  }
   //当Left或者Right的数组元素已经搜索完，将Left或Right的剩余数组元素放入主数组。
  while (left_index < left_sub) {
    arr[merged_index] = left_array[left_index];
    left_index++;
    merged_index++;
  }

  while (right_index < right_sub) {
    arr[merged_index] = right_array[right_index];
    right_index++;
    merged_index++;
  }
}

//把主数组元素分解成两个子元素，排序并合并子数组
void mergeSort(int arr[], int begin, int end) {
  if (begin < end) {
    //middle是把主数组分成两个子数组的点
    int middle = begin + (end - begin) / 2;
    mergeSort(arr, begin, middle);
    mergeSort(arr, middle + 1, end);
    // 合并排好序的子数组，Merge the sorted subarrays
    merge(arr, begin, middle , end);
  }
}

// 打印排好序数组，Print the sorted array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

//主程序
int main() {
  int size;
  cout<<"please input number for array size: ";
  cin>>size;
  cout<<"please input "<<size<<" elements of array:";
  for (int i = 0; i <size; i++)cin>>arr[i];
  mergeSort(arr, 0, size - 1);
  cout << "Sorted array: \n";
  printArray(arr, size);
  return 0;
}