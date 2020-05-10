//UVa 12024 - Hats - Simple problem to calculate derangements and factorials

#include <iostream>

using namespace std;

//We only need till 12 since n <= 12, set base cases
constexpr int maxN{ 12 };
int derange[13]{ 1, 0 };
int factorial[13]{ 1, 1 };

//Calculates both factorial and derangements in same loop
void fact_and_derange( int n )  
{
    for( int i{ 2 }; i <= n; ++i )
    {
        derange[i] = ( i - 1 ) * ( derange[i - 1] + derange[i - 2] );
        factorial[i] = i * factorial[i - 1];
    }
}

int main()
{
    //Precompute factorial and derangements till max value of input
    fact_and_derange( maxN );

    int t, n;              //Problem parameters
    scanf( "%d", &t );
    while( t-- )
    {
        scanf( "%d", &n );
        printf( "%d/%d\n", derange[n], factorial[n] );
    }

}