#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;
using vi = vector<int>;

int main()
{
  int N, M, temp1, temp2;
  int caseNo{ 0 };
  int inDegree[100];
  char buffer1[60], buffer2[60];
  unordered_map<string, int> str2int;
  unordered_map<int, string> int2str;

  while( scanf("%d", &N ) != EOF )
  {
    str2int.clear();
    int2str.clear();
    memset( inDegree, 0, sizeof( inDegree ) );
    vector<vi> AdjList( N, vi() );

    for( int i{ 0 }; i < N; ++i )
    {
      scanf( "%s", buffer1 );
      str2int[ static_cast<string>(buffer1) ] = i;
      int2str[ i ] = static_cast<string>(buffer1);
    }

    scanf("%d", &M );
    for( int i{ 0 }; i < M; ++i )
    {
      scanf( "%s %s", buffer1, buffer2 );
      temp1 = str2int[ static_cast<string>(buffer1) ];
      temp2 = str2int[ static_cast<string>(buffer2) ];
      AdjList[ temp1 ].push_back( temp2 );
      ++inDegree[ temp2 ];
    }

    printf( "Case #%d: Dilbert should drink beverages in this order:", ++caseNo );

    //This is alternate constructor for implementing
    //pq as Min-heap. By default its Max-heap.
    priority_queue<int, vi, greater<int>> pq;
    for( int i{ 0 }; i < N; ++i )
      if( inDegree[i] == 0 )
        pq.push(i);

    while( !pq.empty() )
    {
      int temp1 = pq.top();
      pq.pop();
      printf( " %s", int2str[ temp1 ].c_str() );
      for( auto &v : AdjList[temp1] )
      {
        --inDegree[v];
        if( inDegree[v] == 0 )
          pq.push(v);
      }
    }
    printf( ".\n\n" );
  }
  return 0;
}
