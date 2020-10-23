coinlist = [1, 2, 5, 10, 20, 50, 100, 200]
amount = 200
#DP[x][y] = total number of ways we can produce y pence using the first x coins only
#DP[8][200] = our final answer
row = [0]*(amount+1)
DP = [row]*(len(coinlist) + 1)
#base case:
for i in range(1, len(coinlist)+1):
	DP[i][0] = 1 #total number of ways to make 0 pence is always to do nothing, 1 unique way.

for i in range(1,amount+1):
	DP[0][i] = 0 #total number of ways to make any positive amount of change with 0 coins is 0
print(DP)

#Recurrence relation: Number of ways to make DP[x][y] amount is number of ways to make DP[x-1][y] + DP[x][y-coinlist[x]]
#that is, the number of ways to make that amount of change using 1 less coin,
# + number of ways using that coin, subtracting value of that coin

for i in range(1, len(coinlist) + 1):
	for j in range(amount + 1):
		val = 0
		if j - coinlist[i-1] >= 0:
			val = DP[i-1][j] + DP[i][j-coinlist[i-1]]
		else:
			val = DP[i-1][j]
		DP[i][j] = val
		print(val)

print(DP[len(coinlist)][amount])