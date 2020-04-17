//For details and clarificattions refer articulP.cpp

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;

vi dfsnum, dfslow;

//A flag to set / check whether vertex is within stack
vb inStack;

//Assign discovery time to dfsnum using this counter
int dfsCounter{ 0 };

//Keeps count of no. of connected components
int numSCC{ 0 };
vvi AdjList;
stack<int> st;

void tarjanSCC( int u )
{
  dfslow[u] = dfsnum[u] = ++dfsCounter;

  st.push(u);
  inStack[u] = 1;              //Vertex u is within stack

  for( auto v : AdjList[u] )
  {
    if( dfsnum[v] == 0 )      //Not visited yet
      tarjanSCC(v);

    //If vertex v is currently in stack, this is a back edge
    if( inStack[v] )
      dfslow[u] = min( dfslow[u], dfslow[v] );
  }

  //By this point recursion unwinds completely and returns
  if( dfslow[u] == dfsnum[u] ) //Head of a new component
  {
    ++numSCC;                 //Increase no of components
    while(1)
    {
      int v = st.top();
      st.pop();              //Pop elements from stack
      inStack[v] = 0;        //v not in stack anymore
      if( u == v )           //Head of component now popped out
        break;               //so resume normal execution
    }
  }
}

int main()
{
  int N, M, V, W, P;
  while( scanf( "%d %d", &N, &M ), N || M )
  {
    AdjList.assign( N, vi() );
    while( M-- )
    {
      scanf("%d %d %d", &V, &W, &P );
      //Indices start from 1 in question, convert to 0
      --V; --W;
      AdjList[V].push_back( W );
      if( P == 2 )
         AdjList[W].push_back( V );
    }

    dfsCounter = numSCC = 0;
    while( !st.empty() )
      st.pop();
    dfsnum.assign( N, 0 );
    dfslow.assign( N, 0 );
    inStack.assign( N, 0 );

    for( int i = 0; i < N; ++i )
      if( dfsnum[i] == 0 )          //Not visited yet
        tarjanSCC( i );

    printf( "%d\n", ( numSCC == 1 ) );
  }
  return 0;
}
