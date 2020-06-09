//UVa - 278 - Chess

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int tc;
	scanf( "%d\n", &tc );
	while( tc-- )
	{
		int m, n;
		char piece;
		scanf( "%c %d %d\n", &piece, &m, &n );
		switch( piece )
		{
			case 'k': printf("%.0lf\n", ceil(m/2.0)*ceil(n/2.0)
								   + floor(m/2.0)*floor(n/2.0));
					  break;

			case 'K': printf("%.0lf\n", ceil(m/2.0)*ceil(n/2.0));
					  break;

			case 'Q': 
			case 'r': printf("%d\n", min(m, n));
		}
	}
}  