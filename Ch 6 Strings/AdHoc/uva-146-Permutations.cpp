//UVa 146 - ID Codes
//Permutations

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
    string code;
    while( cin >> code, code != "#" )
    {
        if( next_permutation(code.begin(), code.end()) )
            cout << code << '\n';
        else
            cout << "No Successor\n";
    }
  return 0;
}                           
