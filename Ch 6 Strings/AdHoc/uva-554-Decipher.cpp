//UVa - 554 - Caesar Cypher
//Cipher/Encode/Encrypt/Decode/Decrypt, Harder

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string dict[101];
	int idx{ 0 };
	do
	{
		cin >> dict[idx];

	} while( dict[idx++] != "#" );
	--idx;
	sort( dict, dict + idx );

	char text[251];
	cin.getline(text, 251);
	cin.getline(text, 251);

	int len{ (int)strlen(text) };

	if( text[len - 1] == '\r' ) 
			text[--len] = '\0';

	string best;
	int maxi{ 0 };
	for( int i{0}; i < 26; ++i )
	{
		for( int j{ 0 }; j < len; ++j )
		{
			text[j] = text[j] + 1;
			if( text[j] == 91 ) text[j] = 32;
			if( text[j] == 33 ) text[j] = 65;
		}

		int matches{ 0 };
		stringstream ss{ text };
		string word;
    	while( ss >> word )
        	matches += binary_search(dict, dict + idx, word);

        if( matches > maxi )
        {
        	best = text;
        	maxi = matches;
        }
	}
	stringstream ss{ best };
	string word;
	ss >> word;
	len = word.size();
	cout << word;
	while( ss >> word )
	{
		len += word.size() + 1;
		if( len > 60 )
		{
			cout << '\n';
			len = word.size();
		}
		else
			cout << ' ';
		cout << word;
	}

	cout << '\n';
} 