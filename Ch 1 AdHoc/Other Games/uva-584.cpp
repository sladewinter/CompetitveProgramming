//UVa - 584 - Bowling

#include <iostream>
#include <cstring>

using namespace std;

int scores[22];
int roll{ 0 };
int sum()
{
	int ans{ 0 };
	int i{ 0 };
	for( int frame{ 0 }; frame < 10; ++frame )
	{
		if( scores[i] == 10 )
		{
			ans += scores[i] + scores[i+1] + scores[i+2];
			++i;
		}
		else if( scores[i] + scores[i+1] == 10 )
		{
			ans += scores[i] + scores[i+1] + scores[i+2];
			i += 2;
		}
		else
		{
			ans += scores[i] + scores[i+1];
			i += 2;
		}
	}
	return ans;
}

int main()
{
	char score;
	while( scanf("%c", &score), score != 'G' )
	{
		switch(score)
		{
			case ' '  : break;
			case '\r' : break;

			case '\n' : printf("%d\n", sum());
						roll = 0;
						break;

			case '/'  : scores[roll] = 10 - scores[roll-1];
						++roll;
						break;

			case 'X'  : scores[roll++] = 10;
						break;

			default   : scores[roll++] = score - '0';
						break;
		}
	}
}  