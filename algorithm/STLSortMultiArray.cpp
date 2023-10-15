/****************************************************************
 * multi array STL sort.
 * author: Alex Li
 * date:  2023-4
 * version: 1.0
****************************************************************/
 
#include <iostream>
using namespace std;
#define R 3
#define C 3
 
void SortFun(int arr[R][C]){
    // One by one sort
    // individual rows.
    for (int i = 0; i < R; i++)
        sort(arr[i], arr[i] + C);
 }
 // Printing the sorted matrix
void Display(int arr[R][C]){
     for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << (arr[i][j]) << " ";
        cout << endl;
    }
}

int main(){
    // Initialize the 2D array
    int arr[3][3]
        = { { 12,11,10 }, { 6, 5, 4 }, { 9, 8, 7 } };
    sort(arr[3][0],arr[3][0]+3);
    // Sort the 2D array using the function
   // SortFun(arr);
    Display(arr);
    return 0;
}
