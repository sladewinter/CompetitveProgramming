//UVa - 11172 - Relational Operator
#include <iostream>
using namespace std;
int main() 
{
	int a, b, t;
	scanf( "%d", &t );
	while( t-- )
	{
		scanf( "%d %d", &a, &b );
		printf( "%c\n", ( a == b ) ? '=' : ( a > b ? '>' : '<' ) );
	}
	
	return 0;
}													  