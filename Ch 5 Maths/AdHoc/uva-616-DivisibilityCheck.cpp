//UVa - 616 - Coconuts, Revisited

#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main()
{
	int num;
	while( scanf( "%d", &num ), num >= 0 )
	{
		--num;
		set<int> div;

		//Fast method to get divisors
		for( int i{2}; i <= (int)sqrt(num) + 1; ++i )
			if ( !(num % i) )
			{
				//Need to keep set sorted in descending
				div.insert(-i);
				div.insert(-(num / i));
			}

		bool solved;

		for( auto &element : div )
		{
			int ppl{ -element };  //Set has -ve elements
			solved = true;
			int temp{ num + 1 };
			for( int i{0}; i < ppl; ++i )     //Simulate
			{
				if( temp % ppl == 1 )
					--temp;
				else
				{
					solved = false;
					break;
				}

				temp -= (temp / ppl);
			}

			if(solved)                     //Passed simulation
				solved = !( temp % ppl ); //Check divisibility

			if(solved)
			{
				printf("%d coconuts, %d people and 1 monkey\n",
								++num, ppl);
				break;
			}
		}
		if( !solved || div.empty() )
			printf("%d coconuts, no solution\n", ++num );
	}
} 