//UVa - 11831 - Sticker Collector Robot
//Graph Traversal on Implicit Graph

#include <iostream>
#include <string>
using namespace std;

struct step
{
	int x, y;
};

int main()
{
	step move[4]{ {-1,0}, {0,1}, {1,0}, {0,-1} };   //N, E, S, W
	step pos;                                      //Current position

	int N, M, S;                                  //Problem parameters
	string row;                                  //Ease of input
	char arena[100][100];                       //Robot arena
	int dir;                                   //Direction

	scanf("%d %d %d\n", &N, &M, &S);
	while( scanf("%d %d %d\n", &N, &M, &S), N )
	{
		for( int r{0}; r < N; ++r )
		{
			getline(cin, row);

			for( int c{0}; c < M; ++c )
			{
				arena[r][c] = '.';              //Change N, S, L, O to .

				switch( row[c] )
				{
					case '*': arena[r][c] = '*'; break;    //Change back
					case '#': arena[r][c] = '#'; break;   //Change back
					
					case 'N': dir = 0; pos.x = r; pos.y = c; break;  //N
					case 'S': dir = 2; pos.x = r; pos.y = c; break;  //S
					case 'L': dir = 1; pos.x = r; pos.y = c; break;  //E
					case 'O': dir = 3; pos.x = r; pos.y = c; break;  //W
				}
			}
		}
		getline(cin, row);                           //Instructions
		int stick{ 0 };                             //Stickers
		for( char &i : row )
		{
			switch(i)
			{
				case 'D' : dir = (dir + 1) % 4; break;    //Move right
				case 'E' : dir = (dir + 3) % 4; break;    //Move left

				case 'F' :
				{		 
						   auto temp{ pos };
						   temp.x += move[dir].x;          //Move a step
						   temp.y += move[dir].y;
						   if( temp.x < 0 || temp.x >= N    //Hit a wall
						   	|| temp.y < 0 || temp.y >= M
						   	|| arena[temp.x][temp.y] == '#' )   //Pillar
						   		break;

						   if( arena[temp.x][temp.y] == '*' )  //Sticker
						   		++stick;
						   pos = temp;	
						   arena[pos.x][pos.y] = '.';     //Sticker gone
						   break;
				}
 				case '\r': break;                       //Annoying stuff
				case '\n': break;                      //Unnecessary
			}
		}

		printf("%d\n", stick);
	}
}