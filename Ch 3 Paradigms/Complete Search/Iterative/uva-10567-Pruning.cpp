//UVa - 10567 - Helping Fill Bates
//Iterative Complete Search with Pruning

#include <iostream>
#include <cstring>

using namespace std;

int main() 
{
	char S[1000001];
	scanf( "%s", S );
	int len{ (int)strlen(S) };

	int Q;
	scanf( "%d", &Q );
	char SS[101];

	while( Q-- )
	{
		scanf( "%s", SS );
		int slen{ (int)strlen(SS) };

		bool pos{ true };
		int curr{ 0 };
		int beg{ 1000000 };
		int end{ 0 };
		for( int i{0}; i < slen && pos; ++i, ++curr )
		{
			while( curr < len && S[curr] != SS[i] )
				++curr;

			if( curr == len )
				pos = false;            //Prune early

			beg = min( beg, curr );
			end = max( end, curr );
		}
		pos ? printf( "Matched %d %d\n", beg, end )
			: printf( "Not matched\n" );

	}
	
	return 0;
}                           
