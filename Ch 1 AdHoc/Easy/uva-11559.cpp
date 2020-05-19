//UVa - 11559 - Event Planning
#include <iostream>
using namespace std;
int main() 
{
	int N, B, H, W, p, a;             //Problem parameters
	constexpr int INF{ 999999999 };
	int price{ INF };                
	while( scanf( "%d %d %d %d", &N, &B, &H, &W ) != EOF )
	{
		price = INF;
		while( H-- )
		{
			scanf( "%d", &p );
			for( int w{0}; w < W; ++w )
			{
				scanf( "%d", &a );
				if( a >= N && p * N <= B )
					price = min( p, price );
			}
		}
		if( price == INF )
			cout << "stay home\n";
		else
			cout << price * N << '\n';
	}
	return 0;
}													  