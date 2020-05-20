//UVa - 725 - Division
//Iterative Complete Search
//N = 2 in worst case, so 10(bits) * 50000 roughly 0.5M operations

#include <iostream>
using namespace std;

int main() 
{
	int N;                                   //Problem parameter
	bool first{ true };                     //Blank line b/w cases
	while( scanf( "%d", &N ), N )
	{
		( !first ) ? printf( "\n" ) : first = false;
		bool solved{ false };
		
		for( int abcde{ 1234 }; abcde <= 98765 / N; ++abcde )
		{
			int fghij{ abcde * N };      
			int used{ abcde < 10000 };   //Flag 0 if used in abcde

			int temp{ abcde };          //Check if all digits present
			while( temp )              //Flag bits for denominator
			{
				used |= (1 << (temp % 10));
				temp /= 10;
			}
			temp = fghij;
			while( temp )          //Flag bits for numerator
			{
				used |= (1 << (temp % 10));
				temp /= 10;
			}
			if( used == (1 << 10) - 1 )            //All 10 bits used
			{
				printf( "%05d / %05d = %d\n", fghij, abcde, N );
				solved = true;
			}
		}
		if( !solved )
			printf( "There are no solutions for %d.\n", N );
	}
 	return 0;
}													  