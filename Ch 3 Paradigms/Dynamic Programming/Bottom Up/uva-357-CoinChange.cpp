//Uva- 357 - Let Me Count The Ways

#include <iostream>

using namespace std;
using ll = long long;

int main()
{
	int n;
	ll memo[30001][4];
	int coin[4]{ 5, 10, 25, 50 };

	//If n < 5, only 1 way, i.e. all 1 cents, base case
	for( int i{0}; i < 5; ++i )
		for( int j{0}; j < 4; ++j )
			memo[i][j] = 1;

	//If n >= 5, default 1 way is all 1 cents
	//Then for other 4 coin types, subtract each
    //one by one from n, and add to no. of ways
	//k <= j ensures sequence of coins not repeated
	for( int i{5}; i <= 30000; ++i )
		for( int j{0}; j < 4; ++j )
		{
			memo[i][j] = 1;
			for( int k{0}; k <= j; ++k )
			{
				n = i - coin[k];
				if( n >= 0 )
					memo[i][j] += memo[n][k];
			}
		}
	
	while( scanf("%d", &n) != EOF )
	{
		ll m{ memo[n][3] };

		(m == 1)
		? printf("There is only 1 way to produce %d cents change.\n", n)
		: printf("There are %lld ways to produce %d cents change.\n", m, n);
	}
	return 0;
}

