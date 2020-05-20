//UVa 11742 - Social Constraints
//Generate n! permutations, m conditions for each, O(m x n!)
//n <= 8 and m <= 20 = 0.8M  operations roughly

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

struct iii
{
  int a, b, c;                                   //Easier to access
};

int main() 
{
	int n, m;                                  //Problem parameters
  iii con[20];                              //Constraints
  int perm[8];                             //Permutations
  while( scanf( "%d %d", &n, &m ), n )
  {
    for( int i{ 0 }; i < m; ++i )
      scanf( "%d %d %d", &con[i].a, &con[i].b, &con[i].c );

    iota( perm, perm + n, 0 );         //Initial permutation
    int total{ 0 };                   //No of possible arrangements
    do
    {
      bool pos{ true };            //Possible or not

      for( int i{ 0 }; i < m && pos; ++i )    //Check m constraints
      {
        pos = ( con[i].c > 0 ) 
          ? ( abs( perm[con[i].a] - perm[con[i].b] ) <=  con[i].c )
          : ( abs( perm[con[i].a] - perm[con[i].b] ) >= -con[i].c ); 
      }
      total += pos;            //Adds 1 if all conditions satisfied

    }while( next_permutation( perm, perm + n ) );

    printf( "%d\n", total );
  }
 	return 0;
}													  