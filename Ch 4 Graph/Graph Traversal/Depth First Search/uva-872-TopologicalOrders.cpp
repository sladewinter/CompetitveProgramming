//UVa - 872 - Ordering
//All possible Topological Orders, Recursive Backtracking using Bitmask
//Note: Regex is taking time, use other input processing for faster

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <cmath>

using namespace std;
using iter = sregex_iterator;
using vi = vector<int>;
using vvi = vector<vi>;

vvi AdjList;
int vert{0};                //No of vertices
vi print;                  //Printing purposes
int inDegree[21];          
unordered_map<int, char> int2char;
bool solved;

void TopoOrder( int mask )
{
	if( mask == 0 && !print.empty() )   //Covered all vertices, print
	{
		for( int u{0}; u < vert - 1; ++u )
			printf( "%c ", int2char[print[u]] );
		printf( "%c\n", int2char[print[vert - 1]] );
		solved = true;
		return;
	}
	int temp{ mask };
	while( temp )                    //Very fast lookup using Bitmask
	{
		int LSB{ temp & -temp };     //Least significant power of 2
		temp &= ~LSB;
		int u{ (int)log2(LSB) };     //Get the vertex
		if( inDegree[u] )            //Indegree != 0
			continue;

		print.push_back(u);                //Push vertex for printing
		for( auto &v : AdjList[u] )      
			--inDegree[v];                 
		TopoOrder( mask & ~LSB );          //Recurse

		for( auto &v : AdjList[u] )      //Recursion wraps back
			++inDegree[v];                 //Replace degrees for next
		print.pop_back();                  //Pop back vertex for next
	}
}

int main()
{
	int tc;                //No of test cases
	scanf( "%d\n", &tc );
	while(tc--)
	{
		string line;
		unordered_map<char, int> char2int;    
		int2char.clear();

		vert = 0;    
		getline( cin, line );
		line = regex_replace(line, regex("[\n\r\\s]*"),"");
		sort(line.begin(), line.end());
		for( auto &ch : line )
		{
			char2int[ch] = vert;
			int2char[vert++] = ch;
		}

		AdjList.assign(vert, vi());

		regex edge{ "[A-Z][<>][A-Z]" };           //Faster ways exist
		getline( cin, line );
		auto beg = iter( line.begin(), line.end(), edge );
    	auto end = iter();

    	memset( inDegree, 0, sizeof(inDegree) );      //Get all edges
    	for ( iter k{ beg }; k != end; ++k )
    	{	
    		string temp{ (*k).str() };                
    		AdjList[char2int[temp[0]]].push_back(char2int[temp[2]]);
    		++inDegree[char2int[temp[2]]];
    	}
 
    	print.clear();
    	solved = false;
    	TopoOrder( (1 << vert) - 1 );         //Set mask to full
    	if(!solved) 
    		printf( "NO\n" );

    	if(tc)
    		printf( "\n" );

    	getline(cin, line);
	}
	return 0;
} 