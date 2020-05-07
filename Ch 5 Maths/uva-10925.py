'''UVa 10925 - Krakovia
   This problem requires handling BigIntegers, for which unfortunately C++ inherently 
   doesn't have much support as of C++11, instead of learning Java for BigInteger class
   only, I will use Python which can handle arbitrarily large numbers'''

'''N = No of items, F = No of friends'''
N, F = input().split()

'''Python takes string input by default'''
N, F = int( N ), int( F )

caseNo = 1

'''Stop when both N = 0 and F = 0'''
while N or F:
	sum = 0
	for i in range( N ):                     # Read N items
		V = int(input())
		ans += V

	'''Using comma between strings or int automatically adds a space, to avoid that use +'''
	print( "Bill #" + str( caseNo ), "costs", str(ans) + ": each friend should pay",
		str(int( ans // F )) + "\n" ) 
	'''ans/F means float division and may give rounding errors, use ans//F for int division'''

	caseNo += 1                              # ++caseNo doesnt change caseNo, just returns +1
	N, F = input().split()                   # Take input again and continue
	N, F = int( N ), int( F )
