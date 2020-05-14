/*  String Alignment(Edit Distance) using Needleman Wunsnch's algo (DP)
Align strings A and B with max alignment score(or minimum no. of edits)

  Test case:
  ACAATCC
  AGCATGC                                                           
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main()
{
  string A, B;
  cin >> A >> B;
  vvi memo( A.size() + 1, vi( B.size() + 1, 0 ) );      //Table for DP

  //Base cases of DP
  for( int i{ 1 }; i <= A.size(); ++i )
    memo[i][0] = -1 * i;                   //delete substring A[1..i]

  for( int j{ 1 }; j <= B.size(); ++j )
    memo[0][j] = -1 * j;                   //insert spaces in B[1..j]

  //Bottom up Dynamic Programming
  int option1, option2, option3;
  for( int i{ 1 }; i <= A.size(); ++i )
    for( int j{ 1 }; j <= B.size(); ++j )
    {
      option1 = memo[i - 1][j - 1] + ( A[i] == B[j] ?  2     //Match
                                                    : -1 ); //Mismatch
      
      option2 = memo[i-1][j] - 1;      //Delete A[i]
      option3 = memo[i][j-1] - 1;     //Insert B[j] = spaces

      memo[i][j] = max( option1, max(option2, option3) );  //Best of 3
    }

  printf("Maximum Alignment Score: %d\n", memo[A.size()][B.size()]);

  return 0;        
}

