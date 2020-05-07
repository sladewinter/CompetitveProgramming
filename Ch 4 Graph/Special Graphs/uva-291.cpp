//Eulerian graph traversal and printing all possible Eulerian tours
//UVa - 291 - The House Of Santa Claus - Output possible Eulerian tours
//Input graph is given in problem, unweighted undirected, no test cases

#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

vi pList;                                  //For our printing purposes
bool AdjMatrix[6][6];                     //Taking 6 indices for ease 

void eulerianTour( int u )               //Recursive printing function
{
    pList.push_back( u );

    if( pList.size() == 9 )                  //Eulerian graph complete
    {
        for( auto &v : pList )
            printf( "%d", v );
        printf( "\n" );
    }

    else                                            //Graph incomplete
    {
        for( int v{1}; v <=5; ++v )
        {
            if( AdjMatrix[u][v] )          //This edge not visited yet
            {
                AdjMatrix[u][v] = AdjMatrix[v][u] = false;   //Turn it off
                eulerianTour( v );                           //Visit v
                AdjMatrix[u][v] = AdjMatrix[v][u] = true;    //Turn it on
            }
        }
    }

    pList.pop_back( );      //So that this vertex can be visited again
}   



int main()
{
   

    AdjMatrix[ 1 ][ 2 ] = AdjMatrix[ 2 ][ 1 ] = true;
    AdjMatrix[ 1 ][ 3 ] = AdjMatrix[ 3 ][ 1 ] = true;
    AdjMatrix[ 1 ][ 5 ] = AdjMatrix[ 5 ][ 1 ] = true;
    AdjMatrix[ 2 ][ 3 ] = AdjMatrix[ 3 ][ 2 ] = true;
    AdjMatrix[ 2 ][ 5 ] = AdjMatrix[ 5 ][ 2 ] = true;
    AdjMatrix[ 3 ][ 4 ] = AdjMatrix[ 4 ][ 3 ] = true;
    AdjMatrix[ 3 ][ 5 ] = AdjMatrix[ 5 ][ 3 ] = true;
    AdjMatrix[ 4 ][ 5 ] = AdjMatrix[ 5 ][ 4 ] = true;

    eulerianTour( 1 );
}