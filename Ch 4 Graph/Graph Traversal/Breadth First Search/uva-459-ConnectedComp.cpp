//UVa 459 - Graph Connectivity
//Connected Components in Undirected Graph using BFS

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <regex>
#include <queue>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
constexpr int INF{ 999999999 };

int dist[26];                            //Distance from Source 
vvi  AdjList;                           //Adjacency List

void BFS( int source )     
{
  dist[source] = 0;
  queue<int> que;
  que.push(source);

  while( !que.empty() )
  {
    int u{ que.front() };
    que.pop();
    for( auto &v : AdjList[u] )
      if( dist[v] == INF )     
      {
        dist[v] = dist[u] + 1;
        que.push(v);
      }
  }
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

    fill( dist, dist + n, INF );

    for( int u{ 0 }; u < n; ++u )
      if( dist[u] == INF )
      {
        ++numCC;
        BFS(u);
      }

    printf( "%d\n", numCC );
    if( tc )
      printf( "\n" );
  }
  return 0;
}
