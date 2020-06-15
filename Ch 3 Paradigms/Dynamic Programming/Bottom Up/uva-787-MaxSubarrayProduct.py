#UVa - 787 - Maximum Sub-sequence Product

#We need to keep track of both the maximum and minimum
#contagious products seen till now, since a -ve integer
#can change minimum to maximum, & also global maximum

def MaximumSubarrayProduct():

	#Take input
	arr = [int(i) for i in input().split()]
	while arr[-1] != -999999:
		arr += [int(i) for i in input().split()]

	#Initialize all as question asks non-empty subarray
	minVal = maxVal = maxProd = arr[0]

	#Loop from second element onwards
	for i in arr[1:-1]:

	#If next element is -ve, maxVal and minVal will swap
		if(i < 0):
			minVal, maxVal = maxVal, minVal

	#Either ditch the previous product or not, whichever minimum
		minVal  = min( i, minVal * i )

	#Similarly maxVal will keep track of maximum contagious product
		maxVal  = max( i, maxVal * i )

	#Keeps track of global maximum contagious product
		maxProd = max(maxProd, maxVal)

	return(maxProd)

while True:
	try:
		print(MaximumSubarrayProduct())
	except EOFError:
		break