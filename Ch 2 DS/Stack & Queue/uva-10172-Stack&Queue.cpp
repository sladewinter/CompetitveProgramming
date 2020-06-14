//UVa - 10172 - The Lonesome Cargo
//Simulation using Stack and Queue

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
using qi = queue<int>;
 
int main() 
{
	vector<qi> station;
	stack<int> carrier;

	int SET, N, S, Q, Qi;
	scanf( "%d", &SET );
	while( SET-- )
	{
		scanf( "%d %d %d", &N, &S, &Q );
		station.assign(N, qi());

		int des;
		int cargo{ 0 };
		for( int i{0}; i < N; ++i )
		{
			scanf( "%d", &Qi );
			cargo += Qi;
			for( int j{0}; j < Qi; ++j )
			{
				scanf( "%d", &des );
				station[i].push(--des);
			}
		}

		int time{ 0 };
		int curr{ 0 };
		while( cargo )
		{
			//Unloading
			while( !carrier.empty() )
			{
				if( carrier.top() == curr )
				{
					--cargo;
					++time;
					carrier.pop();
				}
				else if( station[curr].size() < Q )
				{
					station[curr].push( carrier.top() );
					++time;
					carrier.pop();
				}
				else
					break;	
			}

			//Loading
			while( carrier.size() < S && !station[curr].empty() )
			{
				carrier.push( station[curr].front() );
				station[curr].pop();
				++time;
			}

			if( cargo )
			{
				curr = (curr + 1) % N;
				time += 2;
			}
		}

		printf( "%d\n", time );
	}
	return 0;
}                           
