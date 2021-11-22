

def calculate_nth_tri(n):

	return n*(n + 1)/2;


def calculate_nth_pen(n):

	return n*((3*n) - 1)/2


def calculate_nth_hex(n):

	return n*((2*n) - 1)

def add_entry(h, n):

	if(n not in h):
		h[n]=1
	
	else:
		h[n]+=1
	
	if(h[n] == 3):
		print("Found number: {}".format(n))


n = 1
h = {}

while (True):
	triv = calculate_nth_tri(n)
	penv = calculate_nth_pen(n)
	hexv = calculate_nth_hex(n)

	add_entry(h, triv)
	add_entry(h, penv)
	add_entry(h, hexv)
	n += 1

	if (n > 1000000):
		break