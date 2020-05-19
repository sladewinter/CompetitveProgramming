//UVa -11988 - Broken Keyboard (a.k.a. Beiju Text)

#include <iostream>
#include <list>
#include <cstring>
using namespace std;

int main() 
{
	char line[10001];
	list<char> ll;
	list<char>::iterator iter;

	while( scanf( "%s", line ) != EOF )
	{
		ll.clear();
		iter = ll.begin();

		for( int i{0}; i < strlen(line); ++i )
			switch( line[i] )
			{
				case '[' : iter = ll.begin();
						   break;

				case ']' : iter = ll.end();
						   break;

				default  : ll.insert( iter, line[i] );
			}

		for( auto &ch : ll )
			cout << ch;
		cout << '\n';
	}
	return 0;
}													  