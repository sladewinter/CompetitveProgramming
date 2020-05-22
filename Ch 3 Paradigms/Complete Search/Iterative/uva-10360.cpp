//UVa - 10360 - Rat Attack
//Iterative Complete Search

#include <iostream>
#include <cstdint>
#include <array>
#include <algorithm>
#include <cstring>

using namespace std;
using int_t = int_least16_t;

int main()
{
    int tC{ 0 };
    cin >> tC;
    
    int d{ 0 }; 
    int n{ 0 };
    int resX{ 0 };
    int resY{ 0 };
    int resPop{ 0 };
    
    int x, y, size;
    int_t killed[ 1025 ][ 1025 ];
    
    while( tC-- )
    {
        cin >> d >> n;
        memset( killed, 0, sizeof( killed ));

        for( int i{ 0 }; i < n; ++i )
        {
            cin >> x >> y >> size;
            
            int x_begin{ max( x - d, 0 ) };
            int x_end  { min( x + d, 1024 ) };
            int y_begin{ max( y - d, 0 ) };
            int y_end  { min( y + d, 1024 ) };
            
            for( int j{ x_begin }; j <= x_end; ++j )
                for( int k{ y_begin }; k <= y_end; ++k )
                    killed[ j ][ k ] += size;
        }    
        
        resPop = 0;
        resX   = 0;
        resY   = 0;
        
        for( int j{ 0 }; j < 1025; ++j )
                for( int k{ 0 }; k < 1025; ++k )
                    if( resPop < killed[ j ][ k ] )
                    {
                        resX = j;
                        resY = k;
                        resPop = killed[ j ][ k ];
                    }
                    
        printf( "%d %d %d\n", resX, resY, resPop);
    }
    
	return 0;
}






