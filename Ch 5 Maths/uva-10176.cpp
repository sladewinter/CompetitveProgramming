//UVa 10176 - Ocean Deep! - Make it shallow!!
//Check whether very large binary no.( 100 digits ) divisible by 131071
//Just keep storing the modulo 131071 of the input in decimal till no. ends

#include <iostream>

using namespace std;

int main()
{
    char input{};                            //Take input char by char
    int decimal{ 0 };                       //Store num % 131071
    while( ( input = getchar() ) != EOF )
    {
        switch( input )
        {
            case '\n': break;                             //Do nothing

            //End of a test case, print result
            case  '#': ( decimal ) ? printf("NO\n") : printf("YES\n");
                       decimal = 0;
                       break;

            //Covert input till now to decimal modulo 131071
            default  : decimal = ( decimal * 2 + input - 48 ) % 131071;
                       break;
        }
    }
}