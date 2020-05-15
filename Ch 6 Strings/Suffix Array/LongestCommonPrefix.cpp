/* Longest Common Prefix between consecutive Suffixes in a String using
   Permuted Longest Common Prefix Theorem & Suffix Array Data Structure

   Test case:
   GATAGACA
*/

#include <iostream>
#include <string>
#include "SuffixArray.h"

using namespace std;

vi LCP( string input )
{
  SuffixArray SA( input );
  const char *T{ input.c_str() };

  //Phi[i] stores index of previous suffix of SA[i] in SA
  vi Phi(  SA.size() );      

  //LCP[i] stores Longest Common Prefix of Suffixes i and i-1 in SA 
  vi LCP(  SA.size() );

  //PLCP[i] stores LCP of suffix i in original order, not SA order
  vi PLCP( SA.size() );

  Phi[ SA[0] ] = -1;               //No suffix precedes SA[0] in SA

  for( int i{ 1 }; i < SA.size(); ++i )
    Phi[ SA[i] ] = SA[i - 1];                //Compute this in O(n)

  int L{ 0 };              //Track increase/decrease in prefix size


  //L increase/decrease atmost N = SA.size() times so O(N) for this
  for( int i{ 0 }; i < SA.size(); ++i )
  {
    if( Phi[i] == -1 )                    //Special case, i = SA[0]
    {
      PLCP[i] = 0;
      continue;
    }
    while( T[i + L] == T[Phi[i] + L] )    //Length of Common Prefix 
      ++L;                               //L increased max N times

    PLCP[i] = L;              

    L = max( L - 1, 0 );              //L decreased max N times
  }

  for( int i{ 0 }; i < SA.size(); ++i )
    LCP[i] = PLCP[ SA[i] ];             //LCP[i] for position in SA

  return LCP;
}

int main()
{
  string input;
  cin >> input;

  auto lcp{ LCP( input ) };              //Get vector<int> LCP back

  for( auto &element : lcp )
    cout << element << ' ';
  cout << '\n';
  
  return 0;        
}

