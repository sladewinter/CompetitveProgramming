//UVa - 11100 - The Trip, 2007

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> dim;
	int n;
	bool first{ true };

	while( scanf( "%d", &n ), n )
	{
		(first) ? first = false : printf( "\n" );
		dim.resize(n);
		for( int i{0}; i < n; ++i )
			scanf( "%d", &dim[i] );

		map<int, int> freq;            //Count frequency
		int max_f{0};                 //Max frequency
		int unique{0};               //No of unique sizes
		for( int i{0}; i < n; ++i )
		{
			if( !freq[dim[i]] )
			{
				freq[dim[i]] = 1;
				++unique;
			}
			else
				++freq[dim[i]];

			max_f = max( max_f, freq[dim[i]] );
		}

		//No. of sets needed = max_f, since no bag can be
		//packed into another same sized bag
		dim.resize( max_f * unique ); //Pad with dummy 0s
		sort( dim.begin(), dim.end() );

		//Now vector contains max_f sets each of size unique 
		printf( "%d\n", max_f );

		//Print max_f lines, 1 for each set, avoid printing 0
		for( int i{0}; i < max_f; ++i )
		{
			//Print items of set i, output formatting
			for( int j{0}; j < unique - 1; ++j )
			{
				int bag{ dim[ j * max_f + i] };
				if(bag)
					printf("%d ", bag );
				else
				 	continue;
			}
			printf( "%d\n", dim[ (unique - 1) * max_f + i] );
		}
	}
}  