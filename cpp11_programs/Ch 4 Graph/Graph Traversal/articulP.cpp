//  Articulation Point and Bridges using Tarjan algorithm
//  Note: Only works for Undirected Graph
// For detailed explanation please visit the follow link
//https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/

/*  Use the following input - Adjacency list representation
  6                             //No of nodes = 6
  1 1                         //Starts with no of incident edges
  5 0 2 3 4 5               //followed by that many neighbors
  1 1                     //Vertices start from 0
  1 1                   //This is Vertex No 3
  2 1 5               //Vertex No 4 has 2 neighbors / edges
  2 1 4             //Vertices 1 and 4 are neighbors of 5
*/

#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;
using vb = vector<bool>;

//Discovery time of each vertex, initialize with 0
vi dfsnum( 100, 0 );

//Store parent Vertices
vi parent( 100, 0 );

//dfsnum  of vertex with lowest dfsnum reachable from current
vi dfslow( 100, 0 );

//Whether a vertex is an Articulation Point, initialize with 0
vb ArtiP( 100, false );

//Counter to assign dfsnum to a vertex
int dfsCounter{ 0 };
vi AdjList[100];

//Root is a special case
int rootV{ 0 };
int rootChildren{ 0 };

void tarjanAPB( int u )          //This is a DFS variant
{
  dfslow[u] = dfsnum[u] = dfsCounter++;
  for( auto v : AdjList[u] )
  {
    if( dfsnum[v] == 0 )        //Either root, or unvisited vertex
    {
      if( u == rootV )         //If u is root, increase its children
        ++rootChildren;

      if( v != rootV )        //If v is not root, its unvisited
      {
        parent[v] = u;        //u is parent of v
        tarjanAPB( v );      //Visit v DFS style
      }

      //At this point v has been visited
      if( dfslow[v] >= dfsnum[u] )  //Then u is Articulation Point
        ArtiP[u] = true;
      if( dfslow[v] > dfsnum[u] )  //Then u-v is a Bridge
        printf(" Edge (%d, %d) is a bridge\n", u, v);

      //Update dfslow[u] since bidirectional edges so bi-edges
      dfslow[u] = min( dfslow[u], dfslow[v] );
    }

    //if v had been visited earlier but not parent of u,
    //then u - v is a back edge( cycle ), v is ancestor of u
    //then v is a vertex with lower dfsnum that u can reach
    else if( v != parent[u] )
      dfslow[u] = min( dfslow[u], dfsnum[v] );
  }
}

int main()
{
  int N{ 0 };                        //No of vertices
  scanf( "%d", &N );

  int temp1, temp2;               //For taking input the edges
  for( int i{0}; i < N; ++i )
  {
    scanf( "%d", &temp1 );
    while( temp1-- )
    {
      scanf( "%d", &temp2 );
      AdjList[i].push_back( temp2 );
    }
  }

  printf( "Bridges are : \n\n");
  tarjanAPB( rootV );
  printf( "\n\nArticulation Points are : \n\n");

  ArtiP[0] = ( rootChildren > 1 );  //Root is a special case
  for( int i{0}; i < N; ++i )
    if( ArtiP[i] )
      printf( " Vertex : %d\n", i );

  return 0;
}
