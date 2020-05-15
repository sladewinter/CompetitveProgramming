/* Longest Repeated Substring in a String using LCP and Suffix Array DS
   Once we get LCP, we find length of LRS = Largest item in LCP in O(n)

   Test case:
   GATAGACA
*/

#include <iostream>
#include <string>
#include "SuffixArray.h"

using namespace std;

//For details of LCP implementation refer LongestCommonPrefix.cpp
int LRS( string input )
{
  SuffixArray SA( input );

  const char *T{ input.c_str() };
  vi Phi(  SA.size() );        

  Phi[ SA[0] ] = -1;               //No suffix precedes SA[0] in SA

  for( int i{ 1 }; i < SA.size(); ++i )
    Phi[ SA[i] ] = SA[i - 1];                //Compute this in O(n)

  int L{ 0 };              //Track increase/decrease in prefix size
  int lrs{ 0 };           //Max value of L will give us LRS

  for( int i{ 0 }; i < SA.size(); ++i )
  {
    if( Phi[i] == -1 )                    //Special case, i = SA[0]
      continue;

    while( T[i + L] == T[Phi[i] + L] )    //Length of Common Prefix 
      ++L;                               //L increased max N times

    lrs = max( lrs, L );               //Just store max( PLCP[i] )
    L   = max( L - 1, 0 );            //L decreased max N times
  }

  return lrs;                       //Have to fill PLCP to print LRS
}

int main()
{
  string input;
  cin >> input;

  printf( "Longest Repeated Substring length = %d\n", LRS( input ) );

  return 0;        
}

