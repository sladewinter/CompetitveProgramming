//UVa - 1203 - Argus

#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
using ii = tuple<int, int>;

int main()
{
	int Q_num, period[3001];
	char in[20];
	int time;
	priority_queue<ii> pq;
	while( cin.getline(in, 20), strncmp(in, "#", 1) )
	{
		sscanf(in, "Register %d %d", &Q_num, &time);
		pq.emplace(-time, -Q_num);
		period[Q_num] = time;
	}

	int K;
	scanf( "%d", &K );
	while( K-- )
	{
		tie(time, Q_num) = pq.top();
		pq.pop();
		time = -time;
		Q_num = -Q_num;
		printf( "%d\n", Q_num );

		time += period[Q_num];
		pq.emplace(-time, -Q_num);	
	}

}  