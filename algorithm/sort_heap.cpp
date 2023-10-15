/**************************************************************** 
 * Description: mplementation of heap sort
 * Author: Alex Li
 * Date: 2023-06-08 20:56:13
 * LastEditTime: 2023-07-14 18:26:47
****************************************************************/

#include <iostream>
using namespace std;

//把i做为根，进行堆化，N是指数组大小。
//to heapify a subtree rooted with node i, n is size of heap tree
void heapify(int arr[],int N, int i){
    //初始把i做为最为大值标记，initialize largest as root 
    int largest=i;
    //左叶结点为2i+1
    int l=2*i+1;
    //右叶结点为2*i+2
    int r=2*i+2;
    
    //如果左边孩子大，就把左边孩子做为最大值if left child is larger than root 
    if(l<N&&arr[l]>arr[largest]) largest=l;
    //如果右边孩子大，就把右边做为最大值
    if(r<N&&arr[r]>arr[largest]) largest=r;
    //如果最大值不是arr[i]，与最大值交换，然后堆化
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,N,largest);
    }
}

void heapSort(int arr[], int N){
    //建立堆，N/2-1是第一个非叶结点，从它开始堆化
    for (int  i =N/2-1; i >=0; i--)heapify(arr,N,i); 
    // 把每个结点都进行遍历，每次产生出一个最大值
    for (int i =N-1 ; i>0; i--){
        //把最大值放到数组尾部
        swap(arr[0],arr[i]);
        //从堆顶进行重新堆化
        heapify(arr,i,0);
    }

}

void printArray(int arr[],int N){
     for (int i = 0; i < N; i++)cout<<arr[i]<<' ';
     cout<<'\n';
}

//driver function
int main(){
  int  arr[]={14,3,10,8,1,9,2};
  int N=sizeof(arr)/sizeof(arr[0]);
   heapSort(arr,N);
   cout<<"sorted arry is \n";
   printArray(arr,N);

}