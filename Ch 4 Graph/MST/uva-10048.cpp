//Kruskal's MST implementation - Edge List representation
//Modified DFS implementation  - Adjacency List representation
//MiniMax variant of MST

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <cstring>
#include <utility>

using namespace std;

using vi   = vector<int>;
using iii  = tuple<int, int, int>;
using vii  = vector< pair<int, int> >;
using vvii = vector<vii>;

vvii MST;                                 //MST is Adjacency List
bool visited[101];                      
int global_max{ 0 };                

class UnionFind
{
private:
  vi parent, rank;
public:
  UnionFind( int N )                     //N = No. of vertices
  {
    parent.assign( N, 0 );               //Set representative
    for( int i{0}; i < N; ++i )
      parent[i] = i;

    rank.assign( N, 0 );                 //For Union by Rank
  }

  int find( int u )
  {
    return ( parent[u] == u )
           ? u
           : ( parent[u] = find( parent[u] ) ); //Path compression
  }

  void unionSet( int u, int v )
  {
    int pu = find( u );                   //Parent of u
    int pv = find( v );                   //Parent of v
    if( pu == pv )                        //Already same set
      return;
    if( rank[pu] > rank[pv] )
      swap( pu, pv );                    //Keep pu shorter
    parent[pu] = pv;                     //Union by rank
    if( rank[pu] == rank[pv] )
      ++rank[pv];                        //Increase rank of pv
  }
};

void modified_dfs( int u, int v, int curr_max )
{
    visited[u] = true;
 
    for( auto &element : MST[u] )
    {
        if( element.first == v )             //We have reached target
        {
           global_max = max( curr_max, element.second );   //Return to main
           return;
        }
        if( !visited[element.first] && !global_max )   //if not reached target
            modified_dfs( element.first, v,
                          max(curr_max, element.second) ); //DFS
    }
}

int main()
{
	freopen( "input", "r", stdin );
	iii EdgeList[ 1001 ];
    int C, S, Q;
    int caseNo{ 0 };
    bool first{ 1 };
    while( scanf( "%d %d %d", &C, &S, &Q ), C | S | Q )
    {
        first ? ( first = 0 ) : printf( "\n" );
        int u, v, d;
        
        for( int i{0}; i < S; ++i )
        {
            scanf( "%d %d %d", &u, &v, &d );
            --u; --v;
            EdgeList[i] = { d, u, v };
        }

        sort( EdgeList, EdgeList + S );
        printf( "Case #%d\n", ++caseNo );

        UnionFind UF{ C };
        MST.assign( C, vii() );
        int E;                                   //No of edges in MST
        for( int i{0}; i < S; ++i )
        {
        	tie( d, u, v ) = EdgeList[i];
        	if( UF.find( u ) == UF.find( v ) )   
        		continue;                        //Prevent cycle
        	++E;
        	MST[u].emplace_back( v, d );
        	MST[v].emplace_back( u, d );
        	UF.unionSet( u, v );
        	if( E == C - 1 )
        		break;                           //Early stopping
        }

        //Now we have MST connecting vertices, will traverse using DFS
        for( int i{0}; i < Q; ++i )
        {
            memset( visited, 0, sizeof( visited ));
            scanf( "%d %d", &u, &v );
            --u; --v;
            global_max = 0; 
            modified_dfs( u, v, 0 );
            if( !global_max )                   //Disconnected graph
                printf( "no path\n" );
            else
                printf( "%d\n", global_max );
        }
    }
    return 0;
}

