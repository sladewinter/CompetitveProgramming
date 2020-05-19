//UVa - 579 - Clock Hands
#include <iostream>
#include <cmath>
using namespace std;
int main() 
{
	double hour, mint;
	while( scanf( "%lf:%lf", &hour, &mint ), hour || mint )
	{
		double degree{ fabs( (hour * 30 + mint / 2) - (mint * 6) ) };
		printf( "%.3lf\n", min( degree, 360 - degree ) );
	}
	return 0;
}													  