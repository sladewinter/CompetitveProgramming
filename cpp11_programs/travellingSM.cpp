#include <iostream>
#include <cstring>
using namespace std;
int n, bitmask;
int dist[5][5];
int memo[5][32];

int tsp( int pos, int mask )
{
    int &ans{ memo[pos][mask] };
    
    if( ans != -1 )
        return ans;

    if( mask == 0 )
        ans = dist[pos][0];
        
    else
    {
        ans = 99999;
        int m = mask;
        while( m )
        {
            int LSone = m & (-m);
            int i = __builtin_ctz(LSone) + 1;
            ans = min( ans, dist[pos][i] + tsp( i, mask ^ LSone ) );
            m -= LSone;
        }
    }       
    return ans;
}

int main()
{
    memset( memo, -1, sizeof( memo ) );
    while( scanf( "%d", &n ) != EOF )
    {
        for( int i{0}; i < n; ++i )
            for( int j{0}; j < n; ++j )
                scanf( "%d", &dist[i][j] );
                
        printf( "%d\n", tsp( 0, ( 1 << (n - 1) ) - 1 ) );
    }
    return 0;
}

