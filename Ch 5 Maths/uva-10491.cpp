//UVa 10491 - Cows and Cars - Very simple problem to calculate probability

#include <iostream>

using namespace std;

int main()
{
    
    double NCOWS, NCARS, NSHOW;                       //Problem parameters

    while( scanf( "%lf %lf %lf", &NCOWS, &NCARS, &NSHOW ) != EOF )
    {
        double sum{ NCOWS + NCARS };
        printf( "%.5lf\n", ( ( NCOWS / sum ) * ( NCARS / ( sum - 1 - NSHOW ) ) ) 
            + ( ( NCARS / sum ) * ( ( NCARS - 1 ) / ( sum - 1 - NSHOW ) ) ) );
    }
}