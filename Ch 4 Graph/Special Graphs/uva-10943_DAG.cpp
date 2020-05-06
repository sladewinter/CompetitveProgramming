//DP problem modelled as No of Topological orderings possible on DAG
//UVa - 10943 - How do you add? - No of ways to add k numbers for sum n
//Model states ( k Numbers, Sum n ) of DP as vertices of DAG

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;
using ii = pair<int, int>;
using vii = vector<ii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;

vii topologic;
vvb visited;
vii AdjList[101][101];

void toposort( int x, int y )
{
    visited[x][y] = true;

    for( auto &v : AdjList[x][y] )
        if( !visited[ v.first ][ v.second ] )
            toposort( v.first, v.second ); 

    topologic.push_back( { x, y } );
}

int main()
{
    int N, K;                                     //Problem parameters
    vvi noOfWays;
    while( scanf( "%d %d", &N, &K ), N || K )
    {
        //When K = 1, there is only 1 choice, N itself
        //So we fill till K = 2 and ensure N >= 0 since choice <= N
        for( int i{ K }; i > 1; --i )
            for( int j{ N }; j >= 0; --j )
            {
                AdjList[i][j].clear();

                for( int choice{0}; choice <= j; ++choice )
                    AdjList[i][j].emplace_back( i - 1, j - choice );
            }

        //Topologically sort our DAG
        topologic.clear();
        visited.assign( K + 1, vb( N + 1, false ) );
        toposort( K, N );
        reverse( topologic.begin(), topologic.end() );

        //Count no of ways
        noOfWays.assign( K + 1, vi( N + 1, 0 ) );

        //Start with 1 choice
        noOfWays[K][N] = 1;

        //Whenever we reach K = 1 for N >= 0, thats 1 more way
        for( auto &u : topologic )
            for( auto &v : AdjList[u.first][u.second] )
                noOfWays[v.first][v.second] = ( noOfWays[v.first][v.second]
                          + noOfWays[u.first][u.second] ) % 1000000;

        //Sum of all values of noOfWays[1][N] for N >= 0 is our solution
        printf( "%d\n", accumulate( noOfWays[1].begin(), noOfWays[1].end()
                                                       , 0) % 1000000 );
    }
    return 0;
    
}