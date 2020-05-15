/* Longest Repeated Substring in a String using LCP and Suffix Array DS
   Once we get LCP, we find length of LRS = Largest item in LCP in O(n)

   Test case:
   GATAGACA
*/

#include <iostream>
#include <string>
#include <algorithm>
#include "SuffixArray.h"

using namespace std;

int main()
{
  string input;
  cin >> input;

  SuffixArray SA( input );
  auto lcp = SA.LCP();                           //Get the LCP vector

  int lrs{ *max_element( lcp.begin(), lcp.end() ) };   

  printf( "Length of LRS = %d\n", lrs );         //Print LRS length
  printf( "Longest Repeated Substring :\n" );

  for( int i{ 0 }; i < SA.size(); ++i )          //Print out the LRS
  	if( lcp[i] == lrs )             
 		cout << input.substr( SA[i], lrs ) << '\n';

  return 0;        
}

