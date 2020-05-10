//UVa 10139 - Factovisors - Check whether m divides n! using Factorization
//Prime factorize m and then use Legendre's formula to check support in n!
//We will generate all primes upto sqrt( 2^31 ) to speed-up factorization

#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <unordered_map>

using namespace std;
using vi = vector<int>;

constexpr int sieve_size{ 46349 };            //sqrt( 2^31 = 46341 )
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

//What is the largest power x of p such that p^x divides n!
int legendre( int p, int n )
{
    int x{ 0 };             // Initialize result  
  
    while (n)             // Calculate x = n/p + n/(p^2) + n/(p^3) + ....  
    {  
        n /= p;  
        x += n;  
    }  
    return x;  
}


bool factovisors( int n, int m )
{
    if( m <= n | m == 0 | m == 1 )
        return true;                //Trivially true m is contained in n

    if( n == 0 | n == 1 )          // m > n and n! = 1, so m cannot divide 1
        return false;

    //Prime factorization of m
    int sqrtm{ static_cast<int>( sqrt( m ) ) };
    unordered_map<int, int> fact_m;
    for( auto &prime : primes )  
    {
        if( prime > sqrtm )         //Only need to check till sqrt( m )
            break;

        int frequency{ 0 };

        while( m % prime == 0 )
        {
            m /= prime;
            ++frequency;
        } 

        if( frequency > 0 )
            fact_m[ prime ] = frequency;      
    }

    //This means m has been reduced to its largest prime factor > sqrt( m )
    if( m > 1 )                    
        fact_m[ m ] = 1;

    //Now check for support of fact_m in n!
    for( auto &factor : fact_m )                  //For each p^e in fact_m
    {
        if( legendre( factor.first, n ) < factor.second )     //No support
           return false;
    }

    return true;                      //Factorization of m supported in n!
}


int main()
{
    Sieve( sieve_size - 1 );                       //Build list of primes
    int n, m;
    while( scanf( "%d %d", &n, &m ) != EOF )      //Whether m divides n!
    {
        factovisors( n, m ) ? printf( "%d divides %d!\n", m, n )
                            : printf( "%d does not divide %d!\n", m, n );
    }
}