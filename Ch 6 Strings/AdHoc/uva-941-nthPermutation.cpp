//UVa - 941 - Permutations

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

ll memo[21]{ 1 };
ll fact( int n )
{
	return memo[n] ? memo[n] 
		: memo[n] = n * fact(n - 1);
}

int main()
{
	fact(20);
	int tc{ 0 };
	cin >> tc;
	while( tc-- )
	{
		string S;
		ll N;
		cin >> S >> N;
		int L{ (int)S.size() };
		N %= memo[L];
		sort(S.begin(), S.end());
		while( L-- )
		{
			int pos{ (int)floor(N / memo[L]) };
			cout << S[pos];
			N -= pos * memo[L];
			for( int i{pos}; i < L; ++i )
				S[i] = S[i + 1];
		}
		cout << '\n';
	}
	return 0;
} 
