//UVa - 902 - Password Search
//Frequency Counting

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
  int N;
  string msg;
  while( cin >> N >> msg )
  {
    unordered_map<string, int> count;

    int max_c{ 0 };
    string sub, max_str;

    for( int i{0}; i < msg.size() - N + 1; ++i )
    {
      sub = msg.substr( i, N );
      if( !count[sub] )
        count[sub] = 1;
      else
        ++count[sub];

      if( max_c < count[sub] )
      {
        max_c = count[sub];
        max_str = sub;
      }
    }

    cout << max_str << '\n';
  }
} 