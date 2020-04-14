#include<iostream>
#include<cstring>
using namespace std;
int L, N;
int cuts[52];
int memo[52][52];

int cut( int l, int r )
{
  if( l + 1 == r )
    return 0;

  int &ans{ memo[l][r] };
  if( ans != -1)
    return ans;

  ans = 99999;
  for( int i{l + 1}; i < r; ++i )
    ans = min( ans, cut(l, i) + cut(i, r) + (cuts[r] - cuts[l]));
  return ans;
}

int main()
{
  while( scanf( "%d\n", &L ), L )
  {
    memset( memo, -1, sizeof(memo));
    scanf( "%d\n", &N );
    cuts[0] = 0;
    for( int i{1}; i <= N; ++i )
      scanf( "%d\n", &cuts[i] );
    cuts[N + 1] = L;

    printf( "The minimum cutting is %d.\n", cut( 0, N + 1 ) );
  }
  return 0;
}
