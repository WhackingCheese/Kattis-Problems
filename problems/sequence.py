n = int(input())
nums = [1]
while nums[-1] < n:
    nums.append(nums[-1]*2)
nums.pop()
print(len(nums))
for num in nums:
    print(num, end=' ')
print()
