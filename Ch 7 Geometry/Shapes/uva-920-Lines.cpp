//UVa - 920 - Sunny Mountains

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct cord                         //Coordinates
{
	int x, y;
};

int main()
{
	cord co[100];                   //Coordinates
	int C;                          //No of test cases
	scanf( "%d", &C );
	while( C-- )
	{
		int N;                     //No of coordinates
		scanf( "%d", &N );

		for( int i{0}; i < N; ++i )
			scanf( "%d %d", &co[i].x, &co[i].y );

		sort( co, co + N, [](cord a, cord b) 
			{ return a.x < b.x; } );

		int base{ N - 1 }; 
		int peak{ N - 2 };
		int hi{ N - 1 };        //Highest peak yet 
		double size{ 0 };      //The output

		while( true )         //Traverse left to right
		{
			if( co[peak].y > co[hi].y )
			{
				int ht{ co[peak].y - co[base].y };
				int wd{ co[base].x - co[peak].x };

				double cropped_ht{ co[peak].y - co[hi].y };
				double cropped_wd{ wd * cropped_ht / ht };
			
				size += hypot( cropped_ht, cropped_wd );
				hi = peak;   
			}

			base -= 1;
			peak -= 1;
			if( base < 0 )
				break;
		}
		printf( "%.2lf\n", size );
	}
	return 0;
} 
