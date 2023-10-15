#include <iostream>
#include <iomanip>
using namespace std;
const int maxn=1025;
int board[maxn][maxn], tile; /* tile为纸片编号 */
bool visited[maxn][maxn]={0};
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


void princolumnhessboard( int b[maxn][maxn], int n )
{
	int i, j;
	for ( i =1; i <= n; i++ )
	{
		for ( j =1; j <= n; j++ )
		{	cout <<b[i][j];
			// setw(3) output three characters field width.
		if(j<n)cout<<' ';
		}
		cout << endl;
	}
}


int main(){
	int size,n, x, y;
	//cout << "input size(4/8/16/64):" << endl;
	cin >> n;
	size=1<<n;
	//cout << "input the position of special block(x,y):" << endl;
	cin >> x >> y;
	board[x][y] = 0;
	
	chessboard( 1, 1, x, y, size );
    int t=1;
	for (int i =1; i <=size-1 ; i++){
		for (int j =1; j <=size-1;j++){
		if(board[i][j]==board[i][j+1]&&board[i][j+1]==board[i+1][j]&&!visited[i][j]&&!visited[i][j+1]&&!visited[i+1][j]) 
		   {
			board[i][j]=t;
			visited[i][j]=1;
			board[i][j+1]=t;
			visited[i][j+1]=1;
			board[i+1][j]=t;
			visited[i+1][j]=1;
			t++;
			continue;
		   }
		if(board[i][j]==board[i][j+1]&&board[i][j+1]==board[i+1][j+1]&&!visited[i][j]&&!visited[i+1][j+1]&&!visited[i][j+1]) 
		   {
			board[i][j]=t;
			visited[i][j]=1;
			board[i][j+1]=t;
			visited[i][j+1]=1;
			board[i+1][j+1]=t;
			visited[i+1][j+1]=1;
			t++;
			continue;
		   }
        if(board[i][j]==board[i+1][j+1]&&board[i+1][j+1]==board[i+1][j]&&!visited[i][j]&&!visited[i+1][j]&&!visited[i+1][j+1]) 
		   {
			board[i][j]=t;
			visited[i][j]=1;
			board[i+1][j]=t;
			visited[i+1][j]=1;
			board[i+1][j+1]=t;
			visited[i+1][j+1]=1;
			t++;
			continue;
		   }
		  if(board[i+1][j]==board[i+1][j+1]&&board[i+1][j+1]==board[i][j+1]&&!visited[i+1][j]&&!visited[i+1][j+1]&&!visited[i][j+1]) 
		   {
			board[i+1][j]=t;
			visited[i+1][j]=1;
			board[i+1][j+1]=t;
			visited[i+1][j+1]=1;
			board[i][j+1]=t;
			visited[i][j+1]=1;
			t++;
			continue;
		   }  
		   
		}
	}
	
	princolumnhessboard( board, size );
}
 