//UVa - 11935 - Through the Desert
//Binary Search the answer and then Simulate

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
using ii = pair<int, int>;

vector<ii> events;

bool simulate( double fuel )
{
    int n{ 0 };
    int leak{ 0 };
    double dist{ 0 };
    double remaining{ fuel };
    for( auto &element : events )
    {
        remaining -= ((( element.second - dist )/100) * n);
        remaining -= ( element.second - dist ) * leak;
        if( remaining < 0 )
            return false;
        switch( element.first )
        {
            case  1:
                ++leak;
                break;
            case  2:
                remaining = fuel;
                break;
            case  3:
                leak = 0;
                break;
            case  4:
                break;
            default:
                n = -element.first;
                break;
        }
        dist = element.second;
    }
    return( remaining >= 0 );
}

int main()
{
    int n, d;
    double beg, end, mid;
    constexpr double eps = 1e-9;
    char line[30];
    while( scanf( "0 Fuel consumption %d", &n ), n )
    {
        events.clear();
        events.emplace_back( -n, 0 );
        while( true )
        {
            scanf( "%d ", &d );
            cin.getline( line, 30 );
            if( !strncmp( line, "Fuel", 4 ) )
            {
                sscanf( line, "Fuel consumption %d", &n );
                events.emplace_back( -n, d );
            }
            else if( !strcmp( line, "Leak" ) )
                events.emplace_back( 1, d );
            else if( !strcmp( line, "Gas station" ) )
                events.emplace_back( 2, d );
            else if( !strcmp( line, "Mechanic" ) )
                events.emplace_back( 3, d );
            else if( !strcmp( line, "Goal" ) )
            {
                events.emplace_back( 4, d );
                break;
            }
        }
        beg = 0;
        end = 10000;
        while( ( end - beg ) > eps )
        {
            mid = ( beg + end ) / 2;
            simulate( mid ) ? end = mid : beg = mid;
        }
        
        printf( "%.3lf\n", mid );
    }
}