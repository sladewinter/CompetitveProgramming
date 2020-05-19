//UVa - 11340 - Newspaper

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() 
{
	int N, K, M;                 //Problem parameters
 	scanf( "%d\n", &N );

	unordered_map<char, int> char2int;
	string line;
	char ch;
	int val;
	int amount;
	while( N-- )
	{
		char2int.clear();
		scanf( "%d\n", &K );
		while( K-- )
		{
			scanf( "%c %d\n", &ch, &val );
			char2int[ch] = val;             //Uses hashing
		}

		scanf( "%d\n", &M );
		amount = 0;
		while( M-- )
		{
			getline( cin, line );
			for( auto &ch : line )
				amount += char2int[ch];    //Returns 0 if not present
		}
		printf( "%.2lf$\n", amount / 100.00 );

	}
	return 0;
}													  