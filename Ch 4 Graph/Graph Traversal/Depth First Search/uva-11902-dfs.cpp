//UVa 11902 - Dominator
//Depth First Search

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

using vi = vector<int>;

int visited[100];
vi  AdjList[100];

void printLine( int N )
{
  printf( "+" );
  for( int i{0}; i < 2*N - 1; ++i )
    printf( "-");
  printf( "+\n");
}

void DFS( int u )
{
  visited[u] = 1;
  for( auto &v : AdjList[u] )
    if( !visited[v] )
      DFS( v );
}

//Modified DFS which skips the skip vertex and its edges
void dominator( int u , int skip )
{
  visited[u] = 1;
  for( auto &v : AdjList[u] )
    if( !visited[v] && v != skip )
      dominator( v, skip );
}

int main()
{
  int TC, N;
  int caseNo{ 0 };
  int graph{ 0 };
  char output[100][100];
  scanf( "%d\n", &TC );
  while( TC-- )
  {
    scanf( "%d\n", &N );

    for( int i{0}; i < N; ++i )
    {
      AdjList[i].clear();
      for( int j{0}; j < N; ++j )
        if( scanf( "%d\n", &graph ), graph )
          AdjList[i].push_back(j);
    }

    memset( visited, 0, sizeof( visited ) );
    memset( output, 'Y', sizeof( output ) );

    //Run dfs(0) on graph to record vertices reachable from vertex 0
    DFS( 0 );
    for( int i{0}; i < N; ++i )
      if( !visited[i] )
        for( int j{0}; j < N; ++j )
          output[j][i] = 'N';

    //Turn off all the outgoing edges of vertex i and rerun dfs(0)
    for( int i{1}; i < N; ++i )
    {
      memset( visited, 0, sizeof( visited ) );
      dominator( 0, i );
      for( int j{0}; j < N; ++j )
        if( visited[j] && i != j )
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
