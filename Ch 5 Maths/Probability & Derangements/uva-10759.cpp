//UVa 10759 - Dice Throwing - Probability of getting sum >= x using n throws
//Bottom Up dynamic programming used to prevent deep recursion by Top Down

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    int n, x;              //Problem parameters
    ll memo[25][145];     //DP table( throws_left, curr_score )

    while( scanf( "%d %d", &n, &x ), n || x )
    {
        //Base case of DP, max n x 6 score possible with n throws
        for( int i{ 0 }; i <= n * 6; ++i )
            if( i < x )                          //Less than required score
                memo[0][i] = 0;
            else
                memo[0][i] = 1;        //Valid possibility, score satisfied    

        //Fill rest of the DP table in Bottom Up fashion
        for( int i{ 1 }; i <= n; ++i )
            for( int j{ 0 }; j <= n * 6; ++j )
            {
                //Initialize no of ways to reach score >= x to 0
                memo[i][j] = 0;

                //Throw 1 to 6 and add no of ways to reach >= x from curr_score j
                for( int k{ 1 }; k <= 6; ++k )
                    
                    //Since we need to bound (curr_score + throw) to table size
                    if( j + k <= n * 6 )
                        memo[i][j] += memo[i-1][j + k] ;

                //We need this, if curr_score increases, no of ways never decrease
                if( j > 0)
                    memo[i][j] = max( memo[i][j], memo[i][j - 1]);
            }

        ll sample_space{ static_cast<ll>( pow( 6, n ) ) };
        ll GCD{ __gcd( sample_space, memo[n][0] ) };

        //No of ways starting with n throws & 0 score to reach >= x is memo[n][0]
        memo[n][0] /= GCD;
        sample_space /= GCD;

        if( memo[n][0] == 0 )
            printf( "0\n" );
        else if( memo[n][0] == sample_space )
            printf( "1\n" );
        else
            printf( "%lld/%lld\n", memo[n][0], sample_space );

    }

}