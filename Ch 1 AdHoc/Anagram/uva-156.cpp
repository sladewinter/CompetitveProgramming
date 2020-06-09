//UVa - 156 - Ananagram

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int main()
{
	unordered_map<string, int> map;
	vector<string> set;
	string str;
	string modif;
	while( cin >> str )
	{
		if( str == "#" )
			break;
		
		modif = str;
		transform(modif.begin(), modif.end(), 
				   modif.begin(), ::tolower);
		sort( modif.begin(), modif.end() );
		if( !map[modif] )
		{
			map[modif] = 1;
			set.push_back(str);
		}
		else
			map[modif] = 2;
	}
	sort( set.begin(), set.end() );
	for( auto &element : set )
	{
		modif = element;
		transform(modif.begin(), modif.end(), 
				   modif.begin(), ::tolower);
		sort( modif.begin(), modif.end() );
		if( map[modif] == 1 )
			cout << element << '\n';
	}
}  