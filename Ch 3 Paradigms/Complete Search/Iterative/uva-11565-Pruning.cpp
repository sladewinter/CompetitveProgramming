//UVa 11565 - Simple Equations
//Iterative Complete Search with Pruning
//B,C <= 10k so roughly 10 * 2 * sqrt(10K) * 2 * cbrt(10K) = 0.9M ops

#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	int N, A, B, C;                              //Problem parameters
	scanf( "%d", &N );
	while( N-- )
	{
		bool solved{ false };
		scanf( "%d %d %d", &A, &B, &C );
		int sqrtC{ (int)sqrt(C) };     //x, y, z <= sqrt(C)
  		int cbrtB{ (int)cbrt(B) };    //Atleast 1 of x,y,z <= cbrt(B)
  		
  		cbrtB = min( cbrtB, sqrtC );             //Optimization tweak

  		for( int x{-cbrtB}; x <= cbrtB && !solved; ++x )
  			for( int y{ -sqrtC }; y <= sqrtC; ++y )
  				if( y != x && x*x + y*y <= C )       //Pruning
  				{
  					int z{ A - (x + y) };          //Directly pick z!
  					
  					if( z != x && z != y && x*y*z == B
  						       && x*x + y*y + z*z == C )    //Pruning
  					{
  						if( x > y ) swap(x, y);      //Keep x smaller
  						if( y > z ) swap(y, z);     //keep y smaller

  							solved = true;
  							printf( "%d %d %d\n", x, y, z );
  							break;
  					}
  				}
  		if( !solved ) printf( "No solution.\n" );
	}
 	return 0;
}													  