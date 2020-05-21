//UVa 11902 - Dominator
//Breadth First Search

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
using vi = vector<int>;

constexpr int INF{ 999999999 };
int dist[100];                           //Distance from Source 
vi  AdjList[100];                       //Adjacency List
int N;                                 //No of vertices

void dominator( int source, int skip )         //Modified BFS
{
  fill( dist, dist + N, INF );               //Safer than memset
  dist[source] = 0;
  queue<int> que;
  que.push(source);

  while( !que.empty() )
  {
    int u{ que.front() };
    que.pop();
    for( auto &v : AdjList[u] )
      if( dist[v] == INF && v != skip )     
      {
        dist[v] = dist[u] + 1;
        que.push(v);
      }
  }
}

void printLine( int N )
{
  printf( "+" );
  for( int i{0}; i < 2*N - 1; ++i )
    printf( "-");
  printf( "+\n");
}

int main()
{
  int T;                               //Problem parameter
  int caseNo{ 0 };                    //For printing purpose
  int edge{ 0 };                     //Whether 2 vertices have edge
  char output[100][100];            //For printing purpose

  scanf( "%d\n", &T );
  while( T-- )
  {
    scanf( "%d\n", &N );

    for( int i{0}; i < N; ++i )
    {
      AdjList[i].clear();
      for( int j{0}; j < N; ++j )
        if( scanf( "%d\n", &edge ), edge )
          AdjList[i].push_back(j);
    }
    
    //Run bfs(0) on graph to record vertices reachable from vertex 0
    dominator(0, -1);
    
    //Check which vertices unreachable from source
    memset( output, 'Y', sizeof(output) );
    for( int i{0}; i < N; ++i )
      if( dist[i] == INF )
        for( int j{0}; j < N; ++j )
          output[j][i] = 'N';

    //Turn off all the outgoing edges of vertex i and rerun bfs(0)
    for( int i{1}; i < N; ++i )
    {
      dominator( 0, i );
      for( int j{0}; j < N; ++j )
        if( dist[j] != INF && i != j )
          output[i][j] = 'N';
    }

    printf( "Case %d:\n", ++caseNo );
    printLine( N );
    for( int i{0}; i < N; ++i )
    {
      for( int j{0}; j < N; ++j )
        printf( "|%c", output[i][j] );
      printf( "|\n" );
      printLine( N );
    }
  }
  return 0;
}
