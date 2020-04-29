//Shortest Path on Weighted Graph with all +ve weighed edges
//Djikstra Algorithm - Graph modelling
//UVa - 11367 - Full Tank - Converted input graph into "State-Space graph"

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
using iii = tuple<int, int, int>;
using viii = vector<iii>;

viii AdjList[1000][101];  //Vertices modelled as ( city, fuel )
int dist[1000][101];     //No of vertices = No of cities X Max capacity
priority_queue<iii, viii, greater<iii>> pq;

void DjikstraSSTF( int c )
{
    int d, u, fuel_u;    //Extract from top of pq
    int w, v, fuel_v;   //Vertices adjacent to ( u, fuel_u )
    while( !pq.empty() )
    {
        tie( d, u, fuel_u ) = pq.top();
        pq.pop();
        if( d > dist[u][fuel_u] )              //Lazy deletion from pq
            continue;

        for( auto &element : AdjList[u][fuel_u] )  
        {
            tie( w, v, fuel_v ) = element;
            if( fuel_v > c )
                continue;                 //Fuel greater than capacity

            if( dist[u][fuel_u] + w >= dist[v][fuel_v] )
                continue;                //Don't relax, no improvement

            dist[v][fuel_v] = dist[u][fuel_u] + w;        //Relax edge
            pq.push( { dist[v][fuel_v], v, fuel_v } ); //Push new vertex
        }
    }
}

int main()
{
	//freopen( "input", "r", stdin );
	int n, m;
	scanf( "%d %d", &n, &m );               //Cities, Edges

        int price;                         
	for( int i{0}; i < n; ++i )
    	{
        	scanf( "%d", &price );    //Price per unit at city i

	        for( int j{0}; j < 100; ++j )
        	    AdjList[i][j].emplace_back( price, i, j + 1 );
       		    //Stay in same city, but 1 unit fuel cost added
    	}

	int u, v, d;
	for( int i{0}; i < m; ++i )
	{
		scanf( "%d %d %d", &u, &v, &d );     //u - v distance
		for( int j{0}; j <= 100; ++j)
            	if( j >= d)                      //Enough fuel to reach v
            	{
                	//Note: Edges are cost of buying new fuel only
                	AdjList[u][j].emplace_back( 0, v, j-d );
                	AdjList[v][j].emplace_back( 0, u, j-d );
            	}
	}

	int q;                                  //Queries
	scanf( "%d", &q ); 

	int s, e, c;                            //Start, end, car capacity
    	int result;
	while( q-- )
	{
		scanf( "%d %d %d", &c, &s, &e );
        	for( int i{0}; i < n; ++i )
            		for( int j{0}; j <= c; ++j )
                		dist[i][j] = 9999;         //Reset distance matrix

	        dist[s][0] = 0;                    //Source distance = 0
        	while( !pq.empty() )               //Remove previous entries
            		pq.pop();

        	pq.push( { 0, s, 0 } );            //Distance 0, state( s, 0 )
        	DjikstraSSTF( c );                 //capacity is parameter

	        //Least cost is reaching end with fuel 0
        	( dist[e][0] == 9999 ) ? printf( "impossible\n" )
                	               : printf( "%d\n", dist[e][0] );
	}
    	return 0;
}


