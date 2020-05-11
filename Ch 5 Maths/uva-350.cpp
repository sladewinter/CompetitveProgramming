//UVa 350 - Pseudo-Random Numbers - Solved using Floyd's cycle finding algorithm
//Given function f(x) to generate Pseudo-random numbers and seed u, detect length 
//lambda after which the numbers get repeated, also cycle may not begin with u

#include <iostream>

using namespace std;

int Z, I, M, L;                //f(x1) = (Z x x0 + I) % M, x0 = L

int f( int x )               //Calculates f(x)
{
    return ( Z * x + I ) % M;
}

int floydCycleFinding( int x0 )
{
    //In cycle with length lambda, xi = xi + klambda. Let i = klambda. xi = x2i
    //Tortoise and hare starts at x0, tortoise moves 1 step, hare moves 2 steps
    int tortoise{ f( x0 ) };
    int hare{ f( f( x0 ) ) };
    while( tortoise != hare )                  //This loop breaks when xi = x2i
    {
        tortoise = f( tortoise );
        hare = f( f( hare ) );
    }

    //We found i such that klambda = i. Now we will find 'begin of cycle' u
    //Tortoise retains position i, hare starts from x0, both move at same speed
    hare = x0;
    int u{ 0 };
    while( tortoise != hare )         //This loop breaks when xu = xu + klambda
    {
        tortoise = f( tortoise );
        hare = f( hare );
        ++u;
    }

    //We found 'begin of cycle' u, hare is at position u. Now we will find lambda.
    //Tortoise retains position, hare is set next to it, hare moves tortoise stays
    int lambda{ 1 };
    hare = f( tortoise );
    while( tortoise != hare )          //This loop breaks when xi = xi + lambda
    {
        hare = f( hare );
        ++lambda;
    }

    return lambda;
}

int main()
{
    int caseNo{ 0 };

    while( scanf( "%d %d %d %d", &Z, &I, &M, &L ), Z || I || M || L )
    {
        printf( "Case %d: %d\n", ++caseNo, floydCycleFinding( L ) );
    }

}