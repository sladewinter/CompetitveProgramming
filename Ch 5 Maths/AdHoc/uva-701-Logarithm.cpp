//UVa - 701 - The Archeologists' Dilemma
//Logarithm, Exponentiation, Power
//This is only a partially correct but an accepted soln
//Totally correct solution seems hard for large N

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
	ll N;
	while( scanf("%lld", &N ) != EOF )
	{
		for( int k{(int)log10(N) + 2}; ; ++k )
		{
			double left{ log2(N) + (k * log2(10)) };
			double right{ log2(N+1) + (k * log2(10)) };
			if( floor(right) == ceil(left) )
			{		cout << (ll)floor(right) << '\n';
					break;
			}
		}
	}

	return 0;
}
