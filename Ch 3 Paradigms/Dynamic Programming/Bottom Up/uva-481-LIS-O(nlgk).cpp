//UVa - 481 - What Goes Up
//Longest Increasing Subsequence O(nlgk), k=LISlen, n=i/p len
//Bottom up DP(using previous info while filling) + Greedy insertion 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

vi arr;                       //Input Array
vi parent;                   //Parent indx of LIS elements in arr[] 
void backtrack( int id )    //Recurse & print LIS starting @last
{
	if( parent[id] != -1 )
		backtrack( parent[id] );
	printf( "%d\n", arr[id] );
}

int main()
{
	constexpr int INF{ 2147483647 };       //Largest possible int
	int num;
	while( scanf("%d", &num) != EOF )
		arr.push_back(num);

	arr.push_back(INF);         //Ensure LIS always ends with INF
	int n{ (int)arr.size() };  //Length of input 

	parent.assign(n, -1);    //Parent indx of LIS elements in arr[] 
	vi lis(n);              //Array to store LIS
	vi lisId(n);           //Index of LIS elements in arr[]
	int k{ 0 };           //Length of LIS, initially 0
	int pos{ 0 };        //Where in LIS to insert new element?
	int last{ 0 };      //Hold last element of latest LIS in i/p

	for( int id{0}; id < n; ++id )       //Loop elements in O(n)
	{
		//Find position of element in current LIS in O(lgk)
		pos = lower_bound( lis.begin(), lis.begin() + k, arr[id] )
												   - lis.begin();

		lis[pos] = arr[id];         //Greedily overwrite that
		lisId[pos] = id;           //Also store its array index

		(pos == 0) ? parent[id] = -1               //1st element
				   : parent[id] = lisId[pos - 1]; //Parent's index

		if( pos == k )         //Length has increased by 1
		{
			++k;
			last = id;       //Index of last element in latest LIS
		}					
	}

	//Last element is INF so print till last but 1 element of LIS
	printf( "%d\n-\n", k - 1 );
	backtrack(parent[last]);
	return 0;
}

