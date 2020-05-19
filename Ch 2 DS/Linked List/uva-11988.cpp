//UVa -11988 - Broken Keyboard (a.k.a. Beiju Text)

#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() 
{
	string line;
	list<char> ll;

	while( getline( cin, line ) )
	{
		ll.clear();
		list<char>::iterator iter{ ll.begin() };

		for( auto &ch : line )
			switch( ch )
			{
				case '\r':
				case '\n': break;
				
				case '[' : iter = ll.begin();
						   break;

				case ']' : iter = ll.end();
						   break;

				default  : ll.insert( iter, ch );
			}
		for( auto &ch : ll )
			cout << ch;
		cout << '\n';
	}
	return 0;
}													  