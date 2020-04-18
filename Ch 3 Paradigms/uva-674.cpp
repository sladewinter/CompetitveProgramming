#include <iostream>
#include <cstring>
using namespace std;

int V;
int coinValue[5]{ 50, 25, 10, 5, 1 };
int memo[6][7500];

int ways( int type, int V )
{
    if( V == 0 )
        return 1;
        
    if( V < 0 || type == 5 )
        return 0;
        
    int &ans{ memo[type][V] };
    
    if( ans != -1 )
        return ans;
    
    ans = ways(type + 1, V) + ways(type, V - coinValue[type]);
    return ans;
}

int main()
{
    memset( memo, -1, sizeof(memo) );
    while( scanf( "%d", &V ) != EOF )
        printf( "%d\n", ways( 0, V ) );
    return 0;
}
