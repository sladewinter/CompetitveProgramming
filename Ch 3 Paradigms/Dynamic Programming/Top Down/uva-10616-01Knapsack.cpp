//Uva- 10616 - Divisible Group Sums

#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;

int N, Q, D, M;
int arr[200];
ll memo[200][20][10];       //Index,Sum % 20,#Items picked 

ll knapsack( int idx, int sum, int m )
{
	if( idx + M - m > N )   //Impossible to collect M items
		return 0;

	if( m == M )            //Collected all M items
		return sum == 0;

	ll &comb{ memo[idx][sum][m] };    //Memoization
	if( comb != -1 )
		return comb;

	comb = 0;

	//To guarantee that modulo is always +ve
	int rem{ ( ( (sum + arr[idx]) % D ) + D ) % D };

	//Taking item arr[idx]
	comb += knapsack( idx + 1, rem, m + 1 );

	//Not taking item arr[idx]
	comb += knapsack( idx + 1, sum, m );
	return comb;
}

int main()
{
	int setNo{ 0 };
	while( scanf("%d %d", &N, &Q ), N )
	{
		printf( "SET %d:\n", ++setNo );
		for( int i{0}; i < N; ++i )
			scanf( "%d", &arr[i] );

		int Qno{ 0 };
		while( Q-- )
		{
			memset(memo, -1, sizeof(memo));
			scanf( "%d %d", &D, &M );	
			printf("QUERY %d: %lld\n",++Qno,knapsack(0, 0, 0));		
		}
	}
	return 0;
}

