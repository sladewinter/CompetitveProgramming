//UVa - 10851 - 2D Hieroglyphs
//Cipher/Encode/Encrypt/Decode/Decrypt, Easier

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	int N;
	scanf( "%d\n", &N );

	char H[8][82];
	string line;
	while( N-- )
	{
		getline(cin, line);
		
		for( int i{0}; i < 8; ++i )
		{
			getchar();
			cin.getline(H[i], 82);
		}
		int M{ (int)strlen(H[0]) };
		while( H[0][--M] == '\r' || H[0][M] == '\n');
	
		getline(cin, line);		
		getline(cin, line);

		for( int col{ 0 }; col < M; ++col )
		{
			char c{ 0 };

			for( int row{ 7 }; row >= 0; --row )
				if( H[row][col] == 92 ) 
					c += pow(2, row);

			printf( "%c", c );
		}
		printf( "\n" );
	}
} 