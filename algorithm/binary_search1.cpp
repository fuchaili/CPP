#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
	if (right >= left) {
		int mid = left + (right - left) / 2;
		      	if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)   
			return binarySearch(arr, left, mid, x);
		else     
			return binarySearch(arr, mid + 1, right, x);
	}
	return -1;
}

int main(void){
	int n,x,arr[100];
    cin>>n;
    for (int i = 0; i <n; i++){
        cin>>arr[i];
    }
    cin>>x;
	int result = binarySearch(arr, 0, n - 1, x);
	if(result == -1)
		 cout << "Element is not present in array";
	else
		 cout << result;
	return 0;
}
