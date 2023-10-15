/****************************************************************
 * C++ implementation for counting Sort
 * date: 2023-3-21 
 * author : Alex Li
 * mail: lifuchai@hotmail.com
 * ****************************************************************/



#include <iostream>
using namespace std;

void countSort(int array[], int size) {
   int output[10];
  int count[10];
  int max = array[0];

  // 寻找最大的元素 Find the largest element of the array
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // 分配一个长度为Max+1的数组存储计数，并初始化为0
  //Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // 统计每个数的个数，Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // 统计计数的累计值，Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }
  //将元素按顺序放到output数组里
  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }
//将结果放回原数组array
  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

//主函数
// Driver code
int main() {
  int array[] = {4, 2, 2, 8, 3, 3, 1};
  int n = sizeof(array) / sizeof(array[0]);
  countSort(array, n);
  printArray(array, n);
}