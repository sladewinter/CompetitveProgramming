//No of Topological Orderings possible in Directed Acyclic graph
//Topological sorting to form DAG & count no of paths to Destination
//UVa 988 - Many Paths, One Destination - Directed unweighted Graph

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;

vvi AdjList;          
vb visited;                 
vi topologic;
void topoSort( int u )
{
    visited[u] = true;
    
    for( auto &v : AdjList[ u ] )
        if( !visited[ v ] )
            topoSort( v );

    topologic.push_back( u );
}

int main()
{
    //freopen( "input", "r", stdin );
    int noVerts;                              //No of vertices
    int noEvents;                            //No of children
    int event;                              //Child   
    int sum;                               //Sum of no of paths   
    vi noPaths;                           //No of paths birth->death
    bool first{ true };                  //First TestCase
    
    while( scanf( "%d", &noVerts ) != EOF )
    {
        ( first ) ? ( first = false ) : printf( "\n" );

        AdjList.assign( noVerts, vi() );
        for( int i{ 0 }; i < noVerts; ++i )
        {
            scanf( "%d", &noEvents );
            while( noEvents-- )
            {
                scanf( "%d", &event );
                AdjList[ i ].push_back( event );
            }
        }

        visited.assign( noVerts, false );
        topologic.clear();
        topoSort( 0 );
        reverse( topologic.begin(), topologic.end() );

        //Multiple leaf nodes are there, so need to sum their noPaths
        noPaths.assign( noVerts, 0 );
        noPaths[0] = 1;        
        sum = 0;
        for( auto &u : topologic )
            for( auto &v : AdjList[ u ] )
                noPaths[v] += noPaths[u];         //1 more path to v

        int v = noVerts;
        while( v-- )
            if( AdjList[ v ].empty() )           //v is leaf vertex
                sum += noPaths[ v ];            //Sum all leaf vertex
                
        printf( "%d\n", sum );
    }
    return 0;
}





