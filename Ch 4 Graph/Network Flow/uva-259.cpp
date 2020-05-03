//Max Flow in Directed graph modelled as Bipartite Matching problem
//Edmonds Karp's Algorithm - Adjacency Matrix Data structure
//UVa - 259 - Software Allocation - modelled as directed graph
//Source = 0, Applications 1 - 26, Computers 27 - 36, Sink = 37

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using vi = vector<int>;

int res[ 38 ][ 38 ];                     //Residual graph
vi parent;                              //Parent vector for BFS
constexpr int INF{ 999999 };

//Finds shortest path s ~> t on n vertices
void modif_BFS( int s, int t, int n )
{
    static vi dist; 
    
    dist.assign( n, INF );  
    parent.assign( n, -1 );

    queue<int> q;
    dist[s] = 0;
    q.push( s );

    int u, v;
    while( !q.empty() )
    {
        u = q.front();
        q.pop();
        if( u == t )
            break;                        //Reached destination

        for( v = 0; v < n; ++v )
        {
            //If edge u->v exists in resGraph && v is unvisited
            if( res[u][v] > 0 && dist[v] == INF )
            {
                dist[v] = dist[u] + 1;
                q.push( v );
                parent[ v ] = u;
              //  printf( "Parent of %d is %d\n", v, u );
            }
        }

    }
}

int flow{ 0 };
void augment( int s, int v, int minEdge )
{
    if( v == s )                              //Reached source
    {
        flow = minEdge;
        return;
    }
    if( parent[v] != -1 )          //We can continue traversal
    {
        augment( s, parent[v], min( minEdge, 
                            res[ parent[v] ][ v ] ) );
      
        res[ parent[v] ][ v ] -= flow;
        res[ v ][ parent[v] ] += flow;
    }
}

int main()
{
    //freopen( "input", "r", stdin );
   
    char app;                                //Read application
    char noUsers;           //No of users running 1 application
    int noApps;                            //No of applications
    while( ( app = getchar() )  != EOF )       //New test case
    {
         //Reset residual graph
         memset( res, 0, sizeof( res ) );

        //Connect all computers to sink 37 with 1 capacity
        for( int i{27}; i <= 36; ++i )
            res[i][37] = 1;

        //TestCase contain multiple line, app holds application
        noApps = 0;        
        do
        {
            //Set capacities from source 0 to applications
            noUsers = getchar() - 48;
            noApps += noUsers;
            res[0][app - 64] = noUsers;      //Directed graph

            getchar();               //Get the space in input

            //INF capacity b/w apps & comps that can run them
            char comp;
            while( ( comp = getchar() ) != ';' )
                res[app - 64][comp - 21] = INF;  //Directed G

            getchar();             //Get the newline in input

        }while( ( app = getchar() ) != '\n' && app != EOF );

        //Got our input now run Edmonds Karp's algo
        int maxFlow{ 0 };
        
        while( 1 )                   //Edmonds Karp's algorithm
        {
            //Running modified BFS on residual graph
            modif_BFS( 0, 37, 38 );

            //Find minimum weighed edge in path s~>t in resGraph
            flow = 0;
            augment( 0, 37, INF ); 
            if( flow == 0)           //No more flow can be added
                break;
            maxFlow += flow;
        }
        bool used{ false };        //Whether a computer is used
        if( maxFlow == noApps )
        {
            //Check for all 10 computers 27 to 36
            for( int i{27}; i <= 36; ++i )
            {
                used = false;

                //Check for all 26 apps 
                for( int j{1}; j <= 26; ++j )
                    if( res[i][j] == 1 )
                    {
                        //App j used computer i
                        printf( "%c", 'A' + j - 1 );
                        used = true;
                        break;
                    }

                if( used == false )  //This computer not used
                    printf( "%c", '_' );
            }
            printf( "\n" );
        }
        else
            printf( "!\n" );
    }
    return 0;
}





