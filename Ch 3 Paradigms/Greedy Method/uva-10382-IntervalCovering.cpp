#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
using ii = pair<double, double>;
constexpr double eps = 1e-9;

int main() 
{
    int n, l, w;
    double temp1, temp2, curr;
    int min{ 0 };
    ii spr[ 10000 ];
    
    auto sq{ [](double a) {
      return pow(a, 2);
    } };
  
    while( scanf( "%d %d %d", &n, &l, &w ) == 3 )
    {
        
        for( int i{ 0 }; i < n; ++i )
        {
            scanf( "%lf %lf", &temp1, &temp2 );
            
            if( (2 * temp2) >= w )
            {
                temp2 = sqrt(sq(temp2) - sq(w / 2.0));
                spr[i].first = temp1 - temp2;
                spr[i].second = temp1 + temp2;
            }
            else
                spr[i].first = spr[i].second = temp1;
        }
        
        sort( spr, spr + n, []( ii a, ii b )
            { return ( ( fabs(a.first - b.first) <= eps )
                     ? ( a.second > b.second ) 
                     : ( a.first < b.first ) ); 
                });
                
        curr = 0;
        min = 0;
        int max{0};
        double max_r{0};
        for( int i{ 0 }; ( i < n ) && ( curr < l + eps ); ++i )
        {
            if( spr[i].first > curr )
            {
                min = -1;
                break;
            }
            if( spr[i].second > curr )
            {
                for( int j{i}; ( j < n ) && ( spr[j].first < curr ); ++j )
                    if( spr[j].second > max_r )
                    {
                        max_r = spr[j].second;
                        max = j;
                    }
                i = max;
                curr = max_r;
                ++min;
            }
        }
        if( curr < l + eps )
                min = -1;
        printf( "%d\n", min );
    }
    return 0;
}

