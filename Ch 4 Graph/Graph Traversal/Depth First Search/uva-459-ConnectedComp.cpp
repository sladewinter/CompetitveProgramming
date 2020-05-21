//UVa 459 - Graph Connectivity
//Connected Components in Undirected Graph using DFS

#include <iostream>
#include <algorithm>
#include <string>
#include <regex>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

bool visited[26];                        //Distance from Source 
vvi  AdjList;                           //Adjacency List

void DFS( int u )     
{
  visited[u] = true;
  for( auto &v : AdjList[u] )
    if( !visited[v] )
      DFS(v);
}

int main()
{
  int tc;                                 //No of test cases
  string line;
  scanf( "%d\n\n", &tc );
  while( tc-- )
  {
    getline( cin, line );
    int n{ line[0] - 64 };                //No of vertices 
    AdjList.assign( n, vi() );    

    while( getline( cin, line ) )         //May contain \r
    {
      line = regex_replace( line, regex("[\r]*"), "" );
      if( line == "" )
        break;
      AdjList[line[0] - 65].push_back(line[1] - 65);
      AdjList[line[1] - 65].push_back(line[0] - 65);
    }

    int numCC{ 0 };           //No of connected components

    fill( visited, visited + n, false );

    for( int u{ 0 }; u < n; ++u )
      if( !visited[u] )
      {
        ++numCC;
        DFS(u);
      }

    printf( "%d\n", numCC );
    if( tc )
      printf( "\n" );
  }
  return 0;
}
