base = 2
power = 1000
result = base**power

s = 0
for digit in str(result):
	s += int(digit)

print(s)