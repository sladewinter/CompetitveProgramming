//UVa - 750 - 8 Queens Chess Problem
//Recursive Backtracking with Pruning
//No of operations <= 8! (8! without pruning), i.e., <= 41k approx.

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int x, y;                                 //Coordinates of input queen
int rows[8];                             //Row position of Qn in coln i
int lineNo;                             //For printing purposes

bool canPlace(int row, int col)              //Can we place Queen here?
{
  for( int prev{ 0 }; prev < col; ++prev )      //Check previous Queens

    if ( (rows[prev] == row )                            //Row taken
      || (abs(row - rows[prev]) == abs(col - prev)) )   //Same diagonal

      return false;

  return true;
}

void setBoard( int col )        //Recurse over increasing columns 
{
  if( col == 8 && rows[y] == x )               //1 solution found
  {
    printf( "%2d     ", ++lineNo );
    for( int col{ 0 }; col < 8; ++col )     //Print row positions
      printf( " %d", rows[ col ] + 1 );    //Our indices start @0

    printf( "\n" );
    return;
  }

  for( int row{ 0 }; row < 8; ++row )  //Find an empty row for Q
    if( canPlace( row, col ) )        //Check pos of prev Queens
    {
      rows[col] = row; 
      setBoard( col + 1 );              //Move on to next column
    }
}


int main() 
{
  int tc;                                    //No of Test Cases
  scanf( "%d", &tc );
  while( tc-- )
  {
    scanf( "%d %d", &x, &y );
    --x; --y;                        //Problem indices start @1

    lineNo = 0;
    fill( rows, rows + 8, -1 );           //Reset row positions

    printf( "SOLN       COLUMN\n" );
    printf( " #      1 2 3 4 5 6 7 8\n\n");

    setBoard( 0 );                //Place 1st queen in column 0

    if( tc )
      printf( "\n" );
  }  
 	return 0;
}													  