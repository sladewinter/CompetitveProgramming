//UVa - 11173 - Grey Codes

#include <iostream>
using namespace std;

int main() 
{
	int N, n, k;
	scanf( "%d", &N );
	while( N-- )
	{
		scanf( "%d %d", &n, &k );
		printf( "%d\n", k ^ ( k >> 1 ) );
	}
	return 0;
}