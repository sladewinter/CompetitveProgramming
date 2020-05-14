/*  Longest Common Subsequence using Needleman Wunsnch's algo ( DP )
Find LCS( A, B ) by modifying Wunsnch's DP algo for String Alignment
cost for mismatch = -INF, cost for match = 1, cost for insert/del = 1

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

constexpr int INF{ -999999 };                      //Negative infinity

int main()
{
  string A, B;
  cin >> A >> B;
  vvi memo( A.size() + 1, vi( B.size() + 1, 0 ) );      //Table for DP

  //Bottom up Dynamic Programming
  for( int i{ 1 }; i <= A.size(); ++i )
    for( int j{ 1 }; j <= B.size(); ++j )
    {
      memo[i][j] = memo[i - 1][j - 1] + ( A[i] == B[j] ?  1     //Match
                                                    : INF ); //Mismatch

      memo[i][j] = max(memo[i][j], max(memo[i-1][j], memo[i][j-1]));
    }

  printf("Longest Common Subsequence: %d\n", memo[A.size()][B.size()]);

  return 0;        
}

