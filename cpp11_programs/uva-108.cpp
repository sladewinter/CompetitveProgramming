#include <iostream>

using namespace std;

int main()
{
    int n, max, sum;
    int array[100][100];
    while( scanf( "%d", &n ) != EOF )
    {
        for( int i{0}; i < n; ++i )
            for( int j{0}; j < n; ++j )
            {
                scanf( "%d", &array[i][j] );
                if( i > 0 )
                    array[i][j] += array[i-1][j];
                if( j > 0 )
                    array[i][j] += array[i][j-1];
                if( i > 0 && j > 0 )
                    array[i][j] -= array[i-1][j-1];
            }
        max = -127;
        
        for( int x1{0}; x1 < n; ++x1 )
            for( int y1{0}; y1 < n; ++y1 )
                for( int x2{x1}; x2 < n; ++x2 )
                    for( int y2{y1}; y2 < n; ++y2 )
                    {
                        sum = array[x2][y2];
                        if(y1 > 0)
                            sum -= array[x2][y1 - 1];
                        if(x1 > 0)
                            sum -= array[x1 - 1][y2];
                        if(x1 > 0 && y1 > 0)
                            sum += array[x1 - 1][y1 - 1];
                        if( max < sum )
                            max = sum;
                    }
        printf( "%d\n", max );
    }
    return 0;
}