/**************************************************************** 
 * Description: N-queens problem
 * Author: Alex Li
 * Date: 2023-07-27 18:51:55
 * LastEditTime: 2023-07-27 19:39:54
****************************************************************/
#include <iostream>
using namespace std;

const int N=4;

/* A utility function to print solution */
void printSolution(int board[N][N]){
    for (int i = 0; i < N; i++) {
        for (int k = 0; k<N; k++) {
            cout<<board[i][k];
        }
        cout<<"\n";
    }
}

/* A utility function to check if a queen can be placed onboard[row][column]. 
Note that this function is called when "column" queens are already placed in columns from 0 to col -1. 
So we need to check only left side for attacking queens */
bool isSafe(int board[N][N],int row,int column){
    int i,j;
    /* Check this row on left side */
    for (int i = 0; i < column; i++) {
        if(board[row][i])return false;
    }
    
    /* Check upper diagonal on left side */
    for (int i = row, j=column; i >=0&&j>=0; i--,j--) {
        if(board[i][j])return false;
    }
    
    /* Check lower diagonal on left side */
    for (int i = row, j =column;j>=0&&i<N; i++,j--) {
        if(board[i][j])return false;
    }
    
    return true;
}   

/* A recursive utility function to solve N Queen problem */

bool solveNQUtil(int board[N][N],int column){
    /* base case: If all queens are placed then return true */
      if(column>=N)
      return true;
      
    /* Consider this column and try placing this queen in all rows one by one */
      for(int i=0;i<N;i++){
          /* Check if the queen can be placed on board[i][column] */
          if(isSafe(board,i,column)){
              /* Place this queen in board[i][column] */
              board[i][column]=1;
              /* recur to place rest of the queens */
              if(solveNQUtil(board,column+1))
              return true;
              /* If placing queen in board[i][column] doesn't lead to a solution, then 
               remove queen from board[i][column] */
            board[i][column] = 0; // BACKTRACK 
          }
      }
      /* If the queen cannot be placed in any row in this colum col  then return false */
    return false; 
}

bool solveNQ(){
    int board[N][N]={{0,0,0,0},
                     {0,0,0,0},
                     {0,0,0,0},
                     {0,0,0,0}
                    };
     if(solveNQUtil(board,0)==false){
         cout<<"soution does not exist";
         return false;
     }else{
        printSolution(board);
        return true;
     }               
    
}



int main()
{
    solveNQ();
     return 0;
}