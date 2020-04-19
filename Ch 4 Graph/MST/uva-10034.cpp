//Prim's MST demonstration with an Adjacency List representation
//10034 - Freckles
//Priority Queue implementation

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
using vb = vector<bool>;
using di = pair<double, int>;
using dd = pair<double, double>;

//To prevent cycle, used vertex not considered again
vb used;

//No. of vertices
int n;

//To select edges based on increasing order of weight
priority_queue<di> pq;
double AdjList[100][100];

//Push unused neighbors of most recently visisted vertex,
//prioritized by lower cost between them
//pp is max-heap by default so push negative of weights
void process( int u )
{
  used[u] = true;               //Vertex u has now been used
  for( int v{0}; v < n; ++v )
    if( !used[v] && u != v )
      pq.push({ -AdjList[u][v], -v });  // -Weight, -Vertex format
}

double dist( dd p1, dd p2 )   //Euclidean distance
{
  return sqrt( pow( p1.first - p2.first , 2 )
           +   pow( p1.second - p2.second , 2 ) );
}

int main()
{
  int TC;
  dd freck[100];
  scanf( "%d", &TC );
  while( TC-- )
  {
    scanf("%d", &n );
    while( !pq.empty() )
      pq.pop();

    for( int i{ 0 }; i < n; ++i )
      scanf( "%lf %lf", &freck[i].first, &freck[i].second );

    for( int i{0}; i < n; ++i )
      for( int j{i}; j < n; ++j )
        AdjList[i][j] = AdjList[j][i] = dist( freck[i], freck[j] );


    used.assign( n, false );     //Initially no vertex is used
    process( 0 );              //Use vertex 0 as starting vertex
    int noEdges{ 0 };         //No of edges in MST currently
    double w{ 0 };
    double mst{ 0 };         //Current weight of MST
    int v{ 0 };

    while( !pq.empty() )
    {
      w = -( pq.top().first );
      v = -( pq.top().second );
      pq.pop();
      if( used[v] )                 //To prevent cycle
        continue;
      mst += w;
      process( v );                //Use v in MST
      ++noEdges;
      if( noEdges == n - 1 )
        break;                     //optimize
    }
    printf( "%.2lf\n", mst );
    if( TC )
      printf( "\n" );
  }
  return 0;
}
