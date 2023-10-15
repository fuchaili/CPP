/**************************************************************** 
 * Description: C++ implementation of gray code
 * Author: Alex Li
 * Date: 2023-04-25 21:12:31
 * LastEditTime: 2023-06-10 17:09:49
****************************************************************/

#include <stdio.h>
int main(){
	
	int bound = 1, m, n, b, p, gr[15];
	//由键盘输入二进制数的位数n(n<16)，再输入一个十进制数 m(0≤m<2n)，
	printf( "input n,m\n" );
	scanf( "%d%d", &n, &m );
	for (int i = 1; i <= n; i++ )
		bound = bound*2;
	if ( m < 0 || m >= bound ){
		printf( "Data error!\n" );
		return 0;
	}
	b = 1;
	for ( int i = 1; i <= n; i++ ){
		p = 0; 
        b = b * 2;
		for ( int j=0; j <= m; j++ )
			if ( (j%b-(b/2))==0 )
				p = 1 - p;
		gr[i] = p;
	}
	for ( int i = n; i>=1;i--)
		printf( "%1d", gr[i] );  
	printf( "\n" );
}