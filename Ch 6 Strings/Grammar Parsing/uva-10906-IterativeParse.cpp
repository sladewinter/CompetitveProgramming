//UVa - 10906 - Strange Integration
//Input Parsing

#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>

using namespace std;
using scs = tuple<string, char, string>;

int main()
{
	int T;
	scanf( "%d", &T );
	int caseNo{0};
	while( T-- )
	{
		int N;
		string exp;
		unordered_map<string, scs> str2exp;
		scanf( "%d\n", &N );
		while( N-- )
		{
			char opr, _;
			string var, op1, op2;
			cin >> var >> _ >> op1 >> opr >> op2;
			if( str2exp.find(op1) != str2exp.end() )
			{
				string o1, o2;
				char op;
				tie(o1, op, o2) = str2exp[op1];

				if( op == '+' && opr == '*')
					op1 = '(' + o1 + op + o2 + ')';
				else
					op1 = o1 + op + o2;
			}
			if( str2exp.find(op2) != str2exp.end() )
			{
				string o1, o2;
				char op;
				tie(o1, op, o2) = str2exp[op2];

				if( op == opr || op == '+' && opr == '*' )
					op2 = '(' + o1 + op + o2 + ')';
				else
					op2 = o1 + op + o2;
			}
			str2exp[var] = {op1, opr, op2};
			exp = op1 + opr + op2;
		}
		cout<<"Expression #"<<++caseNo<<": "<<exp<<'\n';
	}
} 
