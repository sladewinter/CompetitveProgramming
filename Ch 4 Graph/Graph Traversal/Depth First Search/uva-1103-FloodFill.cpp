//UVa - 1103 - Ancient Messages
//Floof Fill	

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int H, W;                          //Height, Width
char image[201][201];             //Image matrix
int dx[4]{ 1, 0, -1,  0};        //4 directions
int dy[4]{ 0, 1,  0, -1};
int comps;                     //No of white components

//Classic DFS FloodFill
void floodFill( int x, int y, char c1, char c2 ) 
{
	if( x < 0 || x >= H || y < 0 || y >= W  
						|| image[x][y] != c1 )
		return;

	image[x][y] = c2;
	for( int i{0}; i < 4; ++i )
		floodFill( x + dx[i], y + dy[i], c1, c2 );
}

//Counts no of white components inside each graph recursively
void connected( int x, int y, char c1,  char c2, char c3 )
{
	if( x < 0 || x >= H || y < 0 || y >= W  
			  || ( image[x][y] != c1 && image[x][y] != c2 ) )
		return;

	if( image[x][y] == c2 )        //Another white comp found
	{
		++comps;					
		floodFill(x, y, c2, c3);   //Fill only this component
	}
	else
		image[x][y] = c3;          //Else normal FloodFill

	for( int i{0}; i < 4; ++i )
		connected( x + dx[i], y + dy[i], c1, c2, c3 );
}

int main()
{
	//Convert input to binary
	string hex[16]{ "0000", "0001", "0010", "0011",
					"0100", "0101", "0110", "0111",
				   	"1000", "1001", "1010", "1011",
  					"1100", "1101", "1110", "1111" };

	string row;
	int hiero[6];            //Store count of each Hieroglyph

	//According to no. of white components
	char glyphs[6]{'W', 'A', 'K', 'J', 'S', 'D'};

	//According to alphabetical order
	int pos[6]{1, 5, 3, 2, 4, 0};

    int caseNo{0};                           //Output purposes
    
	while( scanf("%d %d\n", &H, &W), H )
	{
		for( int i{0}; i < H; ++i )
		{
			getline(cin, row);             
			int idx{ 0 };                  //Indexing each row

			for( int j{0}; j < W; ++j )
			{
				string hexa;
				if( row[j] <= '9' )
					hexa = hex[row[j] - 48];
				else
					hexa = hex[row[j] - 87];

				for( int k{0}; k < 4; ++k )
					image[i][idx++] = hexa[k];  //Hex to binary
			}	
		}

		W *= 4;                      //Width was in hex earlier

		//0 - White, 1 - Black, 2 - Ignore this color
		//Paint white background from all 4 sides
		for( int i{0}; i < H; ++i )
		{
			floodFill(i, 0, '0', '2' );     
			floodFill(i, W - 1, '0', '2' );
		}
		for( int i{0}; i < W; ++i )
		{
			floodFill(0, i, '0', '2' );
			floodFill(H - 1, i, '0', '2' );
		}

		memset( hiero, 0, sizeof(hiero));
		for( int i{0}; i < H; ++i )
			for( int j{0}; j < W; ++j )
				if( image[i][j] == '1' )      //A new hieroglyph
				{
					comps = 0;

					//Paint it to '2' and count white components
					connected(i, j, '1', '0', '2'); 

					//Increase corresponding Hieroglyph count
					++hiero[comps];
				}
				
		printf( "Case %d: ", ++caseNo );
		for( int i{0}; i < 6; ++i )
			for( int j{0}; j < hiero[pos[i]]; ++j  )

				cout << glyphs[pos[i]];    //Ouput alphabetically
		cout << '\n';
		 
	} //while ends

} //main ends