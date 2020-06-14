#include <iostream>
#include <cstring>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using vi = vector<int>;

class UnionFind
{
	vi parent, rank;
public:
	UnionFind(int n)
	{
		rank.assign(n, 0);
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}
	void unionSet(int u, int v)
	{
		int pu{ findSet(u) };
		int pv{ findSet(v) };
		
		if( pu == pv ) return;

		if( rank[pu] > rank[pv] ) swap(pu, pv);
		else if( rank[pu] == rank[pv] ) ++rank[pv];
		parent[pu] = pv;  
	}
	int findSet(int u)
	{
		return (u == parent[u]) ? u
								: parent[u] = findSet(parent[u]);
	}
};

int main()
{
	int tc, n, i, j;
	char line[100];
	char ch;
	scanf( "%d", &tc );
	while(tc--)
	{
		scanf( "%d\n", &n );
		UnionFind UF( n );
		int su{0}, us{0};

		while( cin.getline(line, 100) && strcmp(line, "") )
		{
			sscanf(line, "%c %d %d\n", &ch, &i, &j);
			--i; --j;
			if( ch == 'c' )
				UF.unionSet(i, j);
			else
			(UF.findSet(i) == UF.findSet(j)) ? ++su : ++us;
		}
		printf( "%d,%d\n", su, us );
		if( tc ) printf("\n");
	}
	return 0;
}