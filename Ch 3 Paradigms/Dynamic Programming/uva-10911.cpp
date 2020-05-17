//UVa - 10911 - Forming Quiz Teams - Top Down DP with bitmasking

//Note: We can definitely improve time by keeping a global minimum,
//and pruning when optimal( mask ) surpasses global minimum, we have
//to pass another parameter curr_dist to optimal( mask )

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
constexpr int INF{ 999999 };

struct point
{
	int x, y;
};

double dist( point stud1, point stud2 )
{
	return sqrt(pow(stud1.x-stud2.x, 2) + pow(stud1.y-stud2.y, 2));
}

int N;
point studs[16];
double memo[65536];
double optimal( int mask )
{
	double &ans{ memo[mask] };
	if( ans != -1 )
		return ans;

	int stud1{ (int)log2( mask ) };
	mask &= ~( 1 << stud1 );

	if( __builtin_popcount(mask) == 1 )
	{
		int stud2{ (int)log2( mask ) };
		return ( ans = dist( studs[stud1], studs[stud2] ) );
	}

	ans = INF;

	int temp_mask{ mask };

	while( temp_mask )
	{
		int stud2{ (int)log2( temp_mask ) };
		ans = min( ans, dist( studs[stud1], studs[stud2] ) 
				     + optimal( mask & ~( 1 << stud2 ) ) );
		temp_mask &= ~( 1 << stud2 );
	}
	return ans;
}

int main()
{
	string stud;
	int caseNo{ 0 };
	while( scanf("%d", &N), N )
	{
		for( int i{0}; i < 2 * N; ++i )
			cin >> stud >> studs[i].x >> studs[i].y;

		int mask{ (1 << 2 * N) - 1 };

		fill( memo, memo + mask + 1, -1 );
		printf( "Case %d: %.2lf\n", ++caseNo, optimal( mask ) );
	}
}