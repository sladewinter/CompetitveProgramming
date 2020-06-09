//UVa - 401 - Palindromes

#include <iostream>
#include <cstring>

using namespace std;

char str[21];
bool isPalindrome()
{
	int slen{ (int)strlen(str) };
	for( int i{0}, j{slen - 1}; i < j; ++i, --j)
		if( str[i] != str[j] )
			return false;

	return true;
}

char reverse[91];
bool isMirrored()
{
	int slen{ (int)strlen(str) };
	for( int i{0}, j{slen - 1}; i <= j; ++i, --j)
		if( str[i] != reverse[str[j]] )
			return false;

	return true;
}

int main()
{
	reverse[65] = 'A';
	reverse[69] = '3';
	reverse[72] = 'H';
	reverse[73] = 'I';
	reverse[74] = 'L';
	reverse[76] = 'J';
	reverse[77] = 'M';
	reverse[79] = 'O';
	reverse[83] = '2';
	reverse[84] = 'T';
	reverse[85] = 'U';
	reverse[86] = 'V';
	reverse[87] = 'W';
	reverse[88] = 'X';
	reverse[89] = 'Y';
	reverse[90] = '5';
	reverse[49] = '1';
	reverse[50] = 'S';
	reverse[51] = 'E';
	reverse[53] = 'Z';
	reverse[56] = '8';
	
	while( scanf( "%s", str ) != EOF )
	{
		printf( "%s -- ", str );
		isPalindrome() 
			? ( isMirrored() 
				? printf("is a mirrored palindrome.\n\n")
				: printf("is a regular palindrome.\n\n") )
			: ( isMirrored() 
				? printf("is a mirrored string.\n\n")
				: printf("is not a palindrome.\n\n") );
	}
}  