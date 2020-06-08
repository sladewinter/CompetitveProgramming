//Shortest Path on Weighted Graph with -ve weighed edges
//Bellman Ford Algorithm - Find out if negative weighed cycles exist
//UVa - 558 - Wormholes - Directed simple graph, all vertices reachable

#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvii = vector<vii>;

int main()
{
    int c, n, m, x, y, t;
    vvii AdjList;
    vi dist;
    bool possible;
    scanf( "%d", &c );
    while( c-- )
    {
        scanf( "%d %d", &n, &m );
        AdjList.assign( n, vii() );
        dist.assign( n, 999999 );
        while( m-- )
        {
            scanf( "%d %d %d", &x, &y, &t );
            AdjList[x].emplace_back( y, t );
        }

        //Bellman Ford
        dist[0] = 0;                              //0 is source in problem
        for( int i{0}; i < n - 1; ++i )          //Run ( n - 1 ) times
            for( int u{0}; u < n; ++u )         //For all vertices u
                for( auto &v : AdjList[u] )    //Vertices adjacent to u
                    dist[v.first] = min( dist[v.first], dist[u] + v.second );


        //Now run it one more time
        possible = false;
        for( int u{0}; u < n; ++u )           //For all vertices u
            for( auto &v : AdjList[u] )      //Vertices adjacent to u
                if( dist[v.first] > dist[u] + v.second )  //-ve cycle
                {
                    possible = true;
                    break;
                }

	//Variant of ternary operator just for demonstration
        ( possible ) && printf( "possible\n" )
                     || printf( "not possible\n" );
    }
    return 0;
}



