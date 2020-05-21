//UVa 469 - Wetlands of Florida
//Flood Fill using DFS

#include<iostream>
#include<cstring>

using namespace std;
int  R, C;
char graph[100][100];

int floodFill( int r, int c, char c1, char c2 )
{
  //{ S, SE, E, NE, N, NW, W, SW }
  static int dr[] = { 1, 1, 0, -1, -1, -1,  0,  1};
  static int dc[] = { 0, 1, 1,  1,  0, -1, -1, -1};
  if( r < 0 || r >= R || c < 0 || c >= C )
    return 0;
  if( graph[r][c] != c1 )
    return 0;
  int ans = 1;
  graph[r][c] = c2;
  for( int i{0}; i < 8; ++i )
    ans += floodFill( r + dr[i], c + dc[i], c1, c2 );
  return ans;
}

int main()
{
  int TC, row, column;
  scanf( "%d\n", &TC );
  while( TC-- )
  {
    R = -1;
    C = 0;
    do
    {
      cin.getline( graph[++R], 100 );
    } while( graph[R][0] == 'L' || graph[R][0] == 'W' );

    C = strlen( graph[0] );

    while( strcmp( graph[R], "" ) )
    {
      sscanf( graph[R], "%d %d", &row, &column );
      --row; --column; //Our index starts from 0, but 1 in question
      printf( "%d\n", floodFill( row, column, 'W', 'X' ) );
      floodFill( row, column, 'X', 'W' ); //Restore
      cin.getline( graph[R], 100 );
    }

    if(TC)
      printf( "\n" );
  }
  return 0;
}
