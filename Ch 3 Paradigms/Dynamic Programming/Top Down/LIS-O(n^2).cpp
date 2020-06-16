//Longest Increasing Subsequence
//1 + 2 + 3 + 4 + .... + n = O(n^2) so may give TLE
//Check uva-481-O(nlgk).cpp in Bottom Up Folder for O(nlgk) AC solution

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using vi = vector<int>;

vi arr{ -7, 10, 9, 2, 3, 8, 8, 6 };

vi parent;             //Parent array for "global" LIS
vi memo;              //Memoization table for DP
int last;            //Last item in "global "LIS
int llen{1};        //Length of "global" LIS

//"Local" LIS start @ index 0 & end @ index i, O(i)
//Gets called only once for each i
void LIS( int i )    
{
    if( i == 0 )      //start & end @ 0 is len 1, base case
    {
        memo[i] = 1;
        return; 
    }

    LIS( i - 1 );  //Recursively call "local" LIS ends @i-1
    memo[i] = 1;  //Initialize length of "local" LIS

    //Check if "local" LIS length can be increased
    for( int j{0}; j < i; ++j )  
    {
        // >= tracks latest "global" LIS in input, > tracks earliest
        if( arr[j] < arr[i] && 1 + memo[j] >= memo[i] )
        {
            memo[i] = 1 + memo[j];      //Update length
            parent[i] = j;             //Printing parent
        }
    }

    // >= tracks ending of latest "global" LIS, > tracks earliest
    if( memo[i] >= llen )
    {
        llen = memo[i];       //Update "global" LIS len
        last = i;            //Update last item in "global" LIS
    }
}

void backtrack( int i )  //Print "global" LIS recursively
{
    if( i != parent[i] )
        backtrack( parent[i] );
    printf( "%d\n", arr[i] ); 
}

int main()
{
    memo.assign( arr.size(), -1 );
    parent.resize(arr.size());
    iota(parent.begin(), parent.end(), 0);

    //Recursively calculate "local" LIS starting at n-1 index
    LIS( arr.size() - 1 );

    printf( "%d\n-\n", llen );         //"global" LIS length

    //Backtrack & print "global" LIS starting from last item
    backtrack(last);
    return 0;
}

