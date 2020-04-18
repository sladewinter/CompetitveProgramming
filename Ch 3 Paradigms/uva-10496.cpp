#include <iostream>
#include <cstring>
using namespace std;
int memo[11][2048];
int beepers[11][2];
int dist[11][11];
int beep;

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
            int i = __builtin_ctz( LSone ) + 1;
            ans = min( ans, dist[pos][i] + tsp( i, mask ^ LSone ) );
            m -= LSone;
        }
    }       
    return ans;
}

int main()
{
    int TC, x, y;
    scanf( "%d", &TC );
    while( TC-- )
    {
        memset( memo, -1, sizeof( memo ) );
        scanf( "%d %d", &x, &y );
        scanf( "%d %d", &beepers[0][0], &beepers[0][1] );
        scanf( "%d", &beep );
        for( int i{1}; i <= beep; ++i )
                scanf( "%d %d", &beepers[i][0], &beepers[i][1] );
                
        for( int i{0}; i <= beep; ++i )
            for( int j{0}; j <= beep; ++j )
                dist[i][j] = abs(beepers[i][0] - beepers[j][0])
                           + abs(beepers[i][1] - beepers[j][1]);
                           
        printf( "The shortest path has length %d\n", tsp( 0, (1 << beep) - 1 ) );
    }
    return 0;
}

