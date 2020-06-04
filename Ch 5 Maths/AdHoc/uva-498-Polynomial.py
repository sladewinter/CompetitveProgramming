#UVa - 498 - Polly the Polynomial
#Polynomial

while(True):
	try:
		coef = input().split()
		val  = input().split()
		n = len(coef)
		st = ''
		for v in val:
			sum = 0
			for i in range(n):
				sum += int(coef[i]) * pow(int(v), n - 1 - i);
			st += str(sum) + ' '
		print(st[:-1])
	except EOFError:
		break