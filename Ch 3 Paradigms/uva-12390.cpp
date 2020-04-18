#include <bits/stdc++.h>

using namespace std;
using dii = tuple<double, int, int>;

int main() 
{
    int N, B;
    int temp;
    while( scanf("%d %d", &N, &B), ( N + 1) || ( B + 1 ) )
    {
        priority_queue<dii> pq;
        for( int i{ 0 }; i < N; ++i )
        {
            scanf( "%d", &temp );
            pq.push({ temp / 1.0, temp, 1 });
        }
        B -= N;
        
        while( B-- )
        {
            auto num = get<1>(pq.top());
            auto den = get<2>(pq.top());
            pq.pop();
            pq.push({ num/(den + 1.0), num, den + 1.0 });
        }
        printf( "%d\n", static_cast<int>( ceil( get<0>(pq.top()) ) ) );
    }
    return 0;
}







