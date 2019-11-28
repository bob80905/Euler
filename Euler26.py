def isrepeating(substring, string):
	l = len(string)
	sl = len(substring)

	i = 0
	while i + sl < l:
		if string[i:i+sl] != substring:
			return False
		i += sl

	return True

from decimal import *
getcontext().prec = 2002
dec = ["-1"]
for i in range(1,1000):
	s = str(Decimal(Decimal(1)/Decimal(i)))
	s = s[2:]
	dec.append(s)
	print(i, s)

best_yet = (1,"5",2) #stores length of recurring substring and the actual recurring string

#assumption: longest recurring sequence of distinct integers.
for i in range(1,len(dec)): #for every fractional part from 1 - 1000
	end = 1
	# print(dec[i])

	if (len(dec[i]) < 2):
		continue

	while end < len(dec[i]): #keep checking until the end of the string...

		r = dec[i][:end] #store the substring
		if isrepeating(r, dec[i]): #if the cycle immediately follows after the first one, and continues
		#to immediately follow until the end of the string...
			if len(r) > best_yet[0] and (dec[i]).count(r) > 1: 
				#if the substring is a candidate for the largest cycle yet and it recurs more than once
				best_yet = (len(r),r, i)
			print(r)
			break #we're done, any further and we'll be checking duplicate cycles within cycles. (001001...)
		end += 1
print(best_yet)

#There is a proof that further precision will not change the answer, that 1/n
#will at most have a recurring cycle of length n.

