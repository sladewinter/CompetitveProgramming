//Recursive Backtracking with Top Down DP Memoization and Pruning
//Modelling 2 separate constraint graphs( Adj Matrices ) into 1 DAG 
//SPOJ 0101: Fishmonger, Multiple independent constraints on solution

#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using vb = vector<bool>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;

constexpr int INF{ 999999 };      //Infinity
int n, t;                        //Problem parameters   
int tTime[50][50];              //Time to travel between 2 states
int toll[50][50];              //Toll between 2 states
vvii memo;                    //Our memoization table
vb visited;                  //To avoid looping around cities


//Takes current state, time left, returns cost and time taken
ii travel( int curr, int timeLeft )
{
    if( timeLeft < 0 )               //Not a candidate, prune
        return { INF, INF };

    if( curr == n - 1 )            //A candidate solution
        return { 0, 0 };

    ii &sol{ memo[curr][timeLeft] };
    if(  sol != ii( -1, -1 ) )            //Solved previously
        return sol;

    visited[curr] = true;          //Avoid self loops
    sol = { INF, INF };           //To pick the minimum
    
    for( int v{ 1 }; v < n; ++v )
        if( !visited[v] && curr != v )
        {
            ii next = travel( v, timeLeft - tTime[curr][v] );
            if( next.first + toll[curr][v] < sol.first )
            {
                sol.first = next.first + toll[curr][v];
                sol.second = next.second + tTime[curr][v];
            }
        }

    visited[curr] = false;
    return sol;

}

int main()
{
    //freopen( "input", "r", stdin ); 
    ii solution;
    while( scanf( "%d %d", &n, &t ), n || t )
    {
        //Input time to travel between 2 states
        for( int u{ 0 }; u < n; ++u )
            for( int v{ 0 }; v < n; ++v )
                scanf( "%d", &tTime[u][v] );

        //Input toll between 2 states
        for( int u{ 0 }; u < n; ++u )
            for( int v{ 0 }; v < n; ++v )
                scanf( "%d", &toll[u][v] );

        //0 to t time possible so t + 1 time units
        memo.assign( n, vii( t + 1, {-1, -1} ) ); 
        visited.assign( n, false );

        solution = travel( 0, t );
        printf( "%d %d", solution.first, solution.second );
        
    }
    return 0;
}





