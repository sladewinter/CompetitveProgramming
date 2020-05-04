//Min Cut in Undirected graph solution using Max Flow
//Edmonds Karp's Algorithm - Adjacency Matrix Data structure
//UVa 10480 - Sabotage - Software Allocation - undirected weighted graph

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using vi = vector<int>;

int res[ 50 ][ 50 ];                     //Residual graph
vi parent;                              //Parent vector for BFS
vi dist;                               //Distance vector for BFS
constexpr int INF{ 999999 };

//Finds shortest path s ~> t on n vertices
void modif_BFS( int s, int t, int n )
{   
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
            if( res[u][v] > 0 && dist[v] == INF )
            {
                dist[v] = dist[u] + 1;
                q.push( v );
                parent[ v ] = u;
              //  printf( "Parent of %d is %d\n", v, u );
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
                            res[ parent[v] ][ v ] ) );
      
        res[ parent[v] ][ v ] -= flow;
        res[ v ][ parent[v] ] += flow;
    }
}

int main()
{
    //freopen( "input", "r", stdin );
    int n, m;
    int initial[50][50];
    while( scanf( "%d %d", &n, &m ), n || m )  //New test case
    {
        //Reset residual graph
        memset( res, 0, sizeof( res ) );

        int u, v, cost;
        while( m-- )
        {
            scanf( "%d %d %d", &u, &v, &cost );

            --u; --v;                    //Our indices start @1
            res[u][v] = cost;
            res[v][u] = cost;   
        }

        memcpy( initial, res, sizeof( res ) );

        //Got our input now run Edmonds Karp's algo
        int maxFlow{ 0 };
        
        while( 1 )                   //Edmonds Karp's algorithm
        {
            //Source( Capital ) is 0, Sink( Largest city ) is 1
            modif_BFS( 0, 1, n );

            //Find minimum weighed edge in path s~>t in resGraph
            flow = 0;
            augment( 0, 1, INF ); 
            if( flow == 0)           //No more flow can be added
                break;
            maxFlow += flow;
        }

        vi sComp, tComp;                    //S and T components
        modif_BFS( 0, 1, n );                //Run BFS once more

        while( n-- )                    //Check for all vertices
        {
            if( dist[n] == INF )       //Unreachable from source
                tComp.push_back(n);
            else                         //Reachable from source
                sComp.push_back(n);
        }

        for( auto &u : sComp )         //Vertices in S component
            for( auto &v : tComp )     //Vertices in T component

                //If earlier u and v were connected
                if( initial[u][v] != 0 )

                    //Then now they have been cut
                    printf( "%d %d\n", u + 1, v + 1 );

        printf( "\n" );
    }
    return 0;
}





