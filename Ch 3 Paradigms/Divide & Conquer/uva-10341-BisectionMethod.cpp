//UVa - 10341 - Solve It
//Bisection Method

#include <iostream>
#include <cmath>

using namespace std;

int p, q, r, s, t, u;
double fun( double x )
{
	return p*exp(-x) + q*sin(x) + r*cos(x)
		 + s*tan(x)  + t*x*x    + u;
}

int main() 
{
	constexpr double EPS{ 1e-9 };

	while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u) != EOF)
	{
		double lo{ 0 };
		double hi{ 1 };

		if( fun(hi) * fun(lo) > 0 )
		{
			printf( "No solution\n" );
			continue;
		}

		while( hi - lo > EPS )     //Bisection method
		{
			double mid{ ( lo + hi ) / 2 };

			if( fun(lo) * fun(mid) <= 0 )
				hi = mid;
			else
				lo = mid;
		}
		printf( "%.4lf\n", (hi + lo) / 2 );
	}
	return 0;
}                           
