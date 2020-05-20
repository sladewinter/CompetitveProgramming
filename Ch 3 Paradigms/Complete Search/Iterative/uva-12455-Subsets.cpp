//UVa - 12455 - Bars
//Generate 2^p subsets, sum elements of each subset, O(p x 2^p)
//p <= 20 so 20 x 2^20 = 21M operations, fast enough using bitmask

#include <iostream>

using namespace std;

int main() 
{
  int t, n, p;                                //Problem parameters
  int bar[20];                               //Store length of bars
  
  scanf( "%d", &t );
  while( t-- )
  {
    scanf( "%d\n%d", &n, &p );
    for( int i{ 0 }; i < p; ++i )
      scanf( "%d", &bar[i] );                 //Input bar length

    int noSubsets{ 1 << p };                //Total no of subsets 
    bool solved{ false };

    for( int s{ 0 }; s < noSubsets; ++s ) //Generate all susets
    {
      int sum{ 0 };
      for( int i{ 0 }; i < p; ++i )     //Iterate all bars
        if( s & ( 1 << i ) )           //Bar[i] present in subset s
          sum += bar[i];              //Add its length

      if( sum == n )                //Got a solution
      {
        solved = true;
        break;
      }
    }
    solved ? printf( "YES\n" ) : printf( "NO\n" );
  }  
 	return 0;
}													  