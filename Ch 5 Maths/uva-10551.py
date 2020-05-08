'''UVa 10551 - Basic Remains
   This problem requires handling BigIntegers, for which unfortunately C++ inherently 
   doesn't have much support as of C++11, instead of learning Java for BigInteger class
   only, I will use Python which can handle arbitrarily large numbers'''

'''Converts a number from base_in to base_out'''
def baseChange( num, base_in, base_out ): 
	if base_in == base_out:                  #Optimization
		return num                                              
	power = 0
	result = 0
	while( num > 0 ):
		result += ( num % base_out ) * pow( base_in, power )
		power += 1
		num //= base_out
	return result

line = input()                               #Input first line

while len( line ) > 1:                       #If input is 0 this breaks
	b, p, m = line.split()                   #Problem parameters
	b, p, m = int(b), int(p), int(m)
	p = baseChange( p, b, 10 )               #Convert p to decimal
	m = baseChange( m, b, 10 )               #Convert m to decimal
	p = p % m                            
	p = baseChange( p, 10, b )               #Convert p back to base b 
	print( p )
	line = input()                           #Input next line
