import sys
from math import sqrt

def get_nums(n):
    nums = [i for i in range(n+1) if i%2]
    del nums[0]
    return nums

def sieve_one(nums, k):
    index = 0
    while (nums[index] < sqrt(k)):
        x = nums[index]
        new_nums = nums[:index+1]        
        for i in nums[index+1:]:
            if i % x:
                new_nums.append(i)
        nums = new_nums[:]
        new_nums = []
        index += 1
    return nums

def sieve_two(nums,k):
    sieve_list = [False]*len(nums)
    index = 0


def getmult(ll num):
    return [i for i in ll if i % num ]
    
	           
if __name__ == "__main__":
    num = sys.argv[1]
    nums = get_nums(int(num))
    k=sieve_one(nums[:], int(num))
    print k
    
    
