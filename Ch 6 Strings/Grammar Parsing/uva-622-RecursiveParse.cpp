//UVa - 622 - Grammar Evaluation
//Recursive Parsing

/*
< expression > := < component > | < component > + < expression >
< component > := < factor > | < factor > * < component >
< factor > := < positiveinteger > | (< expression >)
*/

#include <iostream>
#include <cctype>
#include <string>

using namespace std;
string str;
string::iterator ptr;               //cpp style char ptr

int expression();                 //Forward declaration

int positiveinteger()            
{
	int n{ 0 };

	if( isdigit( *ptr ) )
	{
		while( isdigit( *ptr ) )
			n = n * 10 + ( *ptr++ - '0' );
	}
	else
		throw -1;         //Throw error if no integer
 
 	return n;            //Else return valid integer
}

int factor()
{
	if( *ptr == '(' )
	{
		++ptr;
		int exp{ expression() };
		if( *ptr == ')' )            
			++ptr;
		else
			throw -1;        //Throw closing brace error

		return exp;        //Else evaluate and return
	}
	else
		return positiveinteger();   //No '(' then an int
}

int component()                //Exactly according to grammar 
{
	int fact{ factor() };
	if( *ptr == '*' )
	{
		++ptr;
		fact *= component();
	}	
	return fact;
}

int expression()          //Exactly according to grammar 
{
	int comp{ component() };
	if( *ptr == '+' )
	{
		++ptr;
		comp += expression();
	}	
	return comp;
}

int main()
{
	int n;
	scanf( "%d", &n );
	while( n-- )
	{
		cin >> str;          //Input expression
		ptr = str.begin();     

		try                //Catch any errors
		{
			int val{ expression() };     //Evaluate

			if(ptr == str.end())       //Completely parsed
				cout << val << '\n';
			else
				throw -1;            //Not complete
		}
		catch( int e )
		{
			cout << "ERROR\n";  
		}
	}
} 
