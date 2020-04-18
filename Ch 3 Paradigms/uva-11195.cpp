#include <iostream>
#include <cstdint>

using namespace std;

std::int_fast16_t rowV{ 0 };
std::int_fast32_t leftD{ 0 };
std::int_fast32_t rightD{ 0 };

char board[ 14 ][ 14 ];

int n  { 0 };
int ans{ 0 };

void backtrack( int c )
{
    if(c == n )
        ++ans;
        
    else
    {
        for( int r{ 0 }; r < n; ++r )
            if(( board[r][c] != '*' ) && !( rowV   & ( 1 << r ))
                                      && !( leftD  & ( 1 << ( r - c + n - 1 )))
                                      && !( rightD & ( 1 << ( r + c ))))
            {
                rowV   |= ( 1 << r );
                leftD  |= ( 1 << ( r - c + n - 1 ));
                rightD |= ( 1 << ( r + c ));
                backtrack( c + 1 );
                rowV   &= ~( 1 << r );
                leftD  &= ~( 1 << ( r - c + n - 1 ));
                rightD &= ~( 1 << ( r + c ));
            }
    }
}

int main()
{
    int lineNum{ 0 };
    while( cin >> n, n )
    {
        for( int i{ 0 }; i < n; ++i )
            for( int j{ 0 }; j < n; ++j )
                cin >> board[ i ][ j ];
                
        rowV   = 0;
        leftD  = 0;
        rightD = 0;
        ans    = 0;
        
        backtrack( 0 );
        
        printf("Case %d: %d\n", ++lineNum, ans);
    }
    
	return 0;
}



