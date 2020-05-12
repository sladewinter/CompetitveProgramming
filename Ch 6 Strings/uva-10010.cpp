//UVa 10010 - Where’s Waldorf - String matching in 2D Grid
//If first character matches, search in all 8 directions

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//All possible 8 directions
int dx[8]{ 1, 1, 0, -1, -1, -1,  0,  1};
int dy[8]{ 0, 1, 1,  1,  0, -1, -1, -1};

char grid[50][50];                  //Store input grid
int m, n;                          //Problem parameters

//Search for pattern in direction dir starting from x, y
bool gridSearch( int x, int y, string pattern, int dir ) 
{
    for( int s{0}; s < pattern.size(); ++s )
    {
        if( pattern[s] != grid[x][y] )        //Mismatch
            return false;

        x += dx[ dir ];     //Move 1 step in x direction
        y += dy[ dir ];     //Move 1 step in y direction
    }

    return true;
}

int main()
{
    int TC;                          //No of test cases
    int k;                          //Problem parameter
    string pattern;                //Store strings to search

    scanf( "%d", &TC );
    while( TC-- )                            //New test case
    {
        scanf( "%d %d\n", &m, &n );

        for( int i{0}; i < m; ++i ) 
        {    
            //Keep everything in lower case
            for( int j{0}; j < n; ++j )
                grid[i][j] = tolower( getchar() );

            scanf( "\n" );                 //Get the newline
        }

        scanf( "%d\n", &k );                //No of patterns 

        for( int i{0}; i < k; ++i )       
        {
            cin >> pattern;             //Take pattern input

            //Keep everything in lower case
            transform( pattern.begin(), pattern.end(),
                         pattern.begin(), ::tolower );

            bool solved{ false };

            //These many characters left to traverse from x, y
            int toTraverse{ pattern.size() - 1 };

            //Traverse the grid once
            for( int x{0}; x < m & !solved; ++x )
            for( int y{0}; y < n & !solved; ++y )

            if( grid[x][y] == pattern[0] ) //Potential match
            
                for( int d{0}; d < 8; ++d )//Every direction

                //Check if boundary constraint satisfying
                if( ( x + dx[d] * toTraverse >= 0 )
                    && ( x + dx[d] * toTraverse < m )
                    && ( y + dy[d] * toTraverse >= 0 )
                    && ( y + dy[d] * toTraverse < n ) )

                    //Stop if already solved
                    if( solved = gridSearch( x, y, pattern, d ) )
                    {
                        printf( "%d %d\n", x + 1, y + 1 );
                        break;
                    }
        }

        if( TC )
            printf( "\n" );                 //Test case completed
    }
    return 0;
}