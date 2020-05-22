//UVa - 11085 - Back to the 8-Queens
//Recursive Backtracking with Pruning, Bitmasks for fast lookup
//Precompute all 92 8-Queen solutions and then O(1) per test case

#include <iostream>
using namespace std;

int rows{0};                              //Check row occupancy
int leftD{0};							 //Left diagonal occupancy 
int rightD{0};                          //Right diagonal occupancy
int soln[8];	                       //1 possible solution
int solns[92][8];                     //All possible solutions 
int solNo{ 0 };                      //Solution 0 to 91
 
void backTrack( int col )          //Column
{
	if( col == 8 )               //1 possible solution
	{		
		for( int col{0}; col < 8; ++col )              //Store the solution
			solns[solNo][col] = soln[col];
		
		++solNo; 
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

				soln[col] = row; 
				backTrack( col + 1 );

				//Unset row, left and right diagonals when recursion rewinds
				rows   &= ~(1 << row);
				leftD  &= ~(1 << (row + col));
				rightD &= ~(1 << (row - col + 7));
			}	

}

int main()
{
	backTrack( 0 );                          //Precompute all solutions!
	int Queens[8];                           //Input

	int caseNo{ 0 };
	while( scanf("%d", &Queens[0]) != EOF )
	{
		for( int col{1}; col < 8; ++col )
			scanf("%d", &Queens[col]);

		for( int col{0}; col < 8; ++col )
			--Queens[col];                       //Problem indices start @1
		
		int minimum{ 8 };                      //Minimum no of moves

		for( int sol{0}; sol < 92; ++sol )   //92 x 8 operations only 
		{
			int moves{ 0 };
			for( int col{0}; col < 8; ++col )
				moves += ( Queens[col] != solns[sol][col] );
			minimum = min( minimum, moves );
		}

		printf( "Case %d: %d\n", ++caseNo, minimum );

	}
}