/**************************************************************** 
 * Description: C++ implementation of Radix Sort 
 * Author: Alex Li
 * Date: 2023-06-09 15:59:05
 * LastEditTime: 2023-07-15 09:08:04
****************************************************************/

#include <iostream>
using namespace std;

//取得数组最大值 
int getMax(int arr[],int n){
    int mx=arr[0];
    for (int i = 1; i <n; i++){
       if(arr[i]>mx)mx=arr[i];
    }
    return mx;
}

//计数排序，根据某一位exp
//counting sort of arr according to the digit representated by exp.
void countSort(int arr[],int n, int exp){
    
    int output[n];//准备输出的数组output array
    int i,count[10]={0};

//用count[]存储计数
//store count of occurrences in count[]
    for (i=0;i<n;i++)count[(arr[i]/exp)%10]++;
//让count[]数组存储实际在输出组output[]中的位置
//change count[i] so that count[i] now contains actual position of this digit in output[]
    for ( i =1; i <10; i++)count[i]+=count[i-1];
//生成输出数组output[]
//build the output array
    for (i=n-1;i >=0; i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
//复制output[]数组到arr[]数组，arr[]数组就是按当前某位排序的数组
//copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit.
    for ( i = 0; i <n; i++)arr[i]=output[i];
    
}

//the main function to that sorts arr[] of size n using Radix Sort
void radixSort(int arr[],int n){

//find the maximum number to know number of digits
    int m=getMax(arr,n);
//每一位按计数排序    
//do counting sort for every digit. note that instead of passing digit number 
//exp是10的次方，从10^0次方开始，调用计数排序按每一位排序
//exp is passed. exp is 10^i, where i is current digit number
    for (int exp =1; m/exp>0; exp*=10){
        countSort(arr,n,exp);
    }
}
//打印数组
//print an array
void print(int arr[],int n){
    for (int i=0;i<n ;i++)cout<<arr[i]<<' ';
}

//主函数
//driver code 
int main(){
    int arr[]={180,35,75,90,802,24,2,86};
    int n=sizeof(arr)/sizeof(arr[0]);

//function call
    radixSort(arr,n);
    print(arr,n);
    return 0;
}

