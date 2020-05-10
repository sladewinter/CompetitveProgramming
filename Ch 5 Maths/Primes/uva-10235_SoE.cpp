//UVa 10235 - Simply Emirp - Using Sieve of Eratosthenes to check Prime or not
//Problem requires primes upto 10^6, so Sieve is an overkill, just for demo
//We will generate all primes upto 10^4 using Sieve, but we could upto 10^7

#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
using vi = vector<int>;

constexpr int sieve_size{ 10001 };            //0 to 10000
bitset<sieve_size> bits;                     //Faster than vector<bool>
vi primes;                                  //Compact list of primes

void Sieve( int upperBound )              //Roughly O( N log log N)
{
    bits.set();                          //Set all bits to 1
    bits[0] = bits[1] = 0;              //0 and 1 are non-primes

    for( int i{ 2 }; i <= upperBound; ++i )
        if( bits[i] )                             //i is a Prime
        {
            //Cross out multiples starting from i*i, previous multiples
            //already cleared by now
            for( int j{ i * i }; j <= upperBound; j += i ) 
                bits[j] = 0;    

            primes.push_back(i);                      
        }
}

bool isPrime( int N )
{
    if( N < sieve_size )
        return( bits[N] );                   //O(1) optimization

    for( auto &prime : primes )
        if( N % prime == 0)                //Won't work if N > (last prime)^2
            return false;

    return true;
}

int main()
{
    Sieve( sieve_size - 1 );                   //One time, but may give TLE

    int N;                                    //Problem parameter
    while( scanf( "%d", &N ) != EOF )
    {
        if( !isPrime( N ) )                 //Very fast mostly O( 1 )
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

        if( reverseN != N && isPrime( reverseN ) )  //Shortcircuit optimization
            printf( "%d is emirp.\n", N );
        else
            printf( "%d is prime.\n", N );
    }
}