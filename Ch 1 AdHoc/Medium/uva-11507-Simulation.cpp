//UVa 11507 - Bender B. Rodriguez
//Simulation

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() 
{
	unordered_map<string, int> str2int;
	unordered_map<int, string> int2str;
	str2int["+x"] = 0; int2str[0] = "+x";
	str2int["+y"] = 1; int2str[1] = "+y";
	str2int["+z"] = 2; int2str[2] = "+z";
	str2int["-x"] = 3; int2str[3] = "-x";
	str2int["-y"] = 4; int2str[4] = "-y";
	str2int["-z"] = 5; int2str[5] = "-z";
	str2int["No"] = 6; int2str[6] = "No";

	int bendArray[7][7]{};
	bendArray[0][1] = 1;
	bendArray[0][2] = 2;
	bendArray[0][4] = 4;
	bendArray[0][5] = 5;
	bendArray[0][6] = 0; 
	
	bendArray[1][1] = 3;
	bendArray[1][2] = 1;
	bendArray[1][4] = 0;
	bendArray[1][5] = 1;
	bendArray[1][6] = 1;

	bendArray[2][1] = 2;
	bendArray[2][2] = 3;
	bendArray[2][4] = 2;
	bendArray[2][5] = 0;
	bendArray[2][6] = 2; 

	bendArray[3][1] = 4;
	bendArray[3][2] = 5;
	bendArray[3][4] = 1;
	bendArray[3][5] = 2;
	bendArray[3][6] = 3; 
	
	bendArray[4][1] = 0;
	bendArray[4][2] = 4;
	bendArray[4][4] = 3;
	bendArray[4][5] = 4;
	bendArray[4][6] = 4;

	bendArray[5][1] = 5;
	bendArray[5][2] = 0;
	bendArray[5][4] = 5;
	bendArray[5][5] = 3;
	bendArray[5][6] = 5; 

	int n, dir;
	string temp;
	while( scanf( "%d", &n ), n )
	{
		dir = 0;
		while( --n )
		{
			cin >> temp;
			dir = bendArray[dir][str2int[temp]];
		}

		cout << int2str[dir] << '\n';
	}
	return 0;
}													  