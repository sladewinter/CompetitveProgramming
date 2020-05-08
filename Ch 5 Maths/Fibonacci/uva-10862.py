'''UVa 10862 - Connect the Cable Wires - Generate upto 4000th Fibonacci no.
    
   Using Python3 instead of C++11 to handle abruptly long integers '''

memo = [ 1, 1 ]                   #Initialize for Bottom Up DP base case

'''Max input is 4002 so we prefill upto 4002, Top Down DP will give deep
	recursion error due to stack overflow'''
def fibonacci( num ):
	memo.append( memo[num - 1] + memo[num - 2] )        #Fills memo[num]
	return memo[num]                                                

for i in range( 2, 4002 ):                   #Prefill Table Bottom-up DP
	fibonacci( i )

num = int( input() )                                        #First input

while( num ):
	print( memo[ ( 2 * num ) - 1 ])     #Just print from prefilled table
	num = int( input() )	                                 #Next input