//UVa - 644 - Immediate Decodability
//String Comparison

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	string record;
	vector<string> records;
	int setNo{0};

	while( cin >> record )
	{
		if( record == "9" )
		{
			bool dec{ true };
			int len{ (int)records.size() };

			for( int i{0}; i < len && dec; ++i )
				for( int j{0}; j < len && dec; ++j )
					if( i != j )
					{
						auto size{ min(records[i].size(),
									   records[j].size()) };
						dec = records[i].compare(0, size, records[j]);
					}

			cout << "Set " << ++setNo << " is ";
			if(!dec) 
				cout << "not ";
			cout << "immediately decodable\n";
			records.clear();
		}
		else
			records.push_back(record);
	}
} 
