//UVa 11195 - Another n-Queen Problem
//Recursive Backtracking with Pruning
//Using Fast Lookup with Bitmasks

#include <iostream>
#include <cstdint>

using namespace std;

std::int_fast16_t rowV{ 0 };         //Keeps track of empty rows
std::int_fast32_t leftD{ 0 };       //Keeps track of empty left diagonals
std::int_fast32_t rightD{ 0 };     //Keeps track of empty right diagonals

char board[ 14 ][ 14 ];          //n <= 14 sized board

int n  { 0 };
int ans{ 0 };

void backtrack( int c )     //Recursively visit columns
{
    if(c == n )           //1 possible solution
        ++ans;
        
    else               //Assign empty row checking collision using bitmask
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
        
        backtrack( 0 );                      //Always start with column 0
        
        printf("Case %d: %d\n", ++lineNum, ans);
    }
    
	return 0;
}



