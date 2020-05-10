'''UVa 10497 - Sweet Child Makes Trouble - No of derangements using DP

   Using Python3 instead of C++11 to handle abruptly long integers '''

memo = [ 1, 0 ]                  #Initialize for Top Down DP base case

def derange( num ):
	if( len( memo ) - 1 >= num ):      #memo[num] already exists 
		return memo[ num ]															
	memo.append( ( num - 1 ) * ( derange( num - 1 ) + derange( num - 2 ) ) ) #Add it
	return memo[num]                                                

num = int( input() )
while( num != -1 ):
	print( derange( num ) )
	num = int( input() )
	