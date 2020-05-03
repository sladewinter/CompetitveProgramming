//Max Flow in Undirected( hence Bidirectional ) graph
//Edmonds Karp's Algorithm - Adjacency Matrix Data structure
//UVa - 820 - Internet Bandwidth - weighted connected graph

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using vi = vector<int>;

int resGraph[ 100 ][ 100 ];              //Residual graph
vi parent;                              //Parent vector for BFS
constexpr int INF{ 999999 };

//Finds shortest path s ~> t on n vertices
void modif_BFS( int s, int t, int n )
{
    static vi dist; 
    
    dist.assign( n, INF );  
    parent.assign( n, -1 );

    queue<int> q;
    dist[s] = 0;
    q.push( s );

    int u, v;
    while( !q.empty() )
    {
        u = q.front();
        q.pop();
        if( u == t )
            break;                        //Reached destination

        for( v = 0; v < n; ++v )
        {
            //If edge u->v exists in resGraph && v is unvisited
            if( resGraph[u][v] > 0 && dist[v] == INF )
            {
                dist[v] = dist[u] + 1;
                q.push( v );
                parent[ v ] = u;
            }
        }

    }
}

int flow{ 0 };
void augment( int s, int v, int minEdge )
{
    if( v == s )                              //Reached source
    {
        flow = minEdge;
        return;
    }
    if( parent[v] != -1 )          //We can continue traversal
    {
        augment( s, parent[v], min( minEdge, 
                            resGraph[ parent[v] ][ v ] ) );

        resGraph[ parent[v] ][ v ] -= flow;
        resGraph[ v ][ parent[v] ] += flow;
    }
}

int main()
{
    //freopen( "input", "r", stdin );
    int n, s, t, c;                         //Problem parameters
    int caseNo{ 0 };
    while( scanf( "%d", &n ), n )
    {
        scanf( "%d %d %d", &s, &t, &c );
        --s; --t;                     //Problem indices start @1

        //Set up residual graph
        memset( resGraph, 0, sizeof( resGraph ) );
        int u, v, bw;
        while( c-- )
        {
            scanf( "%d %d %d", &u, &v, &bw );
            --u; --v;                //Problem indices start @1

            //Since multi edges possible, take sum of bandwidth
            resGraph[u][v] += bw;
            resGraph[v][u] += bw;
        }

        int maxFlow{ 0 };
        while( 1 )                    //Edmonds Karp's algorithm
        {
            //Running modified BFS on residual graph
            modif_BFS( s, t, n );

            //Find minimum weighed edge in path s~>t in resGraph
            flow = 0;
            augment( s, t, INF ); 
            if( flow == 0)           //No more flow can be added
                break;
            maxFlow += flow;
        }
        printf( "Network %d\n", ++caseNo );
        printf( "The bandwidth is %d.\n\n", maxFlow );
    }

    
    return 0;
}





