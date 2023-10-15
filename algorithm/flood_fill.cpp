/**************************************************************** 
 * Description: C++ implementation of Flood Fill
 * Author: Alex Li
 * Date: 2023-06-14 10:57:04
 * LastEditTime: 2023-06-14 11:22:29
****************************************************************/


#include <iostream>
using namespace std;

//Floodfill function
void FloodFill(int screen[8][8],int sr,int sc,int row, int column, int prevC, int newC){
     // Condition for checking out of bounds
    if (sr < 0 || sr >= row || sc < 0 || sc >= column) return;
    if (screen[sr][sc] != prevC)return;
     screen[sr][sc] = newC;
    FloodFill(screen, sr - 1, sc, row, column, prevC, newC); // left
    FloodFill(screen, sr + 1, sc, row, column, prevC, newC); // right
    FloodFill(screen, sr, sc + 1, row, column, prevC, newC); // top
    FloodFill(screen, sr, sc - 1, row, column, prevC, newC); // bottom
}

int main(){
    int screen[8][8]=
            { 
            { 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 1, 1, 1, 1, 1, 0, 0 },
            { 1, 0, 0, 1, 1, 0, 1, 1 },
            { 1, 2, 2, 2, 2, 2, 1, 0 },
            { 1, 1, 1, 2, 2, 0, 1, 0 },
            { 1, 1, 1, 2, 2, 2, 2, 0 },
            { 1, 1, 1, 1, 1, 2, 1, 1 },
            { 1, 1, 1, 1, 2, 2, 2, 1 }
            };
           // Row of the display
          int row=8;
          // Column of the display
          int column=8;
          // Co-ordinate provided by the user
          int x=4;
          int y=4;
          // Current color at that co-ordinate
          int prevColor=screen[x][y];
          // New color will be filled
          int newColor=3;

          FloodFill(screen, x, y, row, column, prevColor, newColor);

          // Printing the updated screen
        for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }
return 0;

}