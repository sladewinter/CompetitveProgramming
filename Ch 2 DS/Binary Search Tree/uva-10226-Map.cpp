//UVa - 10226 - Hardwood Species

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int tc;
	string plant;
	map<string, int> count;
	scanf( "%d\n\n", &tc );
	while( tc-- )
	{
		int total{ 0 };
		count.clear();
		while(getline(cin, plant) && plant.size())
		{
			++total;
			if( !count[plant] )
				count[plant] = 1;
			else
				++count[plant];
		}
		for( auto &p : count )
		{
			cout << p.first;
			printf( " %.4lf\n", p.second * 100.0 / total );
		}
		if(tc) printf("\n");
	}

	
}  