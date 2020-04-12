#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    int n, m;
    int cost{ 0 };
    int dragon[20000], knight[20000];
    while( scanf("%d %d", &n, &m), n || m )
    {
        for( int i{ 0 }; i < n; ++i )
            scanf( "%d", &dragon[i] );
            
        for( int i{ 0 }; i < m; ++i )
            scanf( "%d", &knight[i] );
            
        if ( n > m )
        {
            printf( "Loowater is doomed!\n" );
            continue;
        }
            
        sort( dragon, dragon + n );
        sort( knight, knight + m );    
        
        cost = 0;
        
        int i{ 0 };
        int k{ 0 };
        for( ; i < n; ++i )
        {
            while( (knight[ k ] < dragon[ i ] ) && ( k < m ) )
                ++k;
                
            if( k == m )
                break;
            else 
                cost += knight[ k++ ];
        }
        
        if( i < n )
            printf( "Loowater is doomed!\n" );
        else
            printf( "%d\n", cost );
    }
    return 0;
}



