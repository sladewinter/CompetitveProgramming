//UVa - 489 - Hangman Judge

#include <iostream>

using namespace std;

int main()
{
	int round;
	char solution[1000], guess[1000];
	while( scanf( "%d", &round ), round != -1 )
	{
		scanf( "%s", solution );
		scanf( "%s", guess );

		int sol[26]{};
		int slen{ 0 };
		int i{ 0 };
		char ch;
		while( ch = solution[i++] )
			if( !sol[ch - 97] )
			{
				++slen;	
				sol[ch - 97] = 2;
			}
		

		int strokes{ 0 };
		bool gu[26]{};
		i = 0;
		while( ch = guess[i++] )
		{
			if( sol[ch - 97] )
			{
				if( sol[ch - 97] == 2 )
				{
					--slen;
					--sol[ch - 97];
					if( !slen ) break;
				}
			}
			else
			{
				if( !gu[ch - 97] )
				{
					++strokes;
					gu[ch - 97] = true; 	
					if( strokes == 7 ) break;
				}
			}
		}
		printf( "Round %d\n", round );
		if( strokes == 7 )
			printf( "You lose.\n" );
		else if( slen == 0 )
			printf( "You win.\n" );
		else
			printf( "You chickened out.\n" );
	}
}  