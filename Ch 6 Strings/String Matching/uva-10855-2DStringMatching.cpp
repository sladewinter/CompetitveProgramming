//UVa 10855 - Rotated square
//2D Array Manipulation

#include <iostream>
#include <vector>
#include <string>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int N, n;
vvi big, small, rot;

int compare()
{
    int count{ 0 };
    for( int x1{0}; x1 < N - n + 1; ++x1 )
        for( int y1{0}; y1 < N - n + 1; ++y1 )
        {                
            bool match{ true };

            for( int i{0}; i < n && match; ++i )
                for( int j{0}; j < n && match; ++j )
                {
                    int temp{ big[x1 + i][y1 + j] };
                        
                    if( x1 + i )
                        temp -= big[x1 + i - 1][y1 + j];

                    if( y1 + j )
                        temp -= big[x1 + i][y1 + j - 1];

                    if( x1 + i && y1 + j )
                        temp += big[x1 + i - 1][y1 + j - 1];

                    match = ( small[i][j] == temp );
                }
            count += match;
        }
    return count;
}

void rotate()
{
    for( int i{0}; i < n; ++i )
        for( int j{n-1}; j >= 0; --j )
            rot[i][n - j - 1] = small[j][i];
    small = rot;
}

int main() 
{
    string line;
    while( scanf( "%d %d\n", &N, &n ), N )
    {
        big.assign(N, vi(N));
        small.assign(n, vi(n));
        rot.assign(n, vi(n));

        for( int i{0}; i < N; ++i )
        {
            getline(cin, line);
            for( int j{0}; j < N; ++j )
            {
                big[i][j] = line[j] - 64;                
                
                if( i ) big[i][j] += big[i-1][j];
                if( j ) big[i][j] += big[i][j-1];
                
                if( i && j ) 
                    big[i][j] -= big[i-1][j-1];
            }
        }
        scanf( "\n" );
        for( int i{0}; i < n; ++i )
        {
            getline(cin, line);
            for( int j{0}; j < n; ++j )
                small[i][j] = line[j] - 64;
        }

        cout << compare();

        for( int i{0}; i < 3; ++i )
        {
            rotate();
            cout << ' ' << compare();
        }
        cout << '\n';
    }   
	return 0;
}													  
