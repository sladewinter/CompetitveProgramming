#include <iostream>
using namespace std;

int main()
{
    int P[1000], W[1000];
    int knapsack[1001][31];
    int N;
    int T, G, MW, ans;
    scanf( "%d", &T );
    while( T-- )
    {
        scanf( "%d", &N );
        for( int i{0}; i < N; ++i )
            scanf( "%d %d", &P[i], &W[i] );
            
        ans = 0;
        
        for( int i{N}; i >= 0; --i )
            for( int w{0}; w <= 30; ++w)
            {
                if( w == 0 || i == N )
                {
                    knapsack[i][w] = 0;
                    continue;
                }    
                if( w < W[i] )
                    knapsack[i][w] = knapsack[i+1][w];
                else
                    knapsack[i][w] = max( knapsack[i+1][w], knapsack[i+1][w - W[i]] + P[i] );
            }
            
        scanf( "%d", &G );
        while( G-- )
        {
            scanf( "%d", &MW );
            ans += knapsack[0][MW];
        }
        printf( "%d\n", ans );
    }
    return 0;
    
}
