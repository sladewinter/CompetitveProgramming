//UVa - 10005 - Packing polygons
//Check if possible to fit polygon in circle with radius r

#include <iostream>
#include <cmath>
#include <tuple>

using namespace std;

struct point
{
	double x, y;
};

using tpp = tuple<point, point>;

//Checks if point p in inside circle with centre r
bool inside(point p, point c, double r) 
{
	return hypot(p.x - c.x, p.y - c.y) > r       ? false
	                                             : true;
}

//Returns 2 centres given 2 points and radius
tpp centres( point p1, point p2, double r )
{
	//Square of distance between p1 & p2
	double d2{ (p1.x - p2.x) * (p1.x - p2.x) 
		     + (p1.y - p2.y) * (p1.y - p2.y) }; 

	double det{ r * r / d2 - 0.25 };     //Not possible
	if( det < 0.0 )
		throw -1;
	
	double h{ sqrt(det) };   
	point c1;
	c1.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
	c1.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;

	point c2;
	c2.x = (p2.x + p1.x) * 0.5 + (p2.y - p1.y) * h;
	c2.y = (p2.y + p1.y) * 0.5 + (p1.x - p2.x) * h;

	return {c1, c2};
}

int main()
{
	point v[100];                       //Polygon vertices
	double r;                          //Radius of circle
	int n;                            //No of vertices
	while( scanf( "%d", &n ), n )    
	{
		for( int i{0}; i < n; ++i )
			scanf( "%lf %lf", &v[i].x, &v[i].y );

		scanf( "%lf", &r );

		bool pos{ n == 1 };       //Possible if 1 vertex

		//Try all combination of vertices
		for( int i{0}; i < n - 1 && !pos; ++i )
			for( int j{i + 1}; j < n && !pos; ++j )
			{
				point c1, c2;
				try
				{
					//Returns 2 centres given 2 points and radius
					tie(c1, c2) = centres( v[i], v[j], r );
				}
				catch( int e )          //Error if not possible
				{
					continue;
				}

				//Try with 1 centre
				pos = true;
				for( int k{ 0 }; k < n && pos; ++k )
					if( k != i && k != j )
						pos = inside( v[k], c1, r );

				if(pos) break;         //if succeeds break

				//Else try with the other centre
				pos = true;
				for( int k{ 0 }; k < n && pos; ++k )
					if( k != i && k != j )
						pos = inside( v[k], c2, r );
			}

		pos ? printf("The polygon can be packed in the circle.\n")
			: printf("There is no way of packing that polygon.\n");
	}
	return 0;
} 
