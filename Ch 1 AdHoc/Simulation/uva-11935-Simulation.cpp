//UVa - 11935 - Through the Desert
//Simulation

#include <iostream>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;
using vii = vector< pair<int, int> >;

vii events;
double maxi;

void simulate()
{
	int curr{ 0 };
	int rate{ 0 };
	int prev{ 0 };
	int leak{ 0 };
	double fuel{ 0 };

	for( auto event : events )
	{
		curr = event.second;
		fuel += ( curr - prev ) * ( rate / 100.0 + leak );
		maxi = max( maxi, fuel );

		switch( event.first )
		{
			default:                       //Fuel consumption
				rate = -event.first;
				break;

			case 0:                        //Leak
				++leak;
				break;

			case 1:                        //Gas
				maxi = max( maxi, fuel );
				fuel = 0;
				break;

			case 2:                        //Mechanic
				leak = 0;
				break;

			case 3:                        //Goal
				break;
		}
		prev = curr;
	}
}

int main() 
{
	int n, d;
	char line[30];
	while( scanf("0 Fuel consumption %d\n", &n), n )
	{
		events.clear();
		events.emplace_back( -n, 0 );

		while(true)
		{
			scanf("%d ", &d);		
			cin.getline(line, 30);

			if( !strncmp( line, "Fuel", 4 ) )
			{
				sscanf(line, "Fuel consumption %d", &n);
				events.emplace_back( -n, d );
			}
			else if( !strncmp( line, "Leak", 4 ) )			
				events.emplace_back( 0, d );
				
			else if( !strncmp( line, "Gas", 3 ) )			
				events.emplace_back( 1, d );
				
			else if( !strncmp( line, "Mechanic", 8 ) )			
				events.emplace_back( 2, d );
				
			else if( !strncmp( line, "Goal", 4 ) )			
			{
				events.emplace_back( 3, d );
				break;
			}
		}
		maxi = 0;
		simulate();
		printf( "%.3lf\n", maxi );
	}
	return 0;
}                           
