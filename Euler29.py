base_upper = 100
exp_upper = 100

s = set()

for base in range(2,base_upper+1):
	for exp in range(2, exp_upper+1):
		result = 1
		for i in range(exp):
			result*=base 
		s.add(result)

print(len(s))