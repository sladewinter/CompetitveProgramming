#include<iostream>
#include<cstring>
using namespace std;
int memo[101][101];

int ways( int n, int k )
{
  if( k == 1 )
    return 1;

  int &ans{ memo[n][k] };
  if( ans != -1 )
    return ans;

  ans  = 0;
  for( int i{0}; i <= n; ++i )
      ans = (ans + ways( n - i, k - 1 )) % 1000000;
      
  return ans;
}

int main()
{
  int N, K;
  memset( memo, -1, sizeof(memo) );
  while( scanf( "%d %d\n", &N, &K ), N || K )
  {
    printf( "%d\n", ways( N, K ) );
  }
  return 0;
}
