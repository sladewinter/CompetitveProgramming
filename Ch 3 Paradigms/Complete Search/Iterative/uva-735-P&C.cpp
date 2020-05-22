//UVa - 735 - Dart-a-Mania
//Iterative Complete Search

#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> scores;                       //All possible scores
	for( int i{0}; i <= 20; ++i )         //Do this just once
	{
		scores.insert(i);
		scores.insert(i * 2);
		scores.insert(i * 3);
	}
	scores.insert(50);                    //Bull's eye

	int score;
	while( scanf("%d", &score), score > 0 )
	{
		int comb{ 0 };                       //Combinations
		int perm{ 0 };                      //Permutations

		for( const int &i : scores )
			for( const int &j : scores )
				for( const int &k : scores )
					if( i + j + k == score )
					{
						++perm;                  //Can have repititions

						if( i <= j && j <= k)   //Avoids repetition
							++comb;           
					}						
						

		if( comb && perm )
		{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",
				score, comb );

			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",
				score, perm );
		}

		else
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",
				score );

		printf("**********************************************************************\n");
	}

	printf("END OF OUTPUT\n");
}