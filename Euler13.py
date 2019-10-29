f = open("Euler13.txt", "r")
s = 0
for line in f:
	s += int(line)
st = str(s)
print("First 10 digits: {}".format(st[:10]))