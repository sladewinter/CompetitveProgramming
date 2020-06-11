//UVa - 978 - Lemmings Battle!

#include <iostream>
#include <queue>

using namespace std;

int B;
priority_queue<int> green, blue;
void fight( int bf )
{
	if( bf == B || green.empty() || blue.empty() )
		return;
	
	int glem{ green.top() };
	green.pop();

	int blem{ blue.top()  };
	blue.pop();

	fight( bf + 1 );

	if( glem < blem )
		blue.push( blem - glem );
	if( blem < glem )
		green.push( glem - blem );
}

int main()
{
	int N, SG, SB;
	scanf( "%d", &N );
	while( N-- )
	{
		scanf( "%d %d %d", &B, &SG, &SB );

		int lem;
		for( int i{0}; i < SG; ++i )
		{
			scanf( "%d", &lem );
			green.push(lem);
		}
		for( int i{0}; i < SB; ++i )
		{
			scanf( "%d", &lem );
			blue.push(lem);
		}
		while( !green.empty() && !blue.empty() )
			fight( 0 );

		if( green.empty() && blue.empty() )
			printf("green and blue died\n");
		else if( blue.empty() )
		{
			printf("green wins\n");
			while( !green.empty() )
			{
				printf( "%d\n", green.top() );
				green.pop();
			}
		}
		else
		{
			printf("blue wins\n");
			while( !blue.empty() )
			{
				printf( "%d\n", blue.top() );
				blue.pop();
			}

		}
		if( N ) printf("\n");
	}
}  