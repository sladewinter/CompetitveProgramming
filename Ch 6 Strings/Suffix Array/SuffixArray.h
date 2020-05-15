/* Suffix Array implementation alongwith Longest Common Prefix */

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

  vi LCP()
  {
    const char *T{ m_input.c_str() };
  
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
 
  int size() { return SA.size(); }              //Suffix Array size

  int operator[]( int i ) { return SA[ i ]; }  //Return index element

  void print()                                //Print out Suffix Array
  {
    for( auto &pos : SA )
      cout << m_input.substr( pos, len - pos ) << '\n';
  }
};

#endif
