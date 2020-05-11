//UVa 325 - Identifying Legal Pascal Real Constants
//Demonstrate how to use Regular Expressions with Strings

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    string candidate;       //For taking input each candidate string

    //Define the pattern we need to match
    regex exp{ "[-+]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)" }; 

    //Get input line by line
    while( getline( cin, candidate ) )
    {
        //Trim leading spaces using regex_replace
        candidate = regex_replace( candidate, regex( "^\\s+" ), "" );

        //Trim folowing spaces using regex_replace
        candidate = regex_replace( candidate, regex( "\\s+$" ), "" );

        if( candidate == "*" )                  //Last string in file
            break;

        cout << candidate << " is ";

        //Match with our predefined pattern
        regex_match( candidate, exp ) ? cout << "legal.\n"
                                      : cout << "illegal.\n";
    }
}