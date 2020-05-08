//UVa 900 - Brick Wall Patterns - Very simple Fibonacci Number generator using DP

#include <iostream>

using namespace std;

long long unsigned memo[50]{ 1, 1 };      //Rest will get initialized to 0

long long unsigned fibonacci( int num )
{
    long long unsigned &ans{ memo[num] };
    return (ans) ? ans : ans = fibonacci( num - 1 ) + fibonacci( num - 2 );
}

int main()
{
    int num;
    while( scanf( "%d", &num ), num )
        printf( "%llu\n", fibonacci( num ) );
    return 0;
}