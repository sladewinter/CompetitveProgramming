//UVa - 10660 - Citizen attention offices
//Iterative complete search - Generate all possible combinations 25C5
//Coordinate x, y becomes p = x*5 + y, get back x = p / 5, y = p % 5

#include <iostream>
#include <cstring>
using namespace std;

constexpr int INF{ 999999999 };

int dist( int a, int b)
{
	return abs(a/5 - b/5) + abs(a%5 - b%5);
}

int main()
{
	int t, n;                      //Problem parameters
	int pop[25];                   //Population
	int off[5];                    //Office locations

	scanf("%d", &t);
	while( t-- )
	{
		memset( pop, 0, sizeof(pop) );
		scanf("%d", &n);

		int r, c, p;               //Row, column, population
		while( n-- )
		{
			scanf( "%d %d %d", &r, &c, &p );
			pop[r*5 + c] = p;
		}

		int minimum{INF};

		//Enumerate all 25C5 combinations to choose 5 offices
		for( int of1{0}; of1 < 21; ++of1)
			for( int of2{of1 + 1}; of2 < 22; ++of2)
				for( int of3{of2 + 1}; of3 < 23; ++of3)
					for( int of4{of3 + 1}; of4 < 24; ++of4)
						for( int of5{of4 + 1}; of5 < 25; ++of5)
						{
							int distance{ 0 };
							for( int r{0}; r < 5; ++r )
								for( int c{0}; c < 5; ++c )
								{
									int near{ INF };
									int loc{r*5 + c};

									//Find nearest office
									near = min(near, dist(of1, loc));
									near = min(near, dist(of2, loc));
									near = min(near, dist(of3, loc));
									near = min(near, dist(of4, loc));
									near = min(near, dist(of5, loc));
									distance += near * pop[r*5 + c];
								}
							if( distance < minimum )
							{
								minimum = distance; //Store 5 offices
								off[0] = of1;
								off[1] = of2;
								off[2] = of3;
								off[3] = of4;
								off[4] = of5;
							}
						}
		for( int i{0}; i < 4; ++i )
			cout << off[i] << ' ';
		cout << off[4] << '\n';
	}

}