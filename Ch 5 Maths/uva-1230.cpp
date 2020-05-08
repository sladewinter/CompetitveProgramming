//UVa 1230 - MODEX - Given x, y, n where y is large, find pow( x, y ) % n efficiently

#include <iostream>

//Recursively calculate pow( x, y ) % n
int modPow( int x, int y, int n )
{
    if( y == 0 )                           //Base case
        return 1;                              

    int sol{ modPow( x, y/2, n ) };        //Recursively calculate for y/2
    sol = ( sol * sol ) % n;               //Now combine

    if( y & 1 )                            //In case y was odd when halved
        sol = ( sol * x ) % n;             //Multiply x one more time

    return sol;
}

int main()
{
    int c;                                 //No of datasets
    int x, y, n;                           //Problem parameters

    scanf( "%d", &c );
    while( c-- )
    {
        scanf( "%d %d %d", &x, &y, &n );
        printf( "%d\n", modPow( x, y, n ) );   
    }

    return 0;
}