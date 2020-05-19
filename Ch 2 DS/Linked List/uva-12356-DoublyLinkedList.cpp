//UVa - 12356 - Army Buddies
//Simulating Doubly Linked List using 1-D array 

#include <iostream>
struct node
{
 	int l, r;                 //Because pair.first/second too verbose
};
using namespace std;

int main() 
{
	int S, B, L, R;                              //Problem parameters
	node sol[100001];                           //Soldiers
	while( scanf( "%d %d", &S, &B ), S || B )
	{
		for( int i{ 1 }; i <= S; ++i )        //Nodes are 1 to S
		{
			sol[i].l = i - 1;				//Left neighbor index
			sol[i].r = i + 1;			   //Right neighbor index
		}
		while( B-- )
		{
			scanf( "%d %d", &L, &R );  //Delete nodes L to R

			//So node left of L must point towards node right of R
			sol[ sol[L].l ].r = sol[R].r;

			//And node right of R must point towards node left of L
			sol[ sol[R].r ].l = sol[L].l;

			//Print node to the left of L, * if L was first node
			( sol[L].l == 0 ) ? printf( "* " )
					          : printf( "%d ", sol[L].l );

			//Print node to the right of R, * if R was last node
			( sol[R].r == S + 1 ) ? printf( "*\n" )
							  : printf( "%d\n", sol[R].r );
		}
		printf( "-\n" );                      //Problem specific
	}
 	return 0;
}													  