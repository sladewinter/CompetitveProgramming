//Diameter of a Graph on Unweighted Graph with +ve weighed edges only
//Floyd Warshall Algorithm - Adjacency Matrix Data structure
//UVa - 1056 - Degrees of Separation - Undirected simple graph

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    //freopen( "input", "r", stdin );
    int P, R;
    string A, B;
    unordered_map<string, int> map;
    int vertexNo;
    int caseNo{ 0 };
    int diameter;
    int AdjMatrix[50][50];
    while( scanf( "%d %d", &P, &R ), P || R )
    {
        vertexNo = 0;
        map.clear();

        for( int u{ 0 }; u < P; ++u )
            AdjMatrix[u][u] = 0;

        for( int u{ 0 }; u < P - 1; ++u )
            for( int v{ u + 1 }; v < P; ++v )
                AdjMatrix[u][v] = AdjMatrix[v][u] = 999;

        while( R-- )
        {
            cin >> A >> B;
            if( !map[A] )
                map[A] = ++vertexNo;
            if( !map[B] )
                map[B] = ++vertexNo;
            AdjMatrix[ map[A] - 1 ][ map[B] - 1 ]
                = AdjMatrix[ map[B] - 1 ][ map[A] - 1 ] = 1;
        }

        //Floyd Warshall Algorithm
        for( int k{ 0 }; k < P; ++k )
            for( int u{ 0 }; u < P; ++u )
                for( int v{ 0 }; v < P; ++v )
                    AdjMatrix[u][v] = min( AdjMatrix[u][v], 
                        AdjMatrix[u][k] + AdjMatrix[k][v] );

        diameter = 0;

        for( int u{ 0 }; u < P - 1 && diameter != 999; ++u )
            for( int v{ u + 1 }; v < P && diameter != 999; ++v )
                diameter = max( diameter, AdjMatrix[u][v] );

        printf("Network %d: ", ++caseNo );

        ( diameter == 999 ) ? printf("DISCONNECTED\n\n")
                            : printf( "%d\n\n", diameter );

    }

    return 0;
}





