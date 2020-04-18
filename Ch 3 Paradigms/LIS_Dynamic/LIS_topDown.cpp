// Longest Increasing Subsequence Memoization

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

array arr{ -7, 10, 9, 2, 3, 8, 8, 1 };
int memo[ arr.size() ];
int opti{ 1 };

int lis( int index )
{
    if( index == 0 )
        return 1;
        
    int &val{ memo[index] };
    
    if( val != 1 )
        return val;
    
    for( int j{0}; j < index; ++ j )
    {
        lis(j);
        if( arr[index] > arr[j] )
            val = max( val, 1 + lis(j) );
    }
    opti = max( opti, val );       
    return opti;
}

int main()
{
    fill( memo, memo + arr.size(), 1 );
    lis( arr.size() - 1 );
    cout << opti;
    return 0;
}