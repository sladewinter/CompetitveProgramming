//UVa - 10141 - Request for Proposal

#include <iostream>
#include <string>

using namespace std;

int main() 
{
	int caseNo{ 0 };
	int n, p, r, best_r;             
	double best_d, d;        
	string temp, best;			     
	bool first{ 1 };

	while( scanf( "%d %d\n", &n, &p ), n || p )
	{
		(first) ? first = 0 : printf( "\n" );

		while( n-- )
			getline( cin, temp );

		getline( cin, best );
		cin >> best_d >> best_r;
		scanf( "\n" );
		--p;
		r = best_r;
		while( r-- )
				getline( cin, temp );
		
		
		while( p-- )
		{
			getline( cin, temp );
			cin >> d >> r;
			scanf( "\n" );

			if( r > best_r || ( r == best_r && d < best_d ) )
			{
				best = temp;
				best_d = d;
				best_r = r;
			}

			while( r-- )
				getline( cin, temp );
		}

		cout << "RFP #" << ++caseNo << '\n';
		cout << best << '\n';
	} 
	return 0;
}													  