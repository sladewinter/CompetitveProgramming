//UVa 10235 - Simply Emirp - Simple program to check whether a number is Prime or not

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime( int N )
{
    int sqrtN{ static_cast<int>( sqrt( N ) ) };
    for( int d{ 2 }; d <= sqrtN; ++d )
        if( N % d == 0 )
            return false;

    return true;
}

int main()
{
    int N;                                    //Problem parameter
    while( scanf( "%d", &N ) != EOF )
    {
        if( !isPrime( N ) )
        {
            printf( "%d is not prime.\n", N );
            continue;
        }
        
        int reverseN{ 0 };
        int tempN{ N };

        while( tempN > 0 )
        {
            reverseN = reverseN * 10 + tempN % 10;
            tempN /= 10;
        }

        if( reverseN != N && isPrime( reverseN ) )      //Shortcircuit optimization
            printf( "%d is emirp.\n", N );
        else
            printf( "%d is prime.\n", N );
    }
}