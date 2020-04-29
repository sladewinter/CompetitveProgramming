//Strongly Connected Components on unweighted graph
//Floyd Warshall Algorithm - Adjacency Matrix Data structure
//UVa - 247 - Calling Circles - Directed simple graph

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    //freopen( "input", "r", stdin );
    int n, m;
    string A, B;
    unordered_map<string, int> map;
    unordered_map<int, string> rev_map;
    int vertexNo;
    int caseNo{ 0 };
    bool AdjMatrix[25][25];
    bool visited[25];
    bool first{ true };
    while( scanf( "%d %d", &n, &m ), n || m )
    {
        (first) ? ( first = false) : printf( "\n" );
        vertexNo = 0;
        map.clear();

        for( int u{ 0 }; u < n; ++u )
            AdjMatrix[u][u] = true;

        for( int u{ 0 }; u < n - 1; ++u )
            for( int v{ u + 1 }; v < n; ++v )
                AdjMatrix[u][v] = AdjMatrix[v][u] = false;

        while( m-- )
        {
            cin >> A >> B;
            if( !map[A] )
            {
                map[A] = ++vertexNo;
                rev_map[vertexNo] = A;
            }
            if( !map[B] )
            {
                map[B] = ++vertexNo;
                rev_map[vertexNo] = B;
            }

            //Subtract 1 to keep indices from 0
            AdjMatrix[ map[A] - 1 ][ map[B] - 1 ] = true;
        }

        //Floyd Warshall Algorithm for Transitive Closure
        for( int k{ 0 }; k < n; ++k )
            for( int u{ 0 }; u < n; ++u )
                for( int v{ 0 }; v < n; ++v )
                    AdjMatrix[u][v] |= ( AdjMatrix[u][k] 
                                       & AdjMatrix[k][v]);

        for( int u{ 0 }; u < n; ++u )
            visited[u] = false;

        cout << "Calling circles for data set " << ++caseNo << ":\n";
        for( int u{ 0 }; u < n; ++u )
            if( !visited[u] )
            {
                visited[u] = true;
                cout << rev_map[ u + 1 ];      //Subtracted 1 earlier
                for( int v{ 0 }; v < n; ++v )
                    if( u != v & !visited[v] 
                        & AdjMatrix[u][v] & AdjMatrix[v][u] ) //SCC
                    {
                        visited[v] = true;
                        cout << ", " <<rev_map[ v + 1 ];
                    }
                cout << '\n';
            }
    
    }
    return 0;
}





