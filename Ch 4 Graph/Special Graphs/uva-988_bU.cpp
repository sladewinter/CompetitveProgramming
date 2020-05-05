//No of Topological Orderings possible in DAG Bottom Up Approach
//Recursively count no of paths without doing Topological Sort
//UVa 988 - Many Paths, One Destination - Directed unweighted Graph

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;

vvi AdjList;         
vi noPaths;                           //No of paths birth->death
int countPath( int u )
{
    int &ans{ noPaths[ u ] };

    if( ans )
        return ans;
    for( auto &v : AdjList[ u ] )
        ans += countPath( v );
    return ans;
}

int main()
{
    //freopen( "input", "r", stdin );
    int noVerts;                              //No of vertices
    int noEvents;                            //No of children
    int event;                              //Child   
    int sum;                               //Sum of no of paths   
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

        //Multiple leaf nodes are there, so need to sum their noPaths
        noPaths.assign( noVerts, 0 );

        int v = noVerts;
        while( v-- )
            if( AdjList[ v ].empty() )         //v is leaf vertex
                 noPaths[v] = 1;               

        printf( "%d\n", countPath( 0 ) );    //Recursive bottom up
    }
    return 0;
}





