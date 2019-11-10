def fact(n):
	ret = 1
	for i in range(1, n+1):
		ret *= i
	return ret


n = fact(100)
s = str(n)

total = 0
for c in s:
	total += int(c)
print(total)