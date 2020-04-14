#include<iostream>
#include<cstring>
using namespace std;

int main()
{
  int N, K;
  int memo[101][101];
  memset( memo, 0, sizeof(memo) );
  for( int n{0}; n <= 100; ++n )
    for( int k{1}; k <= 100; ++k )
    {
      if( k == 1 )
        memo[n][k] = 1;
      else
        for( int i{0}; i <= n; ++i )
          memo[n][k] = (memo[n][k] + memo[n - i][k - 1]) % 1000000;
    }

  while( scanf( "%d %d\n", &N, &K ), N || K )
    printf( "%d\n", memo[N][K] );

  return 0;
}
