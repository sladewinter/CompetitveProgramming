//UVa - 11235 - Frequent values
//Segment Tree implementation for Maximum Range Query
//Given sorted array with n elements and q queries [i, j]
//Find element with maximum frequency within [i, j]

#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

class SegmentTree
{
public:
	int n;                      //No of elements
	vi sTree;                  //Segment Tree
	vi arr;                   //Input Array
	vi fArr;                 //Frequency array
	vi sPos;                //Start index of elements
	vi ePos;               //End index of elements

	void processInput( int n )           //Take input
	{
		scanf( "%d", &arr[0] );        //Take input 1st element
		sPos[0] = 0;                  //0 is start index of 1st element
		fArr[0] = 1;                 //Frequency seen till now of element 1

		for(int i{1}; i < n; ++i )      //Forward pass while taking input
		{ 
			scanf( "%d", &arr[i] );
			if( arr[i] == arr[i-1] )    //Same as previous element
			{
				sPos[i] = sPos[i-1];              //So same start positions
				fArr[i] = fArr[i - 1] + 1;       //And count increased
			}
			else
			{
				fArr[i] = 1;                 //New element
				sPos[i] = i;                //Reinitialize start position
			}
		}

		ePos[n-1] = n-1;                      //Optional but convenient
		for(int i{n-2}; i >= 0; --i )        //Back pass fill frequencies
		{
			if( arr[i] == arr[i+1] )        //Same as next element
			{ 
				fArr[i] = fArr[i + 1];     //So same frequency
				ePos[i] = ePos[i + 1];    //And same end positions
			}
			else                         //New element
				ePos[i] = i;            //Reinitialize end position
		}
	}

	//Note: Segment Tree contains original max frequency among elements 
	//in range occuring in input array, NOT among frequencies in the range
	void buildTree(int root, int L, int R)     //Build Segment Tree
	{
		if( L == R )                         //Base condition
			sTree[root] = fArr[L];         
		else
		{
			buildTree( root << 1, L, (L + R) / 2 );             //Recurse
			buildTree( (root << 1) + 1, (L + R) / 2 + 1, R );  //Just like heap
			sTree[root] = max( sTree[root << 1], 
						sTree[(root << 1) + 1] ); //Max among left, right child
		}
	}
	SegmentTree( int N )                                          //Constructor
	{
		n = N;                                  //No of elements in input array
		arr.resize(n);                         //Input Array
		fArr.resize(n);                       //Frequency Array
		sPos.resize(n);                      //Start indices of input elements
		ePos.resize(n);                     //End indices of input elements
		processInput(n);                   //Input and count frequency, sPos, ePos
		sTree.resize(3 * n);              //Tree starts@index 1,so >2n size needed
		buildTree(1, 0, n - 1);          //Build Segment Tree
	}
	int RMQ(int root, int L, int R, int i, int j)            //Range Maximum Query
	{
		if( i > R || j < L || i > j )         //Query & Node's range don't overlap
			return -1;                       //-1 works since we take max()

		if( i <= L && j >= R )               //Node's range inside of query
			return sTree[root];             //Return max frequency in that range

		//If Node's range overlaps with Query but not inside query
		return max( RMQ( root << 1, L, (L+R)/2, i, j ),    //Split Node's range
			RMQ( (root << 1) + 1, (L+R)/2+1, R, i, j ) ); //Take max(left, right)
	}
};

int main()
{
	int n, q, i, j;
	while( scanf("%d", &n), n )
	{
		scanf("%d", &q);
		SegmentTree sTree(n);          //Segment Tree constructor also gets input
		while( q-- )                  //Take queries 1 by 1
		{
			scanf("%d %d", &i, &j);
			--i; --j;                            //Problem indices start@1, our@0
			if( sTree.arr[i] == sTree.arr[j] )  //Both ends of query same element
				printf("%d\n", j - i + 1 );	   //Just print difference in indices
			else
			{
				//Query indices may have split similar elements, so we count
				//separately the similar elements at left and right ends of query
				int left{ sTree.ePos[i] - i + 1 };    //startPos and endPos helps 
				int right{ j - sTree.sPos[j] + 1 };  //endpos[i]=startPos[i]+fArray[i]

				//Chop off left and right chain of same elements, and send the mid part
				//to Segment Tree which has all elements intact as in original array!
				//So just take the max frequency in this mid part and compare left, right
				int mid{ sTree.RMQ(1, 0, n-1,     
					sTree.ePos[i] + 1 , sTree.sPos[j] - 1 ) };
				printf("%d\n", max( mid, max(left, right )));
			}
		}
	}
	return 0;
}