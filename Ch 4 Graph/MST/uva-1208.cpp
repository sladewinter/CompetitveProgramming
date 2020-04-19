//Prim's MST demonstration with an Adjacency List representation
//UVa 1208 - Oreon - Input is in Adjacency Matrix representation
//Priority Queue implementation

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using viii = vector<iii>;
using vb = vector<bool>;
using vii = vector<ii>;
using vvii = vector<vii>;

//To prevent cycle, used vertex not considered again
vb used;

//To select edges based on increasing order of weight
priority_queue<iii> pq;
vvii AdjList;

//Push unused neighbors of most recently visisted vertex,
//prioritized by lower cost between them
//pp is max-heap by default so push negative of weights
void process( int u )
{
  used[u] = true;               //Vertex u has now been used
  for( auto &v : AdjList[u] )
    if( !used[ v.first ])       //If v has not been used
      pq.push({-v.second, -u, -v.first}); //-Weight,-Source,-Dest
}

int main()
{
  int TC, N;
  int caseNo{ 0 };
  scanf( "%d", &TC );
  while( TC-- )
  {
    scanf("%d", &N );
    while( !pq.empty() )
      pq.pop();
    AdjList.assign( N, vii() );
    int w;
    for( int i{ 0 }; i < N; ++i )
      for( int j{ 0 }; j < N; ++j )
      {
        if( j > 0 )
          scanf( ", " );
        scanf( "%d", &w );
        if( w > 0 )
          AdjList[i].emplace_back( j, w );
      }

    printf( "Case %d:\n", ++caseNo );

    used.assign( N, false );     //Initially no vertex is used
    process( 0 );              //Use vertex 0 as starting vertex
    int noEdges{ 0 };         //No of edges in MST currently
    int s, d;

    //This is just to display output in sorted order
    viii output( N - 1 );
    while( !pq.empty() )
    {
      tie( w, s, d ) = pq.top();    //-Weight, -Source, -Dest
      w = -w; s = -s; d = -d;
      pq.pop();
      if( used[d] )                 //To prevent cycle
        continue;
      process( d );                //Use d in MST
      if( s > d )
        swap( s, d );             //For sorting output
      output[ noEdges++ ] = { w, s, d };
      if( noEdges == N - 1 )
        break;                     //optimize
    }
    sort( output.begin(), output.end() );
    for( auto &element : output )
    {
      tie( w, s, d ) = element;
      printf( "%c-%c %d\n", 'A' + s, 'A' + d, w );
    }
  }
  return 0;
}
