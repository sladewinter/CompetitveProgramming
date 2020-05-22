//UVa - 167 - The Sultan's Successors - Classic 8 Queens
//Recursive Backtracking with Pruning, Bitmasks for fast lookup

#include <iostream>
using namespace std;

int sum{0};                             //Global sum
int rows, leftD, rightD;               //Check occupancy
int board[64][64];                    //Chess board

void backTrack( int col, int curr)   //Column, Current Sum
{
	if( col == 8 )                 //Filled all columns
	{
		sum = max( curr, sum );           //Update global
		return;
	}

	for(int row{0}; row < 8; ++row)                     //Choose a row
		if (   !(rows   & (1 << row))                  //Empty row check
			&& !(leftD  & (1 << (row + col)))         //Left diagonal check
			&& !(rightD & (1 << (row - col + 7))))   //Right diagonal check
			{
				//Set row, left and right diagonals
				rows   |= (1 << row); 
				leftD  |= (1 << (row + col));
				rightD |= (1 << (row - col + 7));

				backTrack( col + 1, curr + board[row][col] );

				//Unset row, left and right diagonals when recursion rewinds
				rows   &= ~(1 << row);
				leftD  &= ~(1 << (row + col));
				rightD &= ~(1 << (row - col + 7));
			}	

}

int main()
{
	int k;                                //No of boards
	scanf("%d", &k);
	while( k-- )
	{
		for(int i{0}; i < 8; ++i)
			for(int j{0}; j < 8; ++j)
				scanf("%d", &board[i][j]);

		sum = rows = leftD = rightD = 0;  //Nothing is occupied
		backTrack( 0, 0 );                //Start from column 0
		printf( "%5d\n", sum );

	}
}