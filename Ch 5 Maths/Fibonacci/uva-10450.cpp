//UVa 10450 - World Cup Noise - Very simple Fibonacci Number generator using DP

#include <iostream>

using namespace std;

long long unsigned memo[51]{ 1, 2 };      //Rest will get initialized to 0

long long unsigned fibonacci( int num )
{
    long long unsigned &ans{ memo[num] };
    return (ans) ? ans : ans = fibonacci( num - 1 ) + fibonacci( num - 2 );
}

int main()
{
    int TC, num;                                  //No of Test Cases, input
    int caseNo{ 0 };                             //For output purposes
    scanf( "%d", &TC );
    while( TC-- )
    {
        scanf( "%d", &num );
        printf( "Scenario #%d:\n%llu\n\n", ++caseNo, fibonacci( num ) );
    }
    return 0;
}