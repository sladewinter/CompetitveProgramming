//UVa - 526 - String Distance and Transform Process

#include <iostream>
#include <cstring>

using namespace std;

int min3( int a, int b, int c )
{
	return min( a, min(b, c) );
}

int main()
{
	char dist[81][81], str1[81], str2[81];
	int m, n;
	bool first{true};
	while( cin.getline(str1, 81) )
	{
		(first) ? first = false : printf( "\n" );
		
		cin.getline(str2, 81);
		m = strlen(str1);
		n = strlen(str2);
		
		//Bottom up DP 
		dist[m][n] = 0;
		
		for( int i{0}; i < m; ++i )
		    dist[i][n] = m - i;
		 
		for( int i{0}; i < n; ++i )
		    dist[m][i] = n - i;

		for( int i{m - 1}; i >= 0; --i )
			for( int j{n - 1}; j >= 0; --j )
			{
				if(str1[i] == str2[j])
					dist[i][j] = dist[i+1][j+1];
				else
					dist[i][j] = 1 + min3(dist[i+1][j],
										dist[i+1][j+1],
										dist[i][j+1]);
			}
		printf( "%d\n", dist[0][0] );
		int in{ 0 };
		int de{ 0 };
		int no{ 0 };
		for( int i{0}, j{0}; i != m || j != n; )
		{
		    if( str1[i] == str2[j] )
		    {
		        ++i; ++j;
		    }
		    else if( dist[i][j] - 1 == dist[i][j+1] && j < n )
		    {
		    	printf( "%d Insert %d,%c\n", ++no, i + 1 + in - de, str2[j] );
		    	++in; ++j;
		    }
		    else if( dist[i][j] - 1 == dist[i+1][j] && i < m )
		    {
		    	printf( "%d Delete %d\n", ++no, i + 1 + in - de );
		    	++i; ++de;
		    }
		    else
		    {
		    	printf( "%d Replace %d,%c\n", ++no, i + 1 + in - de, str2[j] );
		    	++i; ++j;
		    }
		}

	}
	
}  