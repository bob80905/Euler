#find largest index such that the next element is larger
def get_split_index(A):
    i = len(A) - 1
    while i > 0:
        if A[i - 1] >= A[i]:
            i -= 1
        else:
            break
    return i - 1

#find largest index such that is larger than index i
def get_change_index(A, i):
    j = len(A) - 1
    while j >= i:
        if A[j] > A[i]:
            break
        else:
            j -= 1
    return j

#swap elements i and j
def swap(A, i, j):
    A[i], A[j] = (A[j], A[i])

#reverse array A starting at "start"
def reverse(A, start):
    left = start
    right = len(A) - 1
    while left < right:
        swap(A, left, right)
        left += 1
        right -= 1
    return A

#return the next permutation of A
def findNextPerm(A):
    split_index = get_split_index(A)
    # the Array is sorted in descreased order
    if split_index == -1:
        reverse(A, 0)
    else:
        change_index = get_change_index(A, split_index)
        swap(A, split_index, change_index)
        reverse(A, split_index + 1)
    return A

i = 0
temp = [0,1,2,3,4,5,6,7,8,9]
while i < 999999:				#we find the NEXT permutation 999999 times,
	temp = findNextPerm(temp) 
	i += 1						#in order to obtain the millionth permutation.
	#print(temp)
print(temp)