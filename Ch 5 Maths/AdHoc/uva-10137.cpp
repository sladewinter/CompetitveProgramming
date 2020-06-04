//UVa - 10137 - The Trip

#include <iostream>

using namespace std;

int main()
{
	int n;
	double cost[1000];
	while( scanf("%d", &n), n )
	{
		double avg{ 0 };
		for( int i{0}; i < n; ++i )
		{
			scanf("%lf", &cost[i]);		
			avg += cost[i];
		}
		avg /= n;

		double pos{ 0 };
		double neg{ 0 };
		for( int i{0}; i < n; ++i )
		{
			double v{(long)((avg - cost[i])*100) / 100.0};
			if( v > 0 )
				pos += v;
			if( v < 0 )
				neg -= v;
		}

		printf( "$%.2lf\n", max( pos, neg) );
	}
	return 0;
}
