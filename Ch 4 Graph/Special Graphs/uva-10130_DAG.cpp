//Dynamic Programming problem modelled as Longest Path on DAG
//UVa - 10130 - SuperSale - Classic 0/1 Knapsack Problem
//Model states ( item_no, capacity_left) of DP as vertices of DAG

#include <iostream>
#include <cstdint>
#include <vector>
#include <utility>
#include <algorithm>
#include <tuple>

using namespace std;
using ii = pair<int, int>;
using vii = vector<ii>;
using iii = tuple<int, int, int>;
using viii = vector<iii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;

//Note: Declaring large variables as local often ends stack memory
int_least8_t P[1000], W[1000];       
int N;
vii topologic;
vvb visited;
viii AdjList[1001][31];

void toposort( int x, int y )
{
    visited[x][y] = true;

    int x1, y1, val;
    for( auto &next : AdjList[x][y] )
    {
        tie( x1, y1, val ) = next;
        if( !visited[x1][y1] )
            toposort( x1, y1 ); 
    }

    topologic.push_back( { x, y } );
}

int main()
{
    int T, G, MW;
    vvi dist;
    scanf( "%d", &T );
    while( T-- )
    {
        //Take input Profits and Weights
        scanf( "%d", &N );
        for( int i{0}; i < N; ++i )
            scanf( "%d %d", &P[i], &W[i] );

        //Let's fill up our Adjacency List in O(nW) time
        for( int i{ 0 }; i < N; ++i )
            for( int w{ 30 }; w >= 0; --w )
            {
                AdjList[i][w].clear();

                //Not taking item i, 0 value added
                AdjList[i][w].push_back({ i + 1, w, 0 });
                
                //Taking item i, P[i] value added
                if( w - W[i] >= 0 )
                  AdjList[i][w].push_back({ i + 1, w - W[i], P[i] });
            }

        //This is very important step as AdjList[N] remains filled
        //for one larger value of G and for next smaller value of G, 
        //it gives error as TopoSort unintentionally continues execution
        for( int w{ 30 }; w >= 0; --w )
            AdjList[N][w].clear();

        scanf( "%d", &G );

        int ans{ 0 };
        while( G-- )
        {
            scanf( "%d", &MW );

            //Topologically sort our DAG in O( V ) as E = O( 2V ) here
            topologic.clear();
            visited.assign( N + 1, vb( MW + 1, false ) );
            toposort( 0, MW );
            reverse( topologic.begin(), topologic.end() );

            //Longest Path on DAG
            //This step takes O( V ) as AdjList[u] contains 2 edges 
            int x, y, val;
            dist.assign( N + 1, vi( MW + 1, 0 ) );
            for( auto &u : topologic )
                for( auto &v : AdjList[u.first][u.second] )
                {
                    tie( x, y, val ) = v;

                    //Take the longer path, longest path first
                    dist[x][y] = max( dist[x][y], 
                        dist[u.first][u.second] + val );
                }

            ans += *max_element( dist[N].begin(), dist[N].end() );
        }
        printf( "%d\n", ans );
    }
    return 0;
    
}