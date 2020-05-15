/* String Matching using Suffix Array

  Test case:
  I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN
  SEVENTY SEVEN
*/

#include <iostream>
#include <string>
#include <cstring>
#include <regex>
#include "SuffixArray.h"
#include "SuffixArray.h"

using namespace std;

//Bsearches take O( logn ) each and strcmp takes O( m ) so O( m logn )
void stringMatching( string text, string pattern )
{
  //For our ease of coding     
  int p_size{ static_cast<int>( pattern.size() ) };      
  const char *T{ text.c_str() };                     //C string text
  const char *P{ pattern.c_str() };                 //C string pattern

  SuffixArray SA( text );                     //Create Suffix Array SA
  int lo{ 0 };                               //Smallest index 
  int hi{ SA.size() - 1 };                  //Largest index
  int mid{ ( lo + hi ) / 2 };
  int res{ 0 };                           //Store a comparision

  while( lo < hi )                     //Binary search for lower bound 
  {
    res = strncmp( T + SA[mid], P, p_size ); //Find P in suffix SA[mid]

    if( res >= 0 )                //SA[mid] >= pattern 
      hi = mid;                  //But we need lower bound so continue
    else                        //SA[mid] < pattern
      lo = mid + 1;            //So prune lower half, search in upper

    mid = ( lo + hi ) / 2;    
  }

  if( strncmp( T + SA[lo], P, p_size ) != 0 )             //Not found
  { 
    printf("%s is not found in %s\n", P, T);
    return;
  }

  int lower_bound{ lo };

  lo = 0; hi = SA.size() - 1;         //Reset lo, hi and mid
  mid = ( lo + hi ) / 2;

  while( lo < hi )                     //Binary search for upper bound 
  {
    res = strncmp( T + SA[mid], P, p_size ); //Find P in suffix SA[mid]

    if( res > 0 )                 //SA[mid] > pattern 
      hi = mid;                  //So prune upper half, search in lower
    else                        //SA[mid] <= pattern
      lo = mid + 1;            //So prune lower half, search in upper

    mid = ( lo + hi ) / 2;    
  }

  if( strncmp( T + SA[hi], P, p_size ) != 0 )    //Not matching with hi
    --hi;

  int upper_bound{ hi };

  for (int i = lower_bound; i <= upper_bound; ++i)
     printf( "Pattern is found at index %d in Text\n", SA[i] );
}

int main()
{
  string text, pattern;
  getline( cin, text );
  getline( cin, pattern );

  //Remove newlines or carriage returns if any got appended
  text = regex_replace( text, regex( "[\n\r]*" ), "" );
  pattern = regex_replace( pattern, regex( "[\n\r]*" ), "" );
  stringMatching( text, pattern );
  
  return 0;        
}

