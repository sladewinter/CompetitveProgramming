//UVa - 441 - Lotto
//Iterative Complete Search
//k < 13 & a,b,c,d,e,f are distinct so 7^7 = 0.8M operations worst case

#include <iostream>
using namespace std;

int main() 
{
	int k;                                   //Problem parameter
	bool first{ true };                     //Blank line b/w cases
	int num[12];
	while( scanf( "%d", &k ), k )
	{
		( !first ) ? printf( "\n" ) : first = false;
		
		for( int i{0}; i < k; ++i )
			scanf( "%d", &num[i] );

		for( int a{ 0 }; a <= k - 6; ++a )        
			for( int b{a + 1}; b <= k - 5; ++b )
				for( int c{b + 1}; c <= k - 4; ++c )
					for( int d{c + 1}; d <= k - 3; ++d )
						for( int e{d + 1}; e <= k - 2; ++e )
							for( int f{e + 1}; f <= k - 1; ++f )
								printf("%d %d %d %d %d %d\n", num[a], num[b], 
									         num[c], num[d], num[e], num[f]);
	}
 	return 0;
}													  