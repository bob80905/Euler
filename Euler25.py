fib = [0, 1, 1]
while True:
	fib.append(fib[-1] + fib[-2])
	if len(str(fib[-1])) >= 1000:
		print(len(fib) - 1) #index of last element
		#that was just added and has 1000 digits.
		break