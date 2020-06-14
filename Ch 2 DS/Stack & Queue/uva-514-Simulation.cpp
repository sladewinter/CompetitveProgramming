//UVa - 514 - Rails
//Simulation using Stack

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() 
{
	int order[1000];
	int N;
	while( scanf("%d", &N), N )
	{
		while( scanf("%d", &order[0]), order[0] )
		{
			for( int i{1}; i < N; ++i )
				scanf("%d", &order[i]);

			int coach{1};
			bool pos{true};

			stack<int> station;
			station.push(0);

			for( int i{ 0 }; i < N; ++i )
			{
				while( coach <= order[i] )
					station.push( coach++ );

				if( station.top() != order[i] )
				{
					pos = false;
					break;
				}
				
				station.pop();
			}
			
			pos ? printf( "Yes\n" ) : printf( "No\n" );
		}
		printf( "\n" );
	}
	return 0;
}                           
