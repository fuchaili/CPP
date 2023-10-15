// C++ 二分法查找
#include <iostream>
using namespace std;

// 递归函数实现二分法查找,返回查找值x在数组中的位置，如果没找到返回-1
int binarySearch(int arr[], int left, int right, int x)
{
	if (right >= left) {
		int mid = left + (right - left) / 2;
		     //检查是否等于mid
        	if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)   // 如果x小于mid，哪就是左边子数组中找
			return binarySearch(arr, left, mid, x);
		else     //如果x大于mid，哪就是右边的子数组里找
			return binarySearch(arr, mid + 1, right, x);
	}
	return -1;
}

int main(void)
{
	int n,x,arr[100];
    cin>>n;
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
    }
    cin>>x;
	int result = binarySearch(arr, 0, n - 1, x);
	if(result == -1)
		 cout << "Element is not present in array";
	else
		 cout << "Element is present at index " << result;
	return 0;
}
