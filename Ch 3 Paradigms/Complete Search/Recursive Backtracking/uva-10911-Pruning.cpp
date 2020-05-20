//UVa - 10911 - Forming Quiz Teams - Recursive Backtracking with Pruning
//Note: DP solution is available in Dynamic Programming Folder
//Improve by choosing RSB ( mask & -mask ), instead of LSB log2( mask )

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
constexpr int INF{ 999999 };

struct point
{
	int x, y;
};

double dist( point stud1, point stud2 )      //Euclidean distance
{
	return sqrt(pow(stud1.x-stud2.x, 2) + pow(stud1.y-stud2.y, 2));
}

int N;                                   //No of students
point studs[16];						//Store student coordinates
double minimum{ INF };                 //Global minimum for pruning
double optimal( int mask, double curr ) //2nd parameter for pruning
{

	if( curr > minimum)
		return INF;                 //Prune if passed global minimum

	int stud1{ (int)log2( mask ) };         //Leftmost set bit index
	mask &= ~( 1 << stud1 );           

	if( __builtin_popcount(mask) == 1 )    //No of set bits
	{
		int stud2{ (int)log2( mask ) };
		double distance{ dist( studs[stud1], studs[stud2] ) };

		minimum = min( minimum, curr + distance );  //Set global min
		return distance;
	}

	double ans{ INF };
	int temp_mask{ mask };

	while( temp_mask )
	{
		int stud2{ (int)log2( temp_mask ) };
		double distance{ dist( studs[stud1], studs[stud2] ) };
		ans = min( ans, distance
			 + optimal( mask & ~( 1 << stud2 ), curr + distance ) );
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
		minimum = INF;                            //Very important

		//Start with all students unvisited and current distance 0
		printf( "Case %d: %.2lf\n", ++caseNo, optimal( mask, 0 ) );
	}
}