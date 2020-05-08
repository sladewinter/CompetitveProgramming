'''UVa 10814 - Simplifying Fractions
   This problem requires handling BigIntegers, for which unfortunately C++ inherently 
   doesn't have much support as of C++11, instead of learning Java for BigInteger class
   only, I will use Python which can handle arbitrarily large numbers'''

from math import gcd                         #Always prefer library functions

N = int( input() )                           #No. of test cases

for i in range( N ):
	p, _, q = input().split()                # _ stores the /
	p, q = int(p), int(q)
	GCD = gcd( p, q )
	print( p // GCD, '/', q // GCD )         # // is for integer division