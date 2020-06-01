//UVa - 11057 - Exact Sum

#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
	int book[10000];
	int N, M;
	while( scanf( "%d", &N ) != EOF )
	{
		for( int i{0}; i < N; ++i )
			scanf( "%d", &book[i] );

		scanf( "%d", &M );

		sort( book, book + N );
		int beg{ 0 };
		int end{ N - 1 };
		pair<int ,int> books;

		while( beg < end )
		{
			if( book[beg] + book[end] == M )
			{
				books.first = book[beg];
				books.second = book[end];
				++beg; --end;
			}
			else if( book[beg] + book[end] < M )
				++beg;
			else 
				--end;
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n",
				books.first, books.second);
	}
	return 0;
}                           
