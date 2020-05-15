/* Longest Common Substring of 2 strings by concatenating them & find LCP
   LCS = max(LCP[i]) such that SA[i] & SA[i-1] belong to separate strings

   Test case:
   GATAGACA
   CATA
*/

#include <iostream>
#include <string>
#include "SuffixArray.h"

using namespace std;

int main()
{
  string str1, str2;
  cin >> str1 >> str2;

  //Use separate terminating character '#' for str1 and '$' for str2
  string concatd{ str1 + '#' + str2 };

  SuffixArray SA( concatd );
  auto lcp = SA.LCP();                           //Get the LCP vector

  int split_idx{ (int)str1.size() + 1 };       //str1 ends, str2 begins

  int maxi{ -1 };                            //Length of LCS
  int idx {  0 };                           //Index of LCS

  for( int i{ 0 }; i < SA.size(); ++i )   
  {
  	//skip if suffix SA[i] and suffix SA[i-1] came from same string
    if ((SA[i] < split_idx) == (SA[i-1] < split_idx)) 
      continue;

    if( maxi < lcp[i] )
    {
      maxi = lcp[i];                 //Longest length of LCS yet
      idx = i;                      //Store the index
    }
  }

  printf( "Longest Common Substring :\n" );
  cout << concatd.substr( SA[idx], maxi ) << '\n';

  return 0;        
}

