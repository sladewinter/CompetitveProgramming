//UVa 462 - Bridge Hand Evaluator
//Simulation

#include <iostream>
#include <vector>

using namespace std;
using vc = vector<char>;

int main() 
{
    char line[50];
    int suits[4]{ 'S', 'H', 'D', 'C' };
    while( cin.getline(line, 50) )
    {
        vc hand[4];
        bool stopped[4]{};
        int points{ 0 };
        for( int i{0}; i < 39; i += 3 )
        {
            switch( line[i] )
            {
                case 'A': points += 4; break;
                case 'K': points += 3; break;
                case 'Q': points += 2; break;
                case 'J': points += 1; break;
            }
            switch( line[i+1] )
            {
                case 'S': hand[0].push_back(line[i]); break;
                case 'H': hand[1].push_back(line[i]); break;
                case 'D': hand[2].push_back(line[i]); break;
                case 'C': hand[3].push_back(line[i]); break;
            }
        }
        
        int xtra_pts{ 0 };
        int maxi{ 0 };

        for( int i{0}; i < 4; ++i )
        {
        	maxi = max( (int)hand[i].size(), maxi );
            switch( hand[i].size() )
            {
            	case 0: xtra_pts += 2; 
            			break;

                case 1: if( hand[i][0] == 'K' || hand[i][0] == 'Q' || hand[i][0] == 'J' ) 
                            --points;
                        if( hand[i][0] == 'A' ) 
                        	stopped[i] = true;
                        xtra_pts += 2;
                        break;
                
                case 2: for( auto &rank : hand[i] )
                        {
                        	if( rank == 'Q' || rank == 'J' )
                                --points;
                            if( rank == 'A' || rank == 'K' )
                                stopped[i] = true;
                        }
                        xtra_pts += 1;
                        break;
                        
                case 3: for( auto &rank : hand[i] )
                        {
                        	if( rank == 'J' )
                                --points;
                            if( rank == 'A' || rank == 'K' || rank == 'Q' )
                            	stopped[i] = true;
                        }
                        break;
                
                default: for( auto &rank : hand[i] )
                            if( rank == 'A' || rank == 'K' || rank == 'Q' ) 
                                stopped[i] = true;
                        break; 
            }
        }

        bool no_trump{ stopped[0] && stopped[1] && stopped[2]
        						  && stopped[3] && points >= 16 };

        if( no_trump )
       	{
       		cout << "BID NO-TRUMP\n";
       		continue;
       	}
        points += xtra_pts;

        if( points < 14 )
        {
        	cout << "PASS\n";
        	continue;
        }

        for( int i{0}; i < 4; ++i )
        	if( hand[i].size() == maxi )
        	{
        		printf( "BID %c\n", suits[i] );
        		break;
        	}	

    }
	return 0;
}													  
