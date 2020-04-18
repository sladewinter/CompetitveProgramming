#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;

int main()
{
  int n, l, temp1, temp2;
  bool bipartite{ 0 };
  while( scanf( "%d", &n ), n )
  {
    bipartite = 1;
    vector<vi> AdjList( n, vi() );
    vi colors( n, 999 );
    queue<int> que{};
    scanf( "%d", &l );
    while( l-- )
    {
      scanf( "%d %d", &temp1, &temp2 );
      AdjList[ temp1 ].push_back( temp2 );
      AdjList[ temp2 ].push_back( temp1 );
    }

    que.push( 0 );
    colors[0] = 0;

    while( !que.empty() && bipartite )
    {
      int u = que.front();
      que.pop();
      for( auto &v : AdjList[u] )
      {
        if( colors[v] == 999 )
        {
          colors[v] = 1 - colors[u];
          que.push(v);
        }
        else if( colors[v] == colors[u] )
        {
          bipartite = 0;
          break;
        }
      }
    }


    if( bipartite )
      printf( "BICOLORABLE.\n" );
    else
      printf( "NOT BICOLORABLE.\n" );

  }
  return 0;
}
