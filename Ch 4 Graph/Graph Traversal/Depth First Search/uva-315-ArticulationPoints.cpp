//UVa - 315 - Network
//Find no of Articulation Points( Cut Vertices )

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <bitset>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

vvi AdjList;
vi dfs_low;
vi dfs_num;
vi parent;                         //Parent vertex
bitset<100> points;               //Articulation Pts
int dfsCounter;                  //Assign dfslow, dfsnum
int rootChild;
constexpr int root{ 0 };        //0 will be root


void ArticulPoints( int u )    //Modified DFS
{
	dfs_num[u] = dfs_low[u] = dfsCounter++;
	for( auto &v : AdjList[u] )
	{	
		if( dfs_num[v] == 0 )      //root or unvisited
		{
			if( u == root )       //if u is root
				++rootChild;     //increase children
			
			if( v != root )         //If v is not root
			{
				parent[v] = u;
				ArticulPoints(v);  //Visit v as DFS
			}

			//Recursion rewinds, is u Articulation Pt?
			if( dfs_low[v] >= dfs_num[u] )
				points.set(u); 

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}

		//Else u-v is a back edge
		else if( v != parent[u] )
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);	
	}
}

int main()
{
	int N;
	string line;
	while( scanf("%d", &N), N )
	{
		AdjList.assign(N, vi());
		for( int i{0}; i <= N; ++i )
		{
			int u;
			scanf( "%d", &u );
			if(!u)
				break;
			--u;        //Problem indices start @1

			getline(cin, line);
			stringstream stream{ line };
			int v;
			while( stream >> v )
			{
				--v;    //Problem indices start @1

				AdjList[u].push_back(v);
				AdjList[v].push_back(u);
			}
		}
		dfs_low.assign(N, 0);
		dfs_num.assign(N, 0);
		dfs_low.assign(N, 0);
		parent.assign(N, 0);
		points = 0;
		dfsCounter = 0;
		rootChild = 0;

		ArticulPoints( root );   

		//Root is a special case
		if(rootChild > 1)
			points.set(0);
		else
			points.reset(0);

		printf( "%d\n", points.count() );
	}
} 