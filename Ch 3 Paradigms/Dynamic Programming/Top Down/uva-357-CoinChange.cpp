//Uva- 357 - Let Me Count The Ways

#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;

ll memo[30001][4];
int coin[4]{ 5, 10, 25, 50 };

//Largest stores index of largest denomination
ll coinChange( int n, int largest )
{
	ll &m{ memo[n][largest] };
	if( m != -1 )
		return m;

	m = 1;    //1 way with all ones

	//Do this to prevent repitition
	for( int i{largest}; i >= 0; --i )
		if( n - coin[i] >= 0 )
			m += coinChange(n - coin[i], i);

	return m;
}

int main()
{
	int n;
	memset(memo, -1, sizeof(memo));
	while( scanf("%d", &n) != EOF )
	{
		ll m{ coinChange(n, 3) };
		(m == 1)
		? printf("There is only 1 way to produce %d cents change.\n", n)
		: printf("There are %lld ways to produce %d cents change.\n", m, n);
	}
	return 0;
}

