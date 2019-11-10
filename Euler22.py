def get_sum(name):
	ret = 0
	a=ord('A')
	alph=[chr(i) for i in range(a,a+26)]
	for c in name:
		val = alph.index(c)+1
		ret += val
	return ret





all_names = open("Euler22.txt", "r")
all_names = all_names.read()
all_names = all_names.replace("\"","")
all_names = all_names.replace("\n", "")
all_names = all_names.split(",")
all_names.sort()



total = 0
i = 1
for name in all_names:
	name_sum = get_sum(name)
	total+=name_sum*i
	i+=1

print(total)