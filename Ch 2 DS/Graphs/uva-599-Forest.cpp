//UVa - 599 - The Forrest for the Trees

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int tc;
	char line[100];
	scanf( "%d\n", &tc );
	while(tc--)
	{
		bool tree[26]{ };
		char u, v;
		int edges{ 0 };
		while(cin.getline(line, 100), strncmp(line, "*", 1))
		{
			sscanf(line, "(%c,%c)", &u, &v);
			++edges;
			tree[u - 65] = true;
			tree[v - 65] = true;
		}

		int verts{ 0 }, acorns{ 0 };
		while( scanf("%c", &u) != EOF && u != '\n' )
			switch(u)
			{
				case '\r' :
				case ','  : break;
				default   : if( !tree[u - 65] )
								++acorns;
							++verts;
			}
		int comp{ verts - edges };
		printf("There are %d tree(s) and %d acorn(s).\n",
			comp - acorns, acorns);
	}
}  