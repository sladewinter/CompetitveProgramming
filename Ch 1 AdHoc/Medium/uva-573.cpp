//UVa - 573 - The Snail
#include <iostream>
using namespace std;
int main() 
{
	double H, U, D, F; 
	
	while( scanf( "%lf %lf %lf %lf", &H, &U, &D, &F ), H )
	{
		double climbed{ 0 };
		int day{ 1 };
		F = F * U / 100;
		while( true )
		{
			climbed += U;
			if( climbed > H )
				break;

			U = max( U - F, 0.00 );
			climbed -= D;
			if( climbed < 0 )
				break;

			++day;
		}

		if( climbed < 0)
			printf( "failure on day %d\n", day );
		else
			printf( "success on day %d\n", day );
	}
	return 0;
}													  