/**************************************************************** 
 * Description: C++ implementation of bucket sort
 * Author: Alex Li
 * Date: 2023-06-09 19:33:41
 * LastEditTime: 2023-07-14 22:57:18
****************************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 用n个桶对数组元素排序
void bucketSort(int arr[], int n){
	//创建n个空桶
	vector<int> b[n];
	//把不同的元素放到相应的桶里，这里以10为间距分桶
	int index;
	for (int i = 0; i < n; i++) {
		index= arr[i]/10; // Index in bucket
		b[index].push_back(arr[i]);
	}
	// 把每个桶里的元素进行排序
	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());
	// 把每个桶的数据放里到原数组里面
	index=0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

/* Driver program to test above function */
int main(){
	int arr[]= {8,13,25,31,35,29,48,3,9,21,43,49};
	int n = sizeof(arr) / sizeof(arr[0]);
	bucketSort(arr, n);
	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)cout << arr[i] << " ";
return 0;
}