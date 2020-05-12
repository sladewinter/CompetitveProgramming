//UVa 11151 - Longest Palindrome
//Find the longest subsequence palindrome using Bottom Up DP
//Top down DP may give deep recursion error due to 1000 length

#include <iostream>
#include <string>
#include <vector>
#include <regex>


using namespace std;

int length[1000][1000];                   //Table for Bottom Up DP

int main()
{
    int T;                                      //No of test cases
    string palin;                             //String to consider

    scanf( "%d\n", &T );
    while( T-- )                                   //New test case
    {
        getline( cin, palin );       

        //Remove carriage returns or newlines if any using regex
        palin = regex_replace( palin, regex( "[\n\r]*" ), "" );

        int len{ (int)palin.size() };    

        if( !len )                             //0 length strings   
        {
            cout << len << '\n';
            continue;
        }

        //length[l][r] needs length[l][r - 1] and length[l + 1][r]
        //So we fill table Bottom to Top and Left to Right

        for( int l{ len - 1 }; l >= 0; --l )
            for( int r{ l }; r < len; ++r )
            {
                if( l == r )          //Single digit so palindrome
                    length[l][r] = 1;
                else if( l + 1 == r )
                {
                    if( palin[l] == palin[r] ) //Either palindrome
                        length[l][r] = 2;
                    else                                  //Or not
                        length[l][r] = 1;
                }
                else
                {
                    if( palin[l] == palin[r] ) //Either palindrome

                        length[l][r] = 2 + length[l + 1][r - 1];

                    else                                  //Or not

                        length[l][r] = max( length[l + 1][r]
                                        , length[l][r - 1] );
                }
            }
            cout << length[ 0 ][ len - 1 ] << '\n';
    }
    return 0;
}