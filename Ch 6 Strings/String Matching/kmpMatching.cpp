/* String Matching using Knuth-Morris-Pratt’s Algorithm

  Test case:
  I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN
  SEVENTY SEVEN
*/

#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;
using vi = vector<int>;

vi backTable;
void kmpPreprocess( string pattern )               
{
  backTable.resize( pattern.size() + 1 );
  int i{  0 };                             //i iterates through pattern
  int j{ -1 };               //j = no of contiguous characters repeated
  backTable[0] = -1;        //Value of j till index i

  while( i < pattern.size() )             
  {
    while( j >= 0 && pattern[i] != pattern[j] ) //Not repeated anymore
      j = backTable[j];                        //So set j back 

    ++i; ++j;                         
    backTable[i] = j;
  }
}

void kmpSearch( string pattern, string text )
{
  int i{ 0 };                             //i iterates through text
  int j{ 0 };                            //j = iterates through pattern

  while( i < text.size() )             
  {
    while( j >= 0 && text[i] != pattern[j] )     //Not matching anymore
      j = backTable[j];                         //So set j back 

    ++i; ++j;                        //Increment both to next character
    if( j == pattern.size() )       //We finally found 1 match in text
    {
      printf( "Pattern is found at index %d in Text\n", i - j );
      
      j = backTable[j];          //Prepare j for next match
    }
  }
}


int main()
{
  string text, pattern;
  getline( cin, text );
  getline( cin, pattern );

  //Remove newlines or carriage returns if any got appended
  text = regex_replace( text, regex( "[\n\r]*" ), "" );
  pattern = regex_replace( pattern, regex( "[\n\r]*" ), "" );

  kmpPreprocess( pattern );        //Prepare the back table
  kmpSearch( pattern, text );     //Search text for pattern

  return 0;        
}
