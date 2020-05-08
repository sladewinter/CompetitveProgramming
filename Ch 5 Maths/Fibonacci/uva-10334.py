'''UVa 10334 - Ray Through Glasses
   This problem requires handling BigIntegers, for which unfortunately C++ inherently 
   doesn't have much support as of C++11, instead of learning Java for BigInteger class
   only, I will use Python which can handle arbitrarily large numbers'''

memo = [ 1, 2 ]            #Initialize for Top Down DP base case

def fibonacci( num ):
	if( len( memo ) - 1 >= num ):      #memo[num] already exists 
		return memo[ num ]															
	memo.append( fibonacci( num - 1 ) + fibonacci( num - 2 ) )      #Add it recursively
	return memo[num]                                                


while(1):
	try:                                          #To handle EOF
		print( fibonacci( int( input() ) ) )
	except EOFError:                              #Input has ended
		break
