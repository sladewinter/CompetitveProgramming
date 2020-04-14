// Longest Increasing Subsequence

#include <iostream>
#include <array>

using namespace std;
using ii = pair<int, int>;

int main()
{
    array arr{ -7, 10, 9, 2, 3, 8, 8, 1 };
    array<ii, arr.size()> lis;
    int opti{ 0 };
    lis[0] = make_pair( 0, 1 );
    for( int i{1}; i < lis.size(); ++i )
    {
        lis[i] = make_pair( i, 1 );
        for( int j{0}; j < i; ++j )
            if( arr[i] > arr[j] )
                if( 1 + lis[j].second > lis[i].second )
                {
                    lis[i].second = 1 + lis[j].second;
                    lis[i].first  = j;
                }
        if( lis[i].second > lis[opti].second )
            opti = i;
    }
    int pr = opti;
    while( lis[pr].first != pr )
    {
        cout << arr[pr] << " -> ";
        pr = lis[pr].first;
    }
    cout << arr[pr] << '\n';
    return 0;
}

