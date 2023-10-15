#include <iostream>
#include <iomanip>
using namespace std;
int board[65][65], tile; /* tile为纸片编号 */
void chessboard( int row, int column, int x, int y, int size ){
/* x,y依次为特殊方格的行、列号 */
/* row, column为整个大方格的起始位置*/
	int t,s;
	if ( size == 1 )return ;
		
		t = ++tile;
		s = size / 2;
	// upper left square
	if ( x<row+s&& y<column+s )
		chessboard( row, column, x, y, s );
	else{
		board[row + s -1][column + s -1] = t;
		chessboard(row,column,row+s-1,column+s-1,s);
    }
	// upper right square
	if ( x < row + s && y >= column + s )
		chessboard( row, column + s, x, y, s );
	else{
		board[row + s -1][column + s] = t;
		chessboard(row,column+s,row+s-1,column+s,s);
	}
	//down left square
	if ( x >= row + s && y < column + s )
		chessboard( row + s, column, x, y, s );
	else{
		board[row + s][column + s -1] = t;
		chessboard(row+s,column,row+s,column+s-1,s);
	}
	//down right square
	if ( x >= row + s && y >= column + s )
		chessboard( row + s, column + s, x, y, s );
	else{ 
        board[row + s][column + s] = t;
	      chessboard(row+s,column+s,row+s,column+s,s); }
}


void princolumnhessboard( int b[][65], int n )
{
	int i, j;
	for ( i =1; i <= n; i++ )
	{
		for ( j =1; j <= n; j++ )
			cout << setw( 3 ) << b[i][j];
			// setw(3) output three characters field width.
		cout << endl;
	}
}


int main(){
	int size, x, y;
	cout << "input size(4/8/16/64):" << endl;
	cin >> size;
	cout << "input the position of special block(x,y):" << endl;
	cin >> x >> y;
	board[x][y] = -1;
	
	chessboard( 1, 1, x, y, size );
	princolumnhessboard( board, size );
}