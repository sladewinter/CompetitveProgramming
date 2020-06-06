#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>

using namespace std;
using ii = pair<int, int>;
ii chamber[5];

int main() 
{
    int C, S;
    double imb{ 0 };
    double avg{ 0 };
    int setNo{ 0 };
    array<int, 10> specimens;
    while( scanf("%d %d", &C, &S ) == 2 )
    {
        memset( chamber, 0, sizeof( chamber ));
        imb = 0;
        avg = 0;
        for( int i{ 0 }; i < S; ++i )
        {
            scanf( "%d", &specimens[ i ] );
            avg += specimens[ i ];
        }
        avg /= C;
        sort( specimens.begin(), specimens.begin() + S, greater<int>() );

        int temp = 0;
        for( ; temp < min( C, S); ++temp )
            chamber[temp].first = specimens[temp];
            
        int cham = C;
        if( temp < S )
        for( ; temp < S; ++temp )
            chamber[--cham].second = specimens[temp];
            
        for( temp = 0; temp < C; ++temp )
            imb += abs(chamber[temp].first + chamber[temp].second - avg);
        
        printf( "Set #%d\n", ++setNo );
        
        for( int i{ 0 }; i < C; ++i )
        {
            printf( " %d:", i );
            if( chamber[i].first )
                printf( " %d", chamber[i].first);
            if( chamber[i].second )
                printf( " %d", chamber[i].second);
            printf( "\n" );
        }
        printf( "IMBALANCE = %.5lf\n\n", imb );
    }
    return 0;
}