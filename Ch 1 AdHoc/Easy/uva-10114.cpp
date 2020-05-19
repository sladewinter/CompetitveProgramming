//UVa - 10114 - Loansome Car Buyer
#include <iostream>
#include <cstring>
using namespace std;
int main() 
{
	double deps[101];
	int dur, rec, mnth;
	double dnpay, amt, depr;
	while(scanf( "%d %lf %lf %d", &dur,&dnpay,&amt,&rec ), dur >= 0)
	{
		memset( deps, 0, sizeof(deps) );

		while( rec-- )
		{
			scanf( "%d %lf", &mnth, &depr );
			deps[mnth] = 1 - depr;
		}

		for( mnth = 1; mnth <= dur; ++mnth )
			if( !deps[mnth] )
				deps[mnth] = deps[mnth - 1];

		double carCost{ ( amt + dnpay ) * deps[0] };
		double toPay{ amt };
		int noOfMonths{ 0 };

		while( carCost < toPay )
		{
			carCost *= deps[ ++noOfMonths ];
			toPay -= amt / dur;
		}

		printf( "%d month", noOfMonths );
		( noOfMonths != 1 ) ? printf( "s\n" ) : printf( "\n" );
	}
	
	return 0;
}													  