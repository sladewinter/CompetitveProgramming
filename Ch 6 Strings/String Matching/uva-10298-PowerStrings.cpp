//UVa - 10298 - Power Strings
//Leverage the idea of KMP matching to identify power
//of smallest string

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using vi = vector<int>;

int main()
{
	string s;
	vi back;
	while( cin >> s )
	{
		if( s == "." )
			break;

		int len{ (int)s.size() };
		back.assign( len + 1, -1 );
		for( int i = 0, j = -1; i < len; )
		{
			while( j >= 0 && s[i] != s[j] )
				j = back[j];
			++i; ++j;
			back[i] = j;
		}

		bool pos{false};

		for( int i{2}; i <= len; ++i )
		{
			if( 2*back[i] != i || len % back[i] != 0 )
				continue;

			pos = true;
			int slen{ back[i] };
			int n{ len / back[i] };
			for( int k{1}; k < n && pos; ++k )
				for( int j{0}; j < slen && pos; ++j )
					pos = (s[j] == s[k*slen + j]);

			if(pos)
			{
				cout << n << '\n';
				break;
			}
		}
		if( !pos )
			cout << 1 << '\n';
	}
	return 0;
}  