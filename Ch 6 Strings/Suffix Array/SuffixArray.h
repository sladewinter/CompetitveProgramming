#include <iostream>
#include <string>
#include <vector>
#include <numeric>                   

using namespace std;
using vi = vector<int>;

#ifndef SUFFIX_ARRAY
#define SUFFIX_ARRAY

class SuffixArray
{
  string m_input;                  
  int len;
  vi SA, RA;                   

  void countingSort( int k )           //Stable version
  {
    constexpr int maxN{ 128 };
    vi count( maxN, 0 );            //Frequency table for 128 +ve chars

    //Count the frequencies
    for( int i{ 0 }; i < len; ++i )
      ( i + k < len ) ? ++count[ RA[i + k] ]  //Within length of suffix
                      : ++count[ 0 ];        //Beyond length of suffix

    //Cumulate frequencies for stable sort
    int sum { 0 };
    int temp{ 0 };                    
    for( int i{ 0 }; i < maxN; ++i )
    {
      temp = count[i];
      count[i] = sum;
      sum += temp;
    }

    //Stable sort Suffix Array according to current Rank Array
    vi tempSA( len );
    for( int i{ 0 }; i < len; ++i )
       (SA[i] + k < len) ? tempSA[ count[ RA[SA[i] + k] ]++ ] = SA[i]
                         : tempSA[ count[ 0 ]++ ] = SA[i];

    SA = tempSA;                                 //Update Suffix Array
  }

public:
  SuffixArray( const string &input ) : m_input{ input + '$' }
  {
    len = m_input.size();
    SA.resize( len );
    iota( SA.begin(), SA.end(), 0 );            //Initial Suffix Array
    
    RA.resize( len );
    for( int i{ 0 }; i < len; ++i )
      RA[i] = m_input[i];                  //Initially Ranked on ASCII
 
    for( int k{ 1 }; k < len; k <<= 1 )          //k doubles each time
    {
      //2 pass radix sort
      countingSort( k );           //Sort Suffixes on Rank of kth char
      countingSort( 0 );          //Stable sort on Rank of 0th char

      //Re-ranking procedure
      int rank{ 0 };
      vi tempRA( len );
      tempRA[ SA[0] ] = rank;              //1st item in SA gets 0 Rank

      for( int i{ 1 }; i < len; ++i )
        ( RA[ SA[i] ] == RA[ SA[i - 1] ]                //Same 0th char 
          && RA[ SA[i] + k ] == RA[ SA[i - 1] + k ] )  //Same kth char
                       ?  tempRA[ SA[i] ] = rank      //Then same Rank
                       :  tempRA[ SA[i] ] = ++rank;  //Else increase

      RA = tempRA;                                 //Update Rank Array

      if( RA[ SA[len - 1] ] == len - 1 )  //All of them got diff ranks
        break;                           //Early stopping optimization
    }
  }

  void print()                                //Print out Suffix Array
  {
    for( auto &pos : SA )
      cout << m_input.substr( pos, len - pos ) << '\n';
  }
};

#endif
