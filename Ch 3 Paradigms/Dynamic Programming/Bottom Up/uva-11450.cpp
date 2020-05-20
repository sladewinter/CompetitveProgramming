#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() 
{
    int N, M, C, sol;
    int models[20][21];
    bool reachable[2][201];
    scanf( "%d", &N );
    while( N-- )
    {
        scanf( "%d %d", &M, &C );
        for( int i{0}; i < C; ++i )
        {
            scanf( "%d", &models[i][0] );
            for( int j{1}; j <= models[i][0]; ++j )
                scanf( "%d", &models[i][j] );    
        }
        memset( reachable, 0, sizeof(reachable) );
        
        for( int i{1}; i <= models[0][0]; ++i )
            if( M - models[0][i] >= 0 )
                reachable[0][M - models[0][i]] = 1;
                
        int prev{ 0 };
        int curr{ 1 };
        
        for( int i{1}; i < C; ++i )
        {
            memset( reachable[ curr ], 0, sizeof(reachable[ curr ]) );
            for( int j{0}; j < M; ++j )
                if( reachable[prev][ j ] == 1)
                    for( int k{1}; k <= models[i][0]; ++k )
                        if( j - models[i][k] >= 0)
                            reachable[curr][j - models[i][k]] = 1;
            swap( prev, curr );                
        }
        int i = 0;
        for( ; i < M; ++i )
            if( reachable[ prev ][i] == 1 )
            {
                printf( "%d\n", M - i);
                break;
            }
        if ( i == M )
            printf( "no solution\n" );
    }
    return 0;
}











