#the largest digit is 9
#Objective, find sum of all numbers that are equal to sum of fifth powers of their digits
#9^5 = 59039, 99<59049*2,999<59049*3,9999<59049*4, 99999<59049*5, 999999>59049*6
#Thus, we only need to search the first 999999 numbers
#this is because any larger, and the sum of all fifth powers of digits,
#even if maximal, will never be greater than the number itself

all_valid_numbers = []
for num in range(2,1000000):
	strnum = str(num)
	lnum = [int(digit) for digit in strnum]

	digitsum = 0
	for digit in lnum:
		digitsum += digit**5
	if digitsum == num:
		all_valid_numbers.append(num)

print(sum(all_valid_numbers))