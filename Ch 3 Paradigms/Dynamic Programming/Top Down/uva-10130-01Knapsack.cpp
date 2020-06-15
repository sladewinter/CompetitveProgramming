#include <iostream>
#include <cstdint>
#include <cstring>
using namespace std;
int_least16_t P[1000], W[1000];
int memo[1001][31];
int N;

int knapsack( int i, int w )
{
    if( w == 0 || i == N )
        return 0;
    
    int &ans{ memo[i][w] };
    
    if( ans != -1 )
        return ans;
        
    if( W[i] > w )
        ans = knapsack( i + 1, w );
    else
        ans = max( knapsack( i + 1, w ), knapsack( i + 1, w - W[i] ) + P[i] );
    return ans;
}

int main()
{
    int T, G, MW, ans;
    scanf( "%d", &T );
    while( T-- )
    {
        scanf( "%d", &N );
        for( int i{0}; i < N; ++i )
            scanf( "%d %d", &P[i], &W[i] );
            
        memset( memo, -1, sizeof(memo));
        ans = 0;
        
        scanf( "%d", &G );
        while( G-- )
        {
            scanf( "%d", &MW );
            ans += knapsack( 0, MW );
        }
        printf( "%d\n", ans );
    }
    return 0;
    
}
