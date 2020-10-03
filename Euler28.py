#use pattern matching / math to solve this, instead of filling out a matrix

#observe that on the diagonal going from top left to bottom right, starting with the center "1",
#one can jump back and forth, increasing by multiples of 2. 1, down to 3, up to 7, down to 13
#this is 1, (1+2), (3 + 4), (7 + 6) ...
#or 1, (prev + 2), (prev + 4), (prev + 6) ...
#the length of the sequence must be odd, because the grid is a square that must have odd dimensions (1001x1001)

#Thus, the right hand diagonal can be computed 1001 times to find the sum of the right hand diagonal.

#The left hand diagonal looks like 1, (1 + 4), (1 + 4 + 4), (1 + 4 + 4 + 8), (1 + 4 + 4 + 8 + 8)...
#every 2 turns, the addition needed to predict the next number increases by 4.
N = 1001
total_sum1 = 0
prevsum1 = 1
#compute top left to bottom right diagonal
for i in range(N):
	total_sum1 += prevsum1 + (i*2)
	prevsum1 = prevsum1 + (i*2)

#print(total_sum1)

#compute bottom left to top right diagonal
total_sum2 = 0
prevsum2 = 1
for i in range(1, 1+N):
	prevsum2 += (int(i/2)*4)
	total_sum2 += prevsum2
	print(total_sum2)

total_sum = total_sum2 + total_sum1 - 1 #because both diagonals intersect at 1
print(total_sum)

	