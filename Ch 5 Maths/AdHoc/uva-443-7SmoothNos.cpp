//UVa - 443 - Humble Numbers
//Generate 7-smooth numbers using Bottom Up DP

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int memo[5842]{ 1 };         //1 is 1st 7-smooth no

	//p2, p3, p5, p7 in increased dynamically to 
    //point at those 4 numbers in sequence, multiplying 
    //which by 2, 3, 5, and 7 respectively will just 
    //surpass the current highest 7-smooth number
	int p2, p3, p5, p7;       
	p2 = p3 = p5 = p7 = 0;  //Initially point to 1st no

	for( int i{1}; i < 5842; ++i )  
	{
		//Keep increasing p2, p3, p5, p7 till they surpass
		//current highest when multiplied with 2, 3, 5, 7
		while( memo[p2] * 2 <= memo[i-1]) ++p2;
		while( memo[p3] * 3 <= memo[i-1]) ++p3;
		while( memo[p5] * 5 <= memo[i-1]) ++p5;
		while( memo[p7] * 7 <= memo[i-1]) ++p7;

		//Multiply those with 2, 3, 5, 7 and take minimum
		memo[i] = memo[p2] * 2;
		memo[i] = min( memo[i], memo[p3] * 3 );
		memo[i] = min( memo[i], memo[p5] * 5 );
		memo[i] = min( memo[i], memo[p7] * 7 );
	}

	int n;
	while( scanf( "%d", &n), n )            //O(1) lookup
	{
		printf( "The %d", n );
		
		if( n % 10 == 1 && n % 100 != 11 )
			printf("st");
		
		else if( n % 10 == 2 && n % 100 != 12 )
			printf("nd");

		else if( n % 10 == 3 && n % 100 != 13 )
			printf("rd");

		else
			printf("th");

		printf( " humble number is %d.\n", memo[n-1] );
	}
} 