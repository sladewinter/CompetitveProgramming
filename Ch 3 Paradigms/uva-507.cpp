#include <iostream>

using namespace std;

int main()
{
    int b, s;
    int r{ 0 };
    int max, max_start, max_end, so_far, start, end;
    int stop;
    scanf( "%d", &b );
    while( b-- )
    {
        scanf( "%d", &s );
        start = end = max_start = max_end = 1;
        max = so_far = 0;
        for( int i{1}; i <= s - 1; ++i )
        {
            scanf( "%d", &stop );
            so_far += stop;
            end = i + 1;
            
            if( so_far < 0 )
            {
                so_far = 0;
                start = end = i + 1;
            }
                
            if( max < so_far )
            {
                max = so_far;
                max_start = start;
                max_end = end;
            }
            
            if( max == so_far && ( end - start > max_end - max_start  ))
            {
                max_start = start;
                max_end = end;
            }
        }    
        
        if( max <= 0 )
            printf( "Route %d has no nice parts\n", ++r );
        else
            printf( "The nicest part of route %d is between stops %d and %d\n", ++r, max_start, max_end );
    }
    return 0;
}