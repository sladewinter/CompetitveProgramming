//Longest Path in Directed Acyclic graph using Shortest Path
//Topological sorting to form DAG and SSTF on -ve of the edges
//UVa 452 - Project Scheduling - Directed Weighted Graph

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vii = vector<ii>;
using vvii = vector<vii>;

vvii AdjList;                         //Adjacency List
vi topologic;                        //Topologically sorted verts
vb visited;                         //visited vector for DFS 
void topoSort( int u )
{
    visited[u] = true;

    for( auto &v : AdjList[ u ] )
        if( !visited[ v.first ] )
            topoSort( v.first );

    topologic.push_back( u );
}

int main()
{
    //freopen( "input", "r", stdin );
    vi dist;                               //Distance from source 
    int TC;                               //No of testcases
    char vertex, parent;                 //For input purpose
    int distance, noOfParents;          //For input purpose
    int vertexNo{ 0 };                 //No of vertices
    string line;                      //Line by line input
    stringstream vertInfo{};         //Stream to read char by char 
       
    scanf( "%d\n\n", &TC );        //Remove first 2 newlines
    while( TC-- )
    {
        AdjList.assign( 27, vii() );  //26 alphabets + SuperSource
        unordered_map<char, int> char2int;  
        vertexNo = 0;
         
        //Read line by line till we encounter a newline or EOF
        while( getline( cin, line ) && line != "" )
        {
            //Very important to clear stream's error flags
            vertInfo.clear();             
            vertInfo.str( line ); 
            vertInfo >> vertex;               //Current vertex

            if( !char2int[ vertex ] )
                char2int[ vertex ] = ++vertexNo;
            
            vertInfo >> distance;      //Distance from parents

            noOfParents = 0;           
            while( vertInfo >> parent )
            {
                ++noOfParents;         //1 more parent

                if( !char2int[ parent ] )
                    char2int[ parent ] = ++vertexNo;
                
                AdjList[ char2int[ parent ] ]
                    .emplace_back( char2int[ vertex ], distance );
            }

            if( !noOfParents )  //Assign to SuperSource vertex 0 
                AdjList[ 0 ]
                    .emplace_back( char2int[ vertex ], distance );
        }

        ++vertexNo;            //Super Source 0 added

        //Topological sort using DFS
        topologic.clear();
        visited.assign( vertexNo, false );
        topoSort( 0 );
        reverse( topologic.begin(), topologic.end() );

        //Run Shortest path on DAG in topological order: O( V + E )
        dist.assign( vertexNo, 0 );
        for( auto &u : topologic )
            for( auto &v : AdjList[ u ] )
                dist[ v.first ] = max( dist[ v.first ] , 
                                 dist[ u ] + v.second );

        //Find vertex farthest from source
        cout << *max_element( dist.begin(), dist.end() ) << '\n';

        if( TC )
            cout << '\n';
    }
    return 0;
}





