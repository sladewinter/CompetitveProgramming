#include <iostream>
#include <cstring>

using namespace std;

int N, M, C, sol;
int models[20][21];
int shopA[201][21];

int shop( int money, int g )
{
    if( money < 0 )
        return -9999;
        
    if( g == C )
        return ( M - money );
        
    int &ans{ shopA[money][g] };
 
    if( ans != -1 )
        return ans;

    for( int j{1}; j <= models[g][0]; ++j )
        ans = max( ans, shop( money - models[g][j], g + 1 ));
    
    return ans;
}

int main() 
{
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
        
        memset( shopA, -1, sizeof(shopA) );
        sol = shop( M, 0 );
        
        ( sol < 0 ) ? printf( "no solution\n" )
                    : printf( "%d\n", sol );
        
    }
    return 0;
}








