//UVa - 10827 - Maximum sum on a torus

#include <iostream>
using namespace std;

int torus[150][150];   //Keeps 4 copies of input
int cuml[75][75];     //Cumulate for each start point
int main()
{
	constexpr int negINF{ -( 1 << 30 ) };
	int tc, N;
	scanf( "%d", &tc );
	while( tc-- )
	{
		scanf( "%d", &N );

		//This runs in O(n^2)
		for( int i{0}; i < N; ++i )
			for( int j{0}; j < N; ++j )
			{
				scanf("%d", &torus[i][j]);

				//For convenience, make 4 copies
				torus[N+i][j] = torus[i][N+j]
							  = torus[N+i][N+j]
							  = torus[i][j];
			}

		int sol{ negINF };
		//Loop through each element as starting point O(n^2)
		for( int i{0}; i < N; ++i )
			for( int j{0}; j < N; ++j )
			{
				//Cumulate for N x N window starting from
				//current element in O(N^2)
				for( int k{0}; k < N; ++k )
					for( int l{0}; l < N; ++l )	
					{
						cuml[k][l] = torus[i+k][j+l];

						if( k > 0 )
							cuml[k][l] += cuml[k-1][l];
						if( l > 0 )
							cuml[k][l] += cuml[k][l-1];
						if( k > 0 && l > 0 )
							cuml[k][l] -= cuml[k-1][l-1];

						//Since each of these are the potential 
						//endpoints, we can track here itself!
						sol = max(sol, cuml[k][l]);
					}
			}
		printf( "%d\n", sol ); 
	}
	return 0;
}